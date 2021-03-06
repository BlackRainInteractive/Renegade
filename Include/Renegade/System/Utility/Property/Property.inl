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

// The Renegade namespace
namespace rge {

/*============================================================================================================*/
/*------CONSTRUCTOR-------------------------------------------------------------------------------------------*/
/*============================================================================================================*/

    // The default constructor
    template <typename Base, typename Type>
    Property <Base, Type>::Property () : _baseObject (nullptr), _Get (nullptr), _Set (nullptr) {

    }

/*============================================================================================================*/

    // Construct from functions
    template <typename Base, typename Type>
    Property <Base, Type>::Property (Base* BaseType, Type (Base::*Getter)(), void (Base::*Setter)(Type), PropertyMode Mode) {

        Create (BaseType, Getter, Setter, Mode);
    }

/*============================================================================================================*/
/*------PUBLIC FUNCTIONS--------------------------------------------------------------------------------------*/
/*============================================================================================================*/

    // Create the property
    template <typename Base, typename Type>
    void Property <Base, Type>::Create (Base* BaseType, Type (Base::*Getter)(), void (Base::*Setter)(Type Value), PropertyMode Mode) {

        _baseObject = BaseType;
        _mode       = Mode;

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
        }
    }

/*============================================================================================================*/

    // Get the value
    template <typename Base, typename Type>
    Type Property <Base, Type>::Get () {

        assert (_mode != PropertyMode::WriteOnly);
        assert (_baseObject != nullptr);
        assert (_Get != nullptr);

        return (_baseObject ->*_Get)();
    }

/*============================================================================================================*/

    // Set the value
    template <typename Base, typename Type>
    Type Property <Base, Type>::Set (const Type& Value) {

        assert (_mode != PropertyMode::ReadOnly);
        assert (_baseObject != nullptr);
        assert (_Set != nullptr);

        (_baseObject ->*_Set)(Value);
        return Value;
    }

/*============================================================================================================*/
/*------OPERATOR OVERLOADS------------------------------------------------------------------------------------*/
/*============================================================================================================*/

    // Get the value
    template <typename Base, typename Type>
    Property <Base, Type>::operator Type () {

        return (this -> Get ());
    }

/*============================================================================================================*/

    // Set the value
    template <typename Base, typename Type>
    Type Property <Base, Type>::operator = (const Type& Value) {

        return (this -> Set (Value));
    }
}
