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
    Keyboard Input::MapVirtualKeyToRGE (WPARAM Key, LPARAM Flags) {

        switch (Key) {

            // Determine left / right shift
            case VK_SHIFT: {

                const UINT lShift = MapVirtualKeyW (VK_LSHIFT, MAPVK_VK_TO_VSC);
                UINT scanCode = (UINT) (Flags & (0xFF << 16)) >> 16;

                return (scanCode == lShift ? Keyboard::LShift : Keyboard::RShift);
            }

            // Determine left / right alt
            case VK_MENU:
                return ((HIWORD (Flags) & KF_EXTENDED) ? Keyboard::RAlt : Keyboard::LAlt);

            // Determine left / right control
            case VK_CONTROL:
                return (HIWORD (Flags) & KF_EXTENDED) ? Keyboard::RControl : Keyboard::LControl;

            // The rest of the keys
            case 'A':           return (Keyboard::A);
            case 'B':           return (Keyboard::B);
            case 'C':           return (Keyboard::C);
            case 'D':           return (Keyboard::D);
            case 'E':           return (Keyboard::E);
            case 'F':           return (Keyboard::F);
            case 'G':           return (Keyboard::G);
            case 'H':           return (Keyboard::H);
            case 'I':           return (Keyboard::I);
            case 'J':           return (Keyboard::J);
            case 'K':           return (Keyboard::K);
            case 'L':           return (Keyboard::L);
            case 'M':           return (Keyboard::M);
            case 'N':           return (Keyboard::N);
            case 'O':           return (Keyboard::O);
            case 'P':           return (Keyboard::P);
            case 'Q':           return (Keyboard::Q);
            case 'R':           return (Keyboard::R);
            case 'S':           return (Keyboard::S);
            case 'T':           return (Keyboard::T);
            case 'U':           return (Keyboard::U);
            case 'V':           return (Keyboard::V);
            case 'W':           return (Keyboard::W);
            case 'X':           return (Keyboard::X);
            case 'Y':           return (Keyboard::Y);
            case 'Z':           return (Keyboard::Z);
            case '0':           return (Keyboard::Num0);
            case '1':           return (Keyboard::Num1);
            case '2':           return (Keyboard::Num2);
            case '3':           return (Keyboard::Num3);
            case '4':           return (Keyboard::Num4);
            case '5':           return (Keyboard::Num5);
            case '6':           return (Keyboard::Num6);
            case '7':           return (Keyboard::Num7);
            case '8':           return (Keyboard::Num8);
            case '9':           return (Keyboard::Num9);
            case VK_NUMPAD0:    return (Keyboard::Numpad0);
            case VK_NUMPAD1:    return (Keyboard::Numpad1);
            case VK_NUMPAD2:    return (Keyboard::Numpad2);
            case VK_NUMPAD3:    return (Keyboard::Numpad3);
            case VK_NUMPAD4:    return (Keyboard::Numpad4);
            case VK_NUMPAD5:    return (Keyboard::Numpad5);
            case VK_NUMPAD6:    return (Keyboard::Numpad6);
            case VK_NUMPAD7:    return (Keyboard::Numpad7);
            case VK_NUMPAD8:    return (Keyboard::Numpad8);
            case VK_NUMPAD9:    return (Keyboard::Numpad9);
            case VK_F1:         return (Keyboard::F1);
            case VK_F2:         return (Keyboard::F2);
            case VK_F3:         return (Keyboard::F3);
            case VK_F4:         return (Keyboard::F4);
            case VK_F5:         return (Keyboard::F5);
            case VK_F6:         return (Keyboard::F6);
            case VK_F7:         return (Keyboard::F7);
            case VK_F8:         return (Keyboard::F8);
            case VK_F9:         return (Keyboard::F9);
            case VK_F10:        return (Keyboard::F10);
            case VK_F11:        return (Keyboard::F11);
            case VK_F12:        return (Keyboard::F12);
            case VK_ESCAPE:     return (Keyboard::Escape);
            case VK_LWIN:       return (Keyboard::LSystem);
            case VK_RWIN:       return (Keyboard::RSystem);
            case VK_APPS:       return (Keyboard::Menu);
            case VK_OEM_4:      return (Keyboard::LBracket);
            case VK_OEM_6:      return (Keyboard::RBracket);
            case VK_OEM_1:      return (Keyboard::SemiColon);
            case VK_OEM_COMMA:  return (Keyboard::Comma);
            case VK_OEM_PERIOD: return (Keyboard::Period);
            case VK_OEM_7:      return (Keyboard::Quote);
            case VK_OEM_2:      return (Keyboard::Slash);
            case VK_OEM_5:      return (Keyboard::BackSlash);
            case VK_OEM_3:      return (Keyboard::Tilde);
            case VK_OEM_PLUS:   return (Keyboard::Equal);
            case VK_OEM_MINUS:  return (Keyboard::Dash);
            case VK_SPACE:      return (Keyboard::Space);
            case VK_RETURN:     return (Keyboard::Enter);
            case VK_BACK:       return (Keyboard::BackSpace);
            case VK_TAB:        return (Keyboard::Tab);
            case VK_PRIOR:      return (Keyboard::PageUp);
            case VK_NEXT:       return (Keyboard::PageDown);
            case VK_END:        return (Keyboard::End);
            case VK_HOME:       return (Keyboard::Home);
            case VK_INSERT:     return (Keyboard::Insert);
            case VK_DELETE:     return (Keyboard::Delete);
            case VK_ADD:        return (Keyboard::Add);
            case VK_SUBTRACT:   return (Keyboard::Subtract);
            case VK_MULTIPLY:   return (Keyboard::Multiply);
            case VK_DIVIDE:     return (Keyboard::Divide);
            case VK_UP:         return (Keyboard::Up);
            case VK_DOWN:       return (Keyboard::Down);
            case VK_LEFT:       return (Keyboard::Left);
            case VK_RIGHT:      return (Keyboard::Right);
            case VK_PAUSE:      return (Keyboard::Pause);
            default:            return (Keyboard::Unknown);
        }
    }
}

#endif // _WIN32 | WIN64
