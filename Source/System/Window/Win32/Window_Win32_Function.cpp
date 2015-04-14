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


#ifdef _WIN32
#include <Renegade/System/Window/Win32/Window_Win32.hpp>
#include <Renegade/System/Context/Win32/Context_Win32.hpp>
#include <Renegade/System/Event/Event.hpp>
#include <Renegade/System/Exception/Exception.hpp>
#include <Renegade/System/Input/Win32/Input_Win32.hpp>
#include <Renegade/System/Utility/Win32/Utility_Win32.hpp>
#include <dwmapi.h>

// The Renegade namespace
namespace rge {

/*============================================================================================================*/
/*------CONSTRUCTOR-------------------------------------------------------------------------------------------*/
/*============================================================================================================*/

    // The default constructor
    Window::Window () : _id (Utility::GenGUID ()) {
    }

/*============================================================================================================*/

    // Construct from window settings
    Window::Window (const WindowSettings& Settings) : Window () {

        this -> Create (Settings);
    }

/*============================================================================================================*/
/*------PUBLIC FUNCTIONS--------------------------------------------------------------------------------------*/
/*============================================================================================================*/

    // Create the window
    void Window::Create (const WindowSettings& Settings) {

        // Set variables
        this -> isOpen      = true;
        this -> isActive    = true;

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

        // Create the final window
        this -> _handle = CreateWindowEx (WS_EX_APPWINDOW, (LPCSTR) this -> _id.c_str (), (LPCSTR) Settings.title.c_str (),
                                         (DWORD) WindowStyle::Default, 0, 0, 640, 480, nullptr, nullptr,
                                          appInstance, this);

        // Check for errors
        if (!this -> _handle)
            throw (Exception (__LINE__, __FILE__, "Win32 window creation failed."));

        Vector2f winPos;

        // Set defualt position
        if (Settings.style != WindowStyle::Fullscreen) {

            winPos.x = (GetSystemMetrics (SM_CXSCREEN) - Settings.size.x) / 2;
            winPos.y = (GetSystemMetrics (SM_CYSCREEN) - Settings.size.y) / 2;
        }

        else {

            winPos.x = 0;
            winPos.y = 0;
        }

        // Set the style, size, and position
        this -> SetStyle    (Settings.style);
        this -> SetSize     (Settings.size);
        this -> SetPosition (winPos);
    }

/*============================================================================================================*/

    // Update the window
    void Window::Update () {

        MSG msg;

        // Handle the window messages
        if (PeekMessage (&msg, this -> _handle, 0, 0, PM_REMOVE)) {

            TranslateMessage (&msg);
            DispatchMessage (&msg);
        }
    }

/*============================================================================================================*/

    // Enable or disable transparency
    void Window::EnableTransparency (bool Transparency) {

        DWM_BLURBEHIND bb;

        if (Transparency) {

            bb = {DWM_BB_ENABLE | DWM_BB_BLURREGION,
                  TRUE,
                  CreateRectRgn (0, 0, -1, -1),
                  TRUE};

            DwmEnableBlurBehindWindow (this -> _handle, &bb);
        }

        else {

            bb = {DWM_BB_ENABLE,
                  FALSE,
                  CreateRectRgn (0, 0, -1, -1),
                  TRUE};

            DwmEnableBlurBehindWindow (this -> _handle, &bb);
        }
    }

/*============================================================================================================*/

    // Release the window
    void Window::Release () {

        // Set variables
        this -> isOpen   = false;
        this -> isActive = false;

        // Destroy the window and unregister class
        DestroyWindow	(this -> _handle);
        UnregisterClass ((LPCSTR) this -> _id.c_str (), GetModuleHandle (0));
    }

/*============================================================================================================*/
/*------GETTERS / SETTERS-------------------------------------------------------------------------------------*/
/*============================================================================================================*/

    // Get native window handle
    HWND Window::GetHandle () const {

        return (this -> _handle);
    }

/*============================================================================================================*/

    // Get the window position
    Vector2f const Window::GetPosition () const {

        RECT rect;
        GetWindowRect (this -> _handle, &rect);

        return (Vector2f ((float) rect.left, (float) rect.top));
    }

/*============================================================================================================*/

    // Set the window position
    void Window::SetPosition (Vector2f const& Position) {

        SetWindowPos (this -> _handle, nullptr, (int) Position.x, (int) Position.y,
                      0, 0, SWP_NOSIZE | SWP_NOZORDER | SWP_NOACTIVATE);
    }

/*============================================================================================================*/

    // Get the window size
    Vector2f const Window::GetSize () const {

        RECT rect;
        GetClientRect (this -> _handle, &rect);

        return (Vector2f ((float) (rect.right - rect.left), (float) (rect.bottom - rect.top)));
    }

/*============================================================================================================*/

    // Set window size
    void Window::SetSize (Vector2f const& Size) {

        // Correct the window rect
        RECT wr = {0, 0, (LONG) Size.x, (LONG) Size.y};
        AdjustWindowRect (&wr, (DWORD) this -> _style, FALSE);

        // Check if fullscreen
        if (this -> _style == WindowStyle::Fullscreen) {

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

        SetWindowPos (this -> _handle, nullptr, 0, 0, (int) (wr.right - wr.left), (int) (wr.bottom - wr.top), SWP_NOMOVE | SWP_NOZORDER | SWP_NOACTIVATE);
    }

/*============================================================================================================*/

    // Get the window style
    WindowStyle Window::GetStyle () const {

        return (this -> _style);
    }

/*============================================================================================================*/

    // Set window style
    void Window::SetStyle (WindowStyle const& Style) {

        // Set variables
        this -> _style      = Style;
        Vector2f winSize    = this -> GetSize ();

        // Do if fullscreen
        if (Style == WindowStyle::Fullscreen) {

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
        SetWindowLongPtr (this -> _handle, GWL_STYLE, (LONG_PTR) _style);

        // Set the window as the main focus
        ShowWindow			(this -> _handle, SW_SHOW);
        SetForegroundWindow (this -> _handle);
        SetFocus			(this -> _handle);
    }

/*============================================================================================================*/

    // Get the window title
    std::string const Window::GetTitle () const {

        TCHAR rawString [128];
        GetWindowText (this -> _handle, rawString, 128);

        return (std::string (rawString));
    }

/*============================================================================================================*/

    // Set window title
    void Window::SetTitle (std::string const& Title) {

        SetWindowText (this -> _handle, (LPCSTR) Title.c_str ());
    }

/*============================================================================================================*/

    // Toggle the window visibility
    void Window::SetVisible (bool Visible) {

        ShowWindow (this -> _handle, Visible ? SW_SHOW : SW_HIDE);
    }

/*============================================================================================================*/
/*------PRIVATE FUNCTIONS-------------------------------------------------------------------------------------*/
/*============================================================================================================*/

    // Process window callbacks
    LRESULT Window::_WindowCallback (HWND Handle, UINT Message, WPARAM WParam, LPARAM LParam) {

        Event ev;

        switch (Message) {

            // Window creation
            case WM_CREATE:

                ev.type = EventType::Create;
                break;

            // Window resize
            case WM_SIZE:

                ev.type = EventType::Resize;
                ev.size = Vector2f ((float) LOWORD (LParam), (float) HIWORD (LParam));
                break;

            // Window move
            case WM_MOVE:

                ev.type     = EventType::Move;
                ev.position = Vector2f ((float) LOWORD (LParam), (float) HIWORD (LParam));
                break;

            // Window focus
            case WM_SETFOCUS:

                this -> isActive = true;
                ev.type = EventType::GainedFocus;

                break;

            // Window lost focus
            case WM_KILLFOCUS:

                this -> isActive = false;
                ev.type = EventType::LostFocus;

                break;

            // Window close
            case WM_CLOSE:

                ev.type = EventType::Close;
                this -> isOpen = false;
                break;

            // Key Up
            case WM_KEYUP:
            case WM_SYSKEYUP:

                ev.type     = EventType::KeyUp;
                ev.keyCode  = Input::MapVirtualKeyToRGE (WParam, LParam);

                break;

            // Key down
            case WM_KEYDOWN:
            case WM_SYSKEYDOWN:

                ev.type     = EventType::KeyDown;
                ev.keyCode  = Input::MapVirtualKeyToRGE (WParam, LParam);

                break;

            // Default
            default:
                return (DefWindowProc (Handle, Message, WParam, LParam));
        }

        Event::PushEvent (ev);
        return (DefWindowProc (Handle, Message, WParam, LParam));
    }
}

#endif // _WIN32
