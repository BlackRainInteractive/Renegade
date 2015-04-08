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

#include <Renegade/System/Application/Application_Enum.hpp>
#include <vector>

// The Renegade namespace
namespace rge {

    // Forward declare classes
    class Context;
    class Window;

    // The application class
    class Application {
    public:

        // Constructor
        Application ();

        // Functions
        void RegisterContext    (Context* Context);
        void RegisterWindow     (Window* Window);
        void Exit               ();

        // Getters / Setter
        bool        IsRunning ();
        Context*    GetCurrentContext   () const;
        Window*     GetCurrentWindow    () const;

        // Variables - Static
        #ifdef _WIN32
            static const Platform platform = Platform::Windows;
        #elif defined __gnu_linux__
            static const Platform platform = Platform::Linux;
        #elif defined __APPLE__
            static const Platform platform = Platform::Apple_OSX;
        #else
            static const Platform platform = Platform::Unknown;
        #endif

    private:

        // Variables
        bool _isRunning;
        std::vector <Context*> _contextList;
        std::vector <Window*>  _windowList;
    };
}
