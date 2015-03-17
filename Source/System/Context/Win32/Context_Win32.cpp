/*============================================================================================================*/
// Copyright (c) 2015, Black Rain Interactive
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// * Redistributions of source code must retain the above copyright notice, this
//   list of conditions and the following disclaimer.
//
// * Redistributions in binary form must reproduce the above copyright notice,
//   this list of conditions and the following disclaimer in the documentation
//   and/or other materials provided with the distribution.
//
// * Neither the name of Renegade nor the names of its
//   contributors may be used to endorse or promote products derived from
//   this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
// DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
// FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
// DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
// SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
// CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
// OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
/*============================================================================================================*/

#if defined _WIN32 | _WIN64

#include <Renegade/System/Context/Win32/Context_Win32.hpp>
#include <Renegade/System/Window/Win32/Window_Win32.hpp>
#include <Renegade/System/Exception/Exception.hpp>
#include <GL/glew.h>
#include <GL/wglew.h>
#include <iostream>

// The Renegade namespace
namespace rge {

/*============================================================================================================*/
/*------PUBLIC FUNCTIONS--------------------------------------------------------------------------------------*/
/*============================================================================================================*/

    // Create the context (from rge window)
    void Context::Create (Window* Window, const ContextSettings& Settings) {

        this -> Create (Window -> hwnd, GetDC (Window -> hwnd), Settings);
    }

/*============================================================================================================*/

    // Create the context (using existing HWND and HDC)
    void Context::Create (HWND Handle, HDC DeviceContext, const ContextSettings& Settings) {

        // Set variables
        this -> _deviceContext  = DeviceContext;
        this -> _windowHandle   = Handle;

        this -> accumBits	    = Settings.accumBits;
        this -> alphaBits	    = Settings.alphaBits;
        this -> colourBits	    = Settings.colourBits;
        this -> depthBits	    = Settings.depthBits;
        this -> stencilBits	    = Settings.stencilBits;
        this -> versionMajor	= Settings.versionMajor;
        this -> versionMinor	= Settings.versionMinor;

        // Create the pixel format descriptor
        PIXELFORMATDESCRIPTOR pfd;
        pfd.cAccumBits      = (BYTE) this -> accumBits;
        pfd.cAlphaBits      = (BYTE) this -> alphaBits;
        pfd.cColorBits      = (BYTE) this -> colourBits;
        pfd.cDepthBits      = (BYTE) this -> depthBits;
        pfd.cStencilBits    = (BYTE) this -> stencilBits;
        pfd.dwFlags         = PFD_DOUBLEBUFFER | PFD_SUPPORT_OPENGL | PFD_DRAW_TO_WINDOW | PFD_SUPPORT_COMPOSITION;
        pfd.iPixelType      = PFD_TYPE_RGBA;
        pfd.nSize           = sizeof (PIXELFORMATDESCRIPTOR);

        // Select the pixel format
        int pixFormat = ChoosePixelFormat (DeviceContext, &pfd);

        if (pixFormat == 0)
            throw (Exception (__LINE__, __FILE__, "PFD is invalid."));

        // Set the pixel format
        if (!SetPixelFormat (DeviceContext, pixFormat, &pfd))
            throw (Exception (__LINE__, __FILE__, "Pixel format could not be set."));

        // Create a temp OpenGL 2.1 context
        HGLRC temp = wglCreateContext (DeviceContext);
        wglMakeCurrent (DeviceContext, temp);

        // Start glew and check for errors
        glewExperimental    = GL_TRUE;
        GLenum err          = glewInit ();

        if (err != GLEW_OK)
            throw (Exception (__LINE__, __FILE__, (const char *) glewGetErrorString (err)));

        // Set the context attributes
        const int attributes [] = {

            WGL_CONTEXT_MAJOR_VERSION_ARB, this -> versionMajor,
            WGL_CONTEXT_MINOR_VERSION_ARB, this -> versionMinor,
            WGL_CONTEXT_FLAGS_ARB, WGL_CONTEXT_CORE_PROFILE_BIT_ARB,
            0
        };

        // Check if OpenGL 3.x is supported
        if (wglewIsSupported ("WGL_ARB_create_context") == GL_TRUE) {

            // Remove temp context
            wglMakeCurrent      (nullptr, nullptr);
            wglDeleteContext    (temp);

            // Create new context
            this -> _glContext = wglCreateContextAttribsARB (this -> _deviceContext, nullptr, attributes);
        }

        // OpenGL 3.x not supported, throw error
        else {

            std::cerr << "WARNING: OpenGL 3.x is not supported by your graphics card.\n"
                      << "Things may not work as expected, if at all.\n";

            this -> _glContext = temp;
        }

        // Make current and set clear colour
        this -> SetCurrent ();
        this -> clearColour = Settings.clearColour;
    }

/*============================================================================================================*/

    // Update the context
    void Context::Update () {

        if (this -> isActive) {

            SwapBuffers (this -> _deviceContext);
            glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

            if (wglGetCurrentContext () != this -> _glContext)
                this -> isActive = false;
        }
    }

/*============================================================================================================*/

    // Set context as current
    void Context::SetCurrent () {

        this -> isActive = true;
        wglMakeCurrent (this -> _deviceContext, this -> _glContext);
    }

/*============================================================================================================*/

    // Get the native context handle
    HGLRC Context::GetHGLRC () {

        return (this -> _glContext);
    }

/*============================================================================================================*/

    // Release the context
    void Context::Release () {

        this -> isActive = false;

        wglMakeCurrent		(nullptr, nullptr);
        wglDeleteContext	(this -> _glContext);
        ReleaseDC			(this -> _windowHandle, this -> _deviceContext);
    }

/*============================================================================================================*/
/*------PRIVATE FUNCTIONS-------------------------------------------------------------------------------------*/
/*============================================================================================================*/

    // Get the context clear colour
    Vector4f Context::_GetClearColour () {

        return (this -> _clearColour);
    }

/*============================================================================================================*/

    // Set the context clear colour
    void Context::_SetClearColour (Vector4f Colour) {

        if (this -> isActive) {

            this -> _clearColour = Colour;
            glClearColor (Colour.x, Colour.y, Colour.z, Colour.w);
        }
    }
}

#endif // _WIN32 | _WIN64
