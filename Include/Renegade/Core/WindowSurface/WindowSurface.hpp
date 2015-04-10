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

#include <Renegade/Core/WindowSurface/WindowSurface_Enum.hpp>
#include <Renegade/Math/Vector2f/Vector2f.hpp>
#include <string>

// The Renegade namespace
namespace rge {

    // Forward declarations
    class Application_New;

    // The window surface class
    class WindowSurface {
    public:

        // Constructor / Destructor
        WindowSurface            () : application (nullptr)  {};
        WindowSurface            (Application_New* Application);
        virtual ~WindowSurface   () {};

        // Functions
        virtual void Create     (const Vector2f& Size, const std::string& Title, const WindowBorderStyle Style) = 0;
        virtual void Update     () = 0;
        virtual void Release    () = 0;

        // Getters / Setters
        virtual Vector2f const      GetPosition () const = 0;
        virtual void                SetPosition (Vector2f const& Position) = 0;
        virtual Vector2f const      GetSize     () const = 0;
        virtual void                SetSize     (Vector2f const& Size) = 0;
        virtual WindowBorderStyle   GetStyle    () const = 0;
        virtual void                SetStyle    (const WindowBorderStyle& Style) = 0;
        virtual std::string const   GetTitle    () const = 0;
        virtual void                SetTitle    (std::string const& Title) = 0;

        // Variables
        Application_New* const application;

    protected:

        // Functions
        virtual int BorderStyleToNative (WindowBorderStyle Style) = 0;

        // Variables
        std::string _id;
        WindowBorderStyle _windowBorderStyle;
    };
}
