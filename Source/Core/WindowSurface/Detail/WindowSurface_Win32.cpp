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

#include <Renegade/Core/WindowSurface/Detail/WindowSurface_Win32.hpp>
#include <Renegade/System/Exception/Exception.hpp>
#include <Renegade/System/Utility/Win32/Utility_Win32.hpp>

// The Renegade namespace
namespace rge {

    // The detail namespace
    namespace detail {

/*============================================================================================================*/
/*------CONSTRUCTOR-------------------------------------------------------------------------------------------*/
/*============================================================================================================*/

        // Construct with application specified
        WindowSurface_Win32::WindowSurface_Win32 (Application_New* Application) : WindowSurface::WindowSurface (Application) {

        }

/*============================================================================================================*/
/*------PUBLIC FUNCTIONS--------------------------------------------------------------------------------------*/
/*============================================================================================================*/

        // Create the window
        void WindowSurface_Win32::Create (const Vector2f& Size, const std::string& Title, const WindowBorderStyle Style) {

            // Set variables
            this -> _id = Utility::GenGUID ();

            // Get the application instance
            HINSTANCE appInstance = GetModuleHandle (0);

            // Set up the window class with default settings
            WNDCLASSEX windowClass = {sizeof (WNDCLASSEX),
                                      CS_HREDRAW | CS_VREDRAW | CS_OWNDC,
                                      &_WndProc,
                                      0,
                                      0,
                                      appInstance,
                                      LoadIcon (nullptr, IDI_WINLOGO),
                                      LoadCursor (nullptr, IDC_ARROW),
                                      (HBRUSH) GetStockObject (WHITE_BRUSH),
                                      0,
                                      (LPCSTR) this -> _id.c_str (),
                                      LoadIcon (nullptr, IDI_WINLOGO)};

            // Register the window class
            if (!RegisterClassEx (&windowClass))
                throw (Exception (__LINE__, __FILE__, "Win32 window could not be registered."));

            // Create the window
            this -> _hwnd = CreateWindowEx (WS_EX_APPWINDOW, (LPCSTR) this -> _id.c_str (), (LPCSTR) Title.c_str (),
                                            (DWORD) this -> BorderStyleToNative (WBS_Default), 0, 0, 640, 480,
                                            nullptr, nullptr, appInstance, this);

            // Check for errors
            if (!this -> _hwnd)
                throw (Exception (__LINE__, __FILE__, "Win32 window creation failed."));

            Vector2f winPos;

            // Set default position
            if (Style != WBS_Fullscreen) {

                winPos.x = (GetSystemMetrics (SM_CXSCREEN) - Size.x) / 2;
                winPos.y = (GetSystemMetrics (SM_CYSCREEN) - Size.y) / 2;
            }

            else {

                winPos.x = 0;
                winPos.y = 0;
            }

            // Set the style, size, and position
            this -> SetStyle    (Style);
            this -> SetSize     (Size);
            this -> SetPosition (winPos);
        }

/*============================================================================================================*/

        void WindowSurface_Win32::Update () {

            MSG msg;

            // Handle the window messages
            if (PeekMessage (&msg, this -> _hwnd, 0, 0, PM_REMOVE)) {

                TranslateMessage (&msg);
                DispatchMessage (&msg);
            }
        }

/*============================================================================================================*/

        void WindowSurface_Win32::Release () {

            // Destroy the window and unregister class
            DestroyWindow	(this -> _hwnd);
            UnregisterClass ((LPCSTR) this -> _id.c_str (), GetModuleHandle (0));
        }

/*============================================================================================================*/
/*------GETTERS / SETTERS-------------------------------------------------------------------------------------*/
/*============================================================================================================*/

        Vector2f const WindowSurface_Win32::GetPosition () const {

            RECT rect;
            GetWindowRect (this -> _hwnd, &rect);

            return (Vector2f ((float) rect.left, (float) rect.top));
        }

/*============================================================================================================*/

        void WindowSurface_Win32::SetPosition (Vector2f const& Position) {

            SetWindowPos (this -> _hwnd, nullptr, (int) Position.x, (int) Position.y,
                          0, 0, SWP_NOSIZE | SWP_NOZORDER | SWP_NOACTIVATE);
        }

/*============================================================================================================*/

        Vector2f const WindowSurface_Win32::GetSize () const {

            RECT rect;
            GetClientRect (this -> _hwnd, &rect);

            return (Vector2f ((float) (rect.right - rect.left), (float) (rect.bottom - rect.top)));
        }

/*============================================================================================================*/

        void WindowSurface_Win32::SetSize (Vector2f const& Size) {

            // Correct the window rect
            RECT wr = {0, 0, (LONG) Size.x, (LONG) Size.y};
            AdjustWindowRect (&wr, (DWORD) this -> _windowBorderStyle, FALSE);

            // Check if fullscreen
            if (this -> _windowBorderStyle == WBS_Fullscreen) {

                // Create display settings
                DEVMODE screenSettings;
                screenSettings.dmSize       = sizeof (DEVMODE);
                screenSettings.dmBitsPerPel = 32;
                screenSettings.dmPelsWidth  = (DWORD) Size.x;
                screenSettings.dmPelsHeight = (DWORD) Size.y;
                screenSettings.dmFields     = DM_BITSPERPEL | DM_PELSWIDTH | DM_PELSHEIGHT;

                // Set display as fullscreen
                ChangeDisplaySettings (&screenSettings, CDS_FULLSCREEN);
            }

            SetWindowPos (this -> _hwnd, nullptr, 0, 0, (int) (wr.right - wr.left), (int) (wr.bottom - wr.top), SWP_NOMOVE | SWP_NOZORDER | SWP_NOACTIVATE);
        }

/*============================================================================================================*/

        WindowBorderStyle WindowSurface_Win32::GetStyle () const {

            return (this -> _windowBorderStyle);
        }

/*============================================================================================================*/

        void WindowSurface_Win32::SetStyle (const WindowBorderStyle& Style) {

            // Set variables
            this -> _windowBorderStyle  = Style;
            Vector2f winSize            = this -> GetSize ();

            // Do if fullscreen
            if (Style == WBS_Fullscreen) {

                // Create display settings
                DEVMODE screenSettings;
                screenSettings.dmSize       = sizeof (DEVMODE);
                screenSettings.dmBitsPerPel = 32;
                screenSettings.dmPelsWidth  = (DWORD) winSize.x;
                screenSettings.dmPelsHeight = (DWORD) winSize.y;
                screenSettings.dmFields     = DM_BITSPERPEL | DM_PELSWIDTH | DM_PELSHEIGHT;

                // Set display as fullscreen
                ChangeDisplaySettings (&screenSettings, CDS_FULLSCREEN);
            }

            // Do if windowed
            else
                ChangeDisplaySettings (nullptr, 0);

            // Set the window style
            SetWindowLongPtr (this -> _hwnd, GWL_STYLE, (LONG_PTR) this -> BorderStyleToNative (Style));

            // Set the window as the main focus
            ShowWindow			(this -> _hwnd, SW_SHOW);
            SetForegroundWindow (this -> _hwnd);
            SetFocus			(this -> _hwnd);
        }

/*============================================================================================================*/

        std::string const WindowSurface_Win32::GetTitle () const {

            TCHAR rawString [128];
            GetWindowText (this -> _hwnd, rawString, 128);

            return (std::string (rawString));
        }

/*============================================================================================================*/

        void WindowSurface_Win32::SetTitle (std::string const& Title) {

            SetWindowText (this -> _hwnd, (LPCSTR) Title.c_str ());
        }

/*============================================================================================================*/
/*------PROTECTED FUNCTIONS-----------------------------------------------------------------------------------*/
/*============================================================================================================*/

        int WindowSurface_Win32::BorderStyleToNative (WindowBorderStyle Style) {

            switch (Style) {

                case WBS_Borderless:
                    return (WS_VISIBLE);

                case WBS_Default:
                    return (WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX | WS_VISIBLE);

                case WBS_Default_Resizeable:
                    return (WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_THICKFRAME | WS_MINIMIZEBOX | WS_MAXIMIZEBOX | WS_VISIBLE);

                case WBS_Fullscreen:
                    return (WS_CLIPCHILDREN | WS_CLIPSIBLINGS | WS_VISIBLE);

                default:
                    return (WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX | WS_VISIBLE);
            }
        }

/*============================================================================================================*/
/*------PRIVATE FUNCTIONS-------------------------------------------------------------------------------------*/
/*============================================================================================================*/

        LRESULT WindowSurface_Win32::_WindowCallback (HWND Handle, UINT Message, WPARAM WParam, LPARAM LParam) {

            //Event ev;

            switch (Message) {

                // Window creation
                case WM_CREATE:

                    //ev.type = EventType::Create;
                    break;

                    // Window resize
                case WM_SIZE:

                    //ev.type = EventType::Resize;
                    //ev.size = Vector2f ((float) LOWORD (LParam), (float) HIWORD (LParam));
                    break;

                    // Window move
                case WM_MOVE:

                    //ev.type     = EventType::Move;
                    //ev.position = Vector2f ((float) LOWORD (LParam), (float) HIWORD (LParam));
                    break;

                    // Window focus
                case WM_SETFOCUS:

                    //this -> isActive = true;
                    //ev.type = EventType::GainedFocus;

                    break;

                    // Window lost focus
                case WM_KILLFOCUS:

                    //this -> isActive = false;
                    //.type = EventType::LostFocus;

                    break;

                    // Window close
                case WM_CLOSE:

                    //ev.type = EventType::Close;
                    //this -> isOpen = false;
                    break;

                    // Key Up
                case WM_KEYUP:
                case WM_SYSKEYUP:

                    //ev.type     = EventType::KeyUp;
                    //ev.keyCode  = Input::MapVirtualKeyToRGE (WParam, LParam);

                    break;

                    // Key down
                case WM_KEYDOWN:
                case WM_SYSKEYDOWN:

                    //ev.type     = EventType::KeyDown;
                    //ev.keyCode  = Input::MapVirtualKeyToRGE (WParam, LParam);

                    break;

                    // Default
                default:
                    return (DefWindowProc (Handle, Message, WParam, LParam));
            }

            //Event::PushEvent (ev);
            return (DefWindowProc (Handle, Message, WParam, LParam));
        }

/*============================================================================================================*/
/*------PRIVATE STATIC FUNCTIONS------------------------------------------------------------------------------*/
/*============================================================================================================*/

        LRESULT WindowSurface_Win32::_WndProc (HWND Handle, UINT Message, WPARAM WParam, LPARAM LParam) {

            // Check if window was created
            if (Message == WM_CREATE)
                SetWindowLongPtr (Handle, GWLP_USERDATA, (LONG_PTR) (LPCREATESTRUCT (LParam) -> lpCreateParams));

            // Get the pointer to the current window
            WindowSurface_Win32* win = (WindowSurface_Win32*) GetWindowLongPtr (Handle, GWLP_USERDATA);

            if (win)
                return (win -> _WindowCallback (Handle, Message, WParam, LParam));

            else
                return (DefWindowProc (Handle, Message, WParam, LParam));
        }
    }
}
