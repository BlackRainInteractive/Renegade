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

#if defined _WIN32 | _WIN64

#include <Renegade/System/Utility/Property/Property.hpp>
#include <Renegade/System/Window/Win32/Window_Win32_Enum.hpp>
#include <Renegade/Math/Vector2f/Vector2f.hpp>
#include <string>

// The Renegade namespace
namespace rge {

    // Forward declare classes
    class Context;
    class Window;

    // The window settings struct
    struct WindowSettings {

        WindowSettings () : size (Vector2f (1280, 720)),
                            title ("Renegade_Window"),
                            style (WindowStyle::Default) {};

        Vector2f size;
        std::string title;
        WindowStyle style;
    };

/*============================================================================================================*/

    // The window class
    class Window {
    public:

        // Constructor / Destructor
        Window ();

        // Functions
        void Create             (const WindowSettings& Settings);
        void Update             ();
        void Release            ();

        // Properties
        Property <Window, HWND>         hwnd;
        Property <Window, Vector2f>     position;
        Property <Window, Vector2f>     size;
        Property <Window, WindowStyle>  style;
        Property <Window, std::string>  title;
        Property <Window, bool>         isVisible;

        // Variables
        bool isOpen, isActive;

    private:

        // Functions
        LRESULT CALLBACK _WindowCallback (HWND Handle, UINT Message, WPARAM WParam, LPARAM LParam);
        HWND _GetHWND            ();
        Vector2f _GetPosition    ();
        void _SetPosition        (Vector2f Position);
        Vector2f _GetSize        ();
        void _SetSize            (Vector2f Size);
        WindowStyle _GetStyle    ();
        void _SetStyle           (WindowStyle Style);
        std::string _GetTitle    ();
        void _SetTitle           (std::string Title);
        void _SetVisible         (bool Visible);

        // Functions - Static
        static LRESULT CALLBACK _WndProc (HWND Handle, UINT Message, WPARAM WParam, LPARAM LParam);

        // Variables
        HWND _handle;
        std::string _id;
        WindowStyle _style;
    };
}

#endif // _WIN32 | _WIN64
