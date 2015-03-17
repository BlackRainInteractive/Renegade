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

#if defined _WIN32 | WIN64
#include <Renegade/System/Input/Win32/Input_Win32.hpp>

// The Renegade namespace
namespace rge {

/*============================================================================================================*/
/*------STATIC FUNCTIONS--------------------------------------------------------------------------------------*/
/*============================================================================================================*/

    // Map virtual key to RGE key
    KeyCode Input::MapVirtualKeyToRGE (WPARAM Key, LPARAM Flags) {

        switch (Key) {

            // Determine left / right shift
            case VK_SHIFT: {

                const UINT lShift = MapVirtualKeyW (VK_LSHIFT, MAPVK_VK_TO_VSC);
                UINT scanCode = (UINT) (Flags & (0xFF << 16)) >> 16;

                return (scanCode == lShift ? KeyCode::LShift : KeyCode::RShift);
            }

            // Determine left / right alt
            case VK_MENU:
                return ((HIWORD (Flags) & KF_EXTENDED) ? KeyCode::RAlt : KeyCode::LAlt);

            // Determine left / right control
            case VK_CONTROL:
                return (HIWORD (Flags) & KF_EXTENDED) ? KeyCode::RControl : KeyCode::LControl;

            // The rest of the keys
            case 'A':           return (KeyCode::A);
            case 'B':           return (KeyCode::B);
            case 'C':           return (KeyCode::C);
            case 'D':           return (KeyCode::D);
            case 'E':           return (KeyCode::E);
            case 'F':           return (KeyCode::F);
            case 'G':           return (KeyCode::G);
            case 'H':           return (KeyCode::H);
            case 'I':           return (KeyCode::I);
            case 'J':           return (KeyCode::J);
            case 'K':           return (KeyCode::K);
            case 'L':           return (KeyCode::L);
            case 'M':           return (KeyCode::M);
            case 'N':           return (KeyCode::N);
            case 'O':           return (KeyCode::O);
            case 'P':           return (KeyCode::P);
            case 'Q':           return (KeyCode::Q);
            case 'R':           return (KeyCode::R);
            case 'S':           return (KeyCode::S);
            case 'T':           return (KeyCode::T);
            case 'U':           return (KeyCode::U);
            case 'V':           return (KeyCode::V);
            case 'W':           return (KeyCode::W);
            case 'X':           return (KeyCode::X);
            case 'Y':           return (KeyCode::Y);
            case 'Z':           return (KeyCode::Z);
            case '0':           return (KeyCode::Num0);
            case '1':           return (KeyCode::Num1);
            case '2':           return (KeyCode::Num2);
            case '3':           return (KeyCode::Num3);
            case '4':           return (KeyCode::Num4);
            case '5':           return (KeyCode::Num5);
            case '6':           return (KeyCode::Num6);
            case '7':           return (KeyCode::Num7);
            case '8':           return (KeyCode::Num8);
            case '9':           return (KeyCode::Num9);
            case VK_NUMPAD0:    return (KeyCode::Numpad0);
            case VK_NUMPAD1:    return (KeyCode::Numpad1);
            case VK_NUMPAD2:    return (KeyCode::Numpad2);
            case VK_NUMPAD3:    return (KeyCode::Numpad3);
            case VK_NUMPAD4:    return (KeyCode::Numpad4);
            case VK_NUMPAD5:    return (KeyCode::Numpad5);
            case VK_NUMPAD6:    return (KeyCode::Numpad6);
            case VK_NUMPAD7:    return (KeyCode::Numpad7);
            case VK_NUMPAD8:    return (KeyCode::Numpad8);
            case VK_NUMPAD9:    return (KeyCode::Numpad9);
            case VK_F1:         return (KeyCode::F1);
            case VK_F2:         return (KeyCode::F2);
            case VK_F3:         return (KeyCode::F3);
            case VK_F4:         return (KeyCode::F4);
            case VK_F5:         return (KeyCode::F5);
            case VK_F6:         return (KeyCode::F6);
            case VK_F7:         return (KeyCode::F7);
            case VK_F8:         return (KeyCode::F8);
            case VK_F9:         return (KeyCode::F9);
            case VK_F10:        return (KeyCode::F10);
            case VK_F11:        return (KeyCode::F11);
            case VK_F12:        return (KeyCode::F12);
            case VK_ESCAPE:     return (KeyCode::Escape);
            case VK_LWIN:       return (KeyCode::LSystem);
            case VK_RWIN:       return (KeyCode::RSystem);
            case VK_APPS:       return (KeyCode::Menu);
            case VK_OEM_4:      return (KeyCode::LBracket);
            case VK_OEM_6:      return (KeyCode::RBracket);
            case VK_OEM_1:      return (KeyCode::SemiColon);
            case VK_OEM_COMMA:  return (KeyCode::Comma);
            case VK_OEM_PERIOD: return (KeyCode::Period);
            case VK_OEM_7:      return (KeyCode::Quote);
            case VK_OEM_2:      return (KeyCode::Slash);
            case VK_OEM_5:      return (KeyCode::BackSlash);
            case VK_OEM_3:      return (KeyCode::Tilde);
            case VK_OEM_PLUS:   return (KeyCode::Equal);
            case VK_OEM_MINUS:  return (KeyCode::Dash);
            case VK_SPACE:      return (KeyCode::Space);
            case VK_RETURN:     return (KeyCode::Enter);
            case VK_BACK:       return (KeyCode::BackSpace);
            case VK_TAB:        return (KeyCode::Tab);
            case VK_PRIOR:      return (KeyCode::PageUp);
            case VK_NEXT:       return (KeyCode::PageDown);
            case VK_END:        return (KeyCode::End);
            case VK_HOME:       return (KeyCode::Home);
            case VK_INSERT:     return (KeyCode::Insert);
            case VK_DELETE:     return (KeyCode::Delete);
            case VK_ADD:        return (KeyCode::Add);
            case VK_SUBTRACT:   return (KeyCode::Subtract);
            case VK_MULTIPLY:   return (KeyCode::Multiply);
            case VK_DIVIDE:     return (KeyCode::Divide);
            case VK_UP:         return (KeyCode::Up);
            case VK_DOWN:       return (KeyCode::Down);
            case VK_LEFT:       return (KeyCode::Left);
            case VK_RIGHT:      return (KeyCode::Right);
            case VK_PAUSE:      return (KeyCode::Pause);
            default:            return (KeyCode::Unknown);
        }
    }
}

#endif // _WIN32 | WIN64
