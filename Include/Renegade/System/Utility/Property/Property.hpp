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

#include <Renegade/System/Utility/Property/Property_Enum.hpp>
#include <cassert>

// The Renegade namespace
namespace rge {

    // The property class
    template <typename Base, typename Type>
    class Property {
    public:

        // Constructor / Destructor
        Property () : _baseObject (nullptr), _Get (nullptr), _Set (nullptr) {}
        Property (Base* BaseType, Type (Base::*Getter)(), void (Base::*Setter)(Type Value), PropertyMode Mode = PropertyMode::ReadWrite) {

            Create (BaseType, Getter, Setter, Mode);
        }

        // Functions
        void Create (Base* BaseType, Type (Base::*Getter)(), void (Base::*Setter)(Type Value), PropertyMode Mode = PropertyMode::ReadWrite) {

            _baseObject = BaseType;

            switch (Mode) {

                case PropertyMode::ReadOnly:

                    _Get = Getter;
                    _Set = nullptr;
                    break;

                case PropertyMode::WriteOnly:

                    _Get = nullptr;
                    _Set = Setter;
                    break;

                case PropertyMode::ReadWrite:

                    _Get = Getter;
                    _Set = Setter;
                    break;

                default:

                    _Get = nullptr;
                    _Set = nullptr;
                    break;
            }
        }

        // Overloads
        Type operator = (const Type& Value) {

            assert (_baseObject != nullptr);
            assert (_Set != nullptr);

            (_baseObject ->*_Set)(Value);
            return Value;
        }

        operator Type () {

            assert (_baseObject != nullptr);
            assert (_Get != nullptr);

            return (_baseObject ->*_Get)();
        }

    private:

        // Variables
        Base* _baseObject;

        // Function Pointers
        void (Base::*_Set)(Type Value);
        Type (Base::*_Get)();
    };
}
