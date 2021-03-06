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

#pragma once

#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN

#include <Renegade/Math/Colour/Colour.hpp>
#include <windows.h>
#include <vector>

// The Renegade namespace
namespace rge {

    // Forward declare classes
    class Window;

    // The context settings struct
    struct ContextSettings {

        // Constructor
        ContextSettings () : accumBits	    (32),
                             alphaBits	    (32),
                             colourBits	    (32),
                             depthBits	    (24),
                             stencilBits    (24),
                             versionMajor	(3),
                             versionMinor	(1),
                             clearColour	(Colour::darkGray) {};

        // Variables
        int	accumBits;
        int	alphaBits;
        int	colourBits;
        int	depthBits;
        int	stencilBits;
        int	versionMajor;
        int	versionMinor;
        Colour clearColour;
    };

/*============================================================================================================*/

    // The context class
    class Context {
    public:

        // Constructor
        Context () {};
        Context (Window* Window, const ContextSettings& Settings);

        // Functions
        void Create             (Window* Window, const ContextSettings& Settings);
        void Create				(HWND Handle, HDC DeviceContext, const ContextSettings& Settings);
        void Update				();
        void Release			();

        // Getters / Setters
        HGLRC           GetHandle       () const;
        bool            IsCurrent       () const;
        void            SetCurrent      (bool const Current);
        Colour const    GetClearColour  () const;
        void            SetClearColour  (Colour const& ClearColour);

        // Variables
        //bool isActive;
        int	accumBits;
        int	alphaBits;
        int	colourBits;
        int	depthBits;
        int	stencilBits;
        int	versionMajor;
        int	versionMinor;

    private:

        // Variables
        HDC		    _deviceContext;
        HGLRC	    _glContext;
        HWND	    _windowHandle;
        Colour      _clearColour;
    };
}

#endif // _WIN32
