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

#include <Renegade/Core/Application/Application.hpp>
#include <Renegade/Core/EventManager/EventManager.hpp>

#ifdef _WIN32
    #include <Renegade/Core/WindowSurface/Detail/WindowSurface_Win32.hpp>
#endif

// The Renegade namespace
namespace rge {

/*============================================================================================================*/
/*------PUBLIC FUNCTIONS--------------------------------------------------------------------------------------*/
/*============================================================================================================*/

    // Initialize the application
    void Application_New::Initialize () {

        // Initialize systems
        this -> _eventManager = std::make_unique <EventManager> ();

        #ifdef _WIN32
            this -> _nativeWindow = std::make_unique <detail::WindowSurface_Win32> (this);
        #endif

        this -> _nativeWindow -> Create (Vector2f (800, 600), "Test", WBS_Default);

        // Push init event
        Event event;
        event.eventType = ET_AppInit;

        this -> _eventManager -> PushEvent (event);
    }

/*============================================================================================================*/

    // Update and poll for events
    bool Application_New::Update () {

        // Update all systems
        this -> _nativeWindow -> Update ();

        return true;
    }

/*============================================================================================================*/

    // Shutdown the application
    void Application_New::Shutdown () {

        // Push shutdown event
        Event event;
        event.eventType = ET_AppShutdown;

        this -> _eventManager -> PushEvent (event);

        // Release all systems
        this -> _nativeWindow -> Release ();
    }

/*============================================================================================================*/
/*------GETTERS / SETTERS-------------------------------------------------------------------------------------*/
/*============================================================================================================*/

    // Get the event manager
    EventManager* Application_New::GetEventManager () {

        return (this -> _eventManager ? this -> _eventManager.get () : nullptr);
    }

/*============================================================================================================*/

    // Get the window surface
    WindowSurface* Application_New::GetWindowSurface () {

        return (this -> _nativeWindow ? this -> _nativeWindow.get () : nullptr);
    }
}
