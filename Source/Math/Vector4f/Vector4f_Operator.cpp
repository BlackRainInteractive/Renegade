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

#include <Renegade/Math/Vector4f/Vector4f.hpp>
#include <cassert>

// The Renegade namespace
namespace rge {

/*============================================================================================================*/
/*------ARITHMETIC OPERATORS----------------------------------------------------------------------------------*/
/*============================================================================================================*/

    // Addition operator (vector)
    Vector4f Vector4f::operator + (const Vector4f& RHS) {

        return (Vector4f (this -> x + RHS.x,
                          this -> y + RHS.y,
                          this -> z + RHS.z,
                          this -> w + RHS.w));
    }

/*============================================================================================================*/

    // Addition operator (float)
    Vector4f Vector4f::operator + (const float RHS) {

        return (Vector4f (this -> x + RHS,
                          this -> y + RHS,
                          this -> z + RHS,
                          this -> w + RHS));
    }

/*============================================================================================================*/

    // Unary plus operator
    Vector4f Vector4f::operator + () {

        return (Vector4f (+this -> x,
                          +this -> y,
                          +this -> z,
                          +this -> w));
    }

/*============================================================================================================*/

    // Increment operator (prefix)
    Vector4f Vector4f::operator ++ () {

        ++this -> x;
        ++this -> y;
        ++this -> z;
        ++this -> w;

        return (*this);
    }

/*============================================================================================================*/

    // Increment operator (postfix)
    Vector4f Vector4f::operator ++ (int) {

        Vector4f original = *this;

        ++this -> x;
        ++this -> y;
        ++this -> z;
        ++this -> w;

        return (original);
    }

/*============================================================================================================*/

    // Subtraction operator (vector)
    Vector4f Vector4f::operator - (const Vector4f& RHS) {

        return (Vector4f (this -> x - RHS.x,
                          this -> y - RHS.y,
                          this -> z - RHS.z,
                          this -> w - RHS.w));
    }

/*============================================================================================================*/

    // Subtraction operator (float)
    Vector4f Vector4f::operator - (const float RHS) {

        return (Vector4f (this -> x - RHS,
                          this -> y - RHS,
                          this -> z - RHS,
                          this -> w - RHS));
    }

/*============================================================================================================*/

    // Unary minus operator
    Vector4f Vector4f::operator - () {

        return (Vector4f (-this -> x,
                          -this -> y,
                          -this -> z,
                          -this -> w));
    }

/*============================================================================================================*/

    // Decrement operator (prefix)
    Vector4f Vector4f::operator -- () {

        --this -> x;
        --this -> y;
        --this -> z;
        --this -> w;

        return (*this);
    }

/*============================================================================================================*/

    // Decrement operator (postfix)
    Vector4f Vector4f::operator -- (int) {

        Vector4f original = *this;

        --this -> x;
        --this -> y;
        --this -> z;
        --this -> w;

        return (original);
    }

/*============================================================================================================*/

    // Multiplication operator (vector)
    Vector4f Vector4f::operator *  (const Vector4f& RHS) {

        return (Vector4f (this -> x * RHS.x,
                          this -> y * RHS.y,
                          this -> z * RHS.z,
                          this -> w * RHS.w));
    }

/*============================================================================================================*/

    // Multiplication operator (float)
    Vector4f Vector4f::operator * (const float RHS) {

        return (Vector4f (this -> x * RHS,
                          this -> y * RHS,
                          this -> z * RHS,
                          this -> w * RHS));
    }

/*============================================================================================================*/

    // Division operator (vector)
    Vector4f Vector4f::operator / (const Vector4f& RHS) {

        return (Vector4f (this -> x / RHS.x,
                          this -> y / RHS.y,
                          this -> z / RHS.z,
                          this -> w / RHS.w));
    }

/*============================================================================================================*/

    // Division operator (float)
    Vector4f Vector4f::operator / (const float RHS) {

        return (Vector4f (this -> x / RHS,
                          this -> y / RHS,
                          this -> z / RHS,
                          this -> w / RHS));
    }

/*============================================================================================================*/
/*------RELATIONAL OPERATORS----------------------------------------------------------------------------------*/
/*============================================================================================================*/

    // Equal to operator
    bool Vector4f::operator == (const Vector4f& RHS) {

        return ((this -> x == RHS.x) &&
                (this -> y == RHS.y) &&
                (this -> z == RHS.z) &&
                (this -> w == RHS.w));
    }

/*============================================================================================================*/

    // Not equal to operator
    bool Vector4f::operator != (const Vector4f& RHS) {

        return ((this -> x != RHS.x) ||
                (this -> y != RHS.y) ||
                (this -> z != RHS.z) ||
                (this -> w != RHS.w));
    }

/*============================================================================================================*/
/*------COMPOUND ASSIGNMENT OPERATORS-------------------------------------------------------------------------*/
/*============================================================================================================*/

    // Addition assignment operator (vector)
    Vector4f& Vector4f::operator += (const Vector4f& RHS) {

        return (*this = *this + RHS);
    }

/*============================================================================================================*/

    // Addition assignment operator (float)
    Vector4f& Vector4f::operator += (const float RHS) {

        return (*this = *this + RHS);
    }

/*============================================================================================================*/

    // Subtraction assignment operator (vector)
    Vector4f& Vector4f::operator -= (const Vector4f& RHS) {

        return (*this = *this - RHS);
    }

/*============================================================================================================*/

    // Subtraction assignment operator (float)
    Vector4f& Vector4f::operator -= (const float RHS) {

        return (*this = *this - RHS);
    }

/*============================================================================================================*/

    // Multiplication assignment operator (vector)
    Vector4f& Vector4f::operator *= (const Vector4f& RHS) {

        return (*this = *this * RHS);
    }

/*============================================================================================================*/

    // Multiplication assignment operator (float)
    Vector4f& Vector4f::operator *= (const float RHS) {

        return (*this = *this * RHS);
    }

/*============================================================================================================*/

    // Division assignment operator (vector)
    Vector4f& Vector4f::operator /= (const Vector4f& RHS) {

        return (*this = *this / RHS);
    }

/*============================================================================================================*/

    // Division assignment operator (float)
    Vector4f& Vector4f::operator /= (const float RHS) {

        return (*this = *this / RHS);
    }

/*============================================================================================================*/
/*------MEMBER OPERATORS--------------------------------------------------------------------------------------*/
/*============================================================================================================*/

    // Array subscript operator
    float& Vector4f::operator [] (int Index) {

        assert (Index > -1 && Index < 4);

        switch (Index) {

            case 0:
                return (this -> x);

            case 1:
                return (this -> y);

            case 2:
                return (this -> z);

            case 3:
                return (this -> w);

            default:
                return (this -> x);
        }
    }
}
