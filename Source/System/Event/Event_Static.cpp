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

#include <Renegade/System/Event/Event.hpp>

// The Renegade namespace
namespace rge {

/*============================================================================================================*/
/*------STATIC VARIABLES--------------------------------------------------------------------------------------*/
/*============================================================================================================*/

    // Private
    std::vector <Event> Event::_eventList;

/*============================================================================================================*/
/*------STATIC FUNCTIONS--------------------------------------------------------------------------------------*/
/*============================================================================================================*/

    // Poll for events
    bool Event::PollEvents (Event& Event) {

        if (Event::_eventList.size () > 0) {

            Event = Event::_eventList [Event::_eventList.size () - 1];
            Event::_eventList.pop_back ();

            return true;
        }

        return false;
    }

/*============================================================================================================*/

    // Push an event
    void Event::PushEvent (Event Event) {

        Event::_eventList.push_back (Event);
    }
}
