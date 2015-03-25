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

#include <Renegade/Math/Colour/Colour.hpp>
#include <cassert>

// The Renegade namespace
namespace rge {

/*============================================================================================================*/
/*------ARITHMETIC OPERATORS----------------------------------------------------------------------------------*/
/*============================================================================================================*/

    // Addition operator (colour)
    Colour Colour::operator + (const Colour& RHS) {

        return (Colour (this -> r + RHS.r,
                        this -> g + RHS.g,
                        this -> b + RHS.b,
                        this -> a + RHS.a));
    }

/*============================================================================================================*/

    // Addition operator (float)
    Colour Colour::operator + (const float RHS) {

        return (Colour (this -> r + RHS,
                        this -> g + RHS,
                        this -> b + RHS,
                        this -> a + RHS));
    }

/*============================================================================================================*/

    // Unary plus operator
    Colour Colour::operator + () {

        return (Colour (+this -> r,
                        +this -> g,
                        +this -> b,
                        +this -> a));
    }

/*============================================================================================================*/

    // Increment operator (prefix)
    Colour Colour::operator ++ () {

        ++this -> r;
        ++this -> g;
        ++this -> b;
        ++this -> a;

        return (*this);
    }

/*============================================================================================================*/

    // Increment operator (postfix)
    Colour Colour::operator ++ (int) {

        Colour original = *this;

        ++this -> r;
        ++this -> g;
        ++this -> b;
        ++this -> a;

        return (original);
    }

/*============================================================================================================*/

    // Subtraction operator (colour)
    Colour Colour::operator - (const Colour& RHS) {

        return (Colour (this -> r - RHS.r,
                        this -> g - RHS.g,
                        this -> b - RHS.b,
                        this -> a - RHS.a));
    }

/*============================================================================================================*/

    // Subtraction operator (float)
    Colour Colour::operator - (const float RHS) {

        return (Colour (this -> r - RHS,
                        this -> g - RHS,
                        this -> b - RHS,
                        this -> a - RHS));
    }

/*============================================================================================================*/

    // Unary minus operator
    Colour Colour::operator - () {

        return (Colour (-this -> r,
                        -this -> g,
                        -this -> b,
                        -this -> a));
    }

/*============================================================================================================*/

    // Decrement operator (prefix)
    Colour Colour::operator -- () {

        --this -> r;
        --this -> g;
        --this -> b;
        --this -> a;

        return (*this);
    }

/*============================================================================================================*/

    // Decrement operator (postfix)
    Colour Colour::operator -- (int) {

        Colour original = *this;

        --this -> r;
        --this -> g;
        --this -> b;
        --this -> a;

        return (original);
    }

/*============================================================================================================*/

    // Multiplication operator (colour)
    Colour Colour::operator *  (const Colour& RHS) {

        return (Colour (this -> r * RHS.r,
                        this -> g * RHS.g,
                        this -> b * RHS.b,
                        this -> a * RHS.a));
    }

/*============================================================================================================*/

    // Multiplication operator (float)
    Colour Colour::operator * (const float RHS) {

        return (Colour (this -> r * RHS,
                        this -> g * RHS,
                        this -> b * RHS,
                        this -> a * RHS));
    }

/*============================================================================================================*/

    // Division operator (colour)
    Colour Colour::operator / (const Colour& RHS) {

        return (Colour (this -> r / RHS.r,
                        this -> g / RHS.g,
                        this -> b / RHS.b,
                        this -> a / RHS.a));
    }

/*============================================================================================================*/

    // Division operator (float)
    Colour Colour::operator / (const float RHS) {

        return (Colour (this -> r / RHS,
                        this -> g / RHS,
                        this -> b / RHS,
                        this -> a / RHS));
    }

/*============================================================================================================*/
/*------RELATIONAL OPERATORS----------------------------------------------------------------------------------*/
/*============================================================================================================*/

    // Equal to operator
    bool Colour::operator == (const Colour& RHS) {

        return ((this -> r == RHS.r) &&
                (this -> g == RHS.g) &&
                (this -> b == RHS.b) &&
                (this -> a == RHS.a));
    }

/*============================================================================================================*/

    // Not equal to operator
    bool Colour::operator != (const Colour& RHS) {

        return ((this -> r != RHS.r) ||
                (this -> g != RHS.g) ||
                (this -> b != RHS.b) ||
                (this -> a != RHS.a));
    }

/*============================================================================================================*/
/*------COMPOUND ASSIGNMENT OPERATORS-------------------------------------------------------------------------*/
/*============================================================================================================*/

    // Addition assignment operator (colour)
    Colour& Colour::operator += (const Colour& RHS) {

        return (*this = *this + RHS);
    }

/*============================================================================================================*/

    // Addition assignment operator (float)
    Colour& Colour::operator += (const float RHS) {

        return (*this = *this + RHS);
    }

/*============================================================================================================*/

    // Subtraction assignment operator (colour)
    Colour& Colour::operator -= (const Colour& RHS) {

        return (*this = *this - RHS);
    }

/*============================================================================================================*/

    // Subtraction assignment operator (float)
    Colour& Colour::operator -= (const float RHS) {

        return (*this = *this - RHS);
    }

/*============================================================================================================*/

    // Multiplication assignment operator (colour)
    Colour& Colour::operator *= (const Colour& RHS) {

        return (*this = *this * RHS);
    }

/*============================================================================================================*/

    // Multiplication assignment operator (float)
    Colour& Colour::operator *= (const float RHS) {

        return (*this = *this * RHS);
    }

/*============================================================================================================*/

    // Division assignment operator (colour)
    Colour& Colour::operator /= (const Colour& RHS) {

        return (*this = *this / RHS);
    }

/*============================================================================================================*/

    // Division assignment operator (float)
    Colour& Colour::operator /= (const float RHS) {

        return (*this = *this / RHS);
    }

/*============================================================================================================*/
/*------MEMBER OPERATORS--------------------------------------------------------------------------------------*/
/*============================================================================================================*/

    // Array subscript operator
    float& Colour::operator [] (int Index) {

        assert (Index > -1 && Index < 4);

        switch (Index) {

            case 0:
                return (this -> r);

            case 1:
                return (this -> g);

            case 2:
                return (this -> b);

            case 3:
                return (this -> a);

            default:
                return (this -> r);
        }
    }
}
