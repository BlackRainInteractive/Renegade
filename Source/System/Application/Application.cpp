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

#include <Renegade/System/Application/Application.hpp>
#include <Renegade/System/Window/Window.hpp>
#include <Renegade/System/Context/Win32/Context_Win32.hpp>
#include <algorithm>

// The Renegade namespace
namespace rge {

/*============================================================================================================*/
/*------STATIC VARIABLES--------------------------------------------------------------------------------------*/
/*============================================================================================================*/

    // Public
    #if defined _WIN32 | _WIN64
        Platform Application::platform = Platform::Windows;
    #elif defined __gnu_linux__
        Platform Application::platform = Platform::Linux;
    #elif defined __APPLE__
        Platform Application::platform = Platform::Apple_OSX;
    #else
        Platform Application::platform = Platform::Unknown;
    #endif

/*============================================================================================================*/
/*------CONSTRUCTOR-------------------------------------------------------------------------------------------*/
/*============================================================================================================*/

    // The default constructor
    Application::Application () : _isRunning (true) {

    }

/*============================================================================================================*/
/*------PUBLIC FUNCTIONS--------------------------------------------------------------------------------------*/
/*============================================================================================================*/

    // Check if is running
    bool Application::IsRunning () {

        // Check if running
        if (this -> _isRunning) {

            // Update all contexts
            for (auto i : this -> _contextList) {

                if (i -> isActive)
                    i -> Update ();
            }

            // Update all windows
            for (auto i : this -> _windowList) {

                // Update window if open
                if (i -> isOpen)
                    i -> Update ();

                    // Else remove the window from the list
                else
                    this -> _windowList.erase (std::remove (this -> _windowList.begin (),
                                                            this -> _windowList.end (), i));
            }
        }

        return (this -> _isRunning);
    }

/*============================================================================================================*/

    // Get the current context
    Context* Application::GetCurrentContext () {

        for (auto item : this -> _contextList) {

            if (item -> isActive)
                return (item);
        }

        return (nullptr);
    }

/*============================================================================================================*/

    // Get the current window
    Window* Application::GetCurrentWindow () {

        for (auto item : this -> _windowList) {

            if (item -> isActive)
                return (item);
        }

        return (nullptr);
    }

/*============================================================================================================*/

    // Register a context
    void Application::RegisterContext (Context* Context) {

        this -> _contextList.push_back (Context);
    }

/*============================================================================================================*/

    // Register a window
    void Application::RegisterWindow (Window* Window) {

        this -> _windowList.push_back (Window);
    }

/*============================================================================================================*/

    // Exit the application
    void Application::Exit () {

        // Release all contexts
        for (auto i : this -> _contextList)
            i -> Release ();

        // Release all windows
        for (auto i : this -> _windowList)
            i -> Release ();

        this -> _isRunning = false;
    }
}
