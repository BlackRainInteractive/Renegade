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

#define WIN32_LEAN_AND_MEAN

#include <Renegade/Core/WindowSurface/WindowSurface.hpp>
#include <windows.h>

// The Renegade namespace
namespace rge {

    // The detail namespace
    namespace detail {

        // The Win32 window surface class
        class WindowSurface_Win32 : public WindowSurface {
        public:

            // Constructor / Destructor
            WindowSurface_Win32 () : WindowSurface::WindowSurface () {};
            WindowSurface_Win32 (Application_New* Application);

            // Functions
            void Create     (const Vector2f& Size, const std::string& Title, const WindowBorderStyle Style) override;
            void Update     () override;
            void Release    () override;

            // Getters / Setters
            Vector2f const      GetPosition () const override;
            void                SetPosition (Vector2f const& Position) override;
            Vector2f const      GetSize     () const override;
            void                SetSize     (Vector2f const& Size) override;
            WindowBorderStyle   GetStyle    () const override;
            void                SetStyle    (const WindowBorderStyle& Style) override;
            std::string const   GetTitle    () const override;
            void                SetTitle    (std::string const& Title) override;

        protected:

            // Functions
            int BorderStyleToNative (WindowBorderStyle Style) override;

        private:

            // Functions
            LRESULT CALLBACK _WindowCallback (HWND Handle, UINT Message, WPARAM WParam, LPARAM LParam);

            // Functions - Static
            static LRESULT CALLBACK _WndProc (HWND Handle, UINT Message, WPARAM WParam, LPARAM LParam);

            // Variables
            HWND _hwnd;
        };
    }
}
