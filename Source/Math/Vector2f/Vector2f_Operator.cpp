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

#include <Renegade/Math/Vector2f/Vector2f.hpp>
#include <Renegade/Math/Matrix3f/Matrix3f.hpp>
#include <cassert>

// The Renegade namespace
namespace rge {

/*============================================================================================================*/
/*------ARITHMETIC OPERATORS----------------------------------------------------------------------------------*/
/*============================================================================================================*/

    // Addition operator (vector)
    Vector2f Vector2f::operator + (const Vector2f& RHS) {

        return (Vector2f (this -> x + RHS.x,
                          this -> y + RHS.y));
    }

/*============================================================================================================*/

    // Addition operator (float)
    Vector2f Vector2f::operator + (const float RHS) {

        return (Vector2f (this -> x + RHS,
                          this -> y + RHS));
    }

/*============================================================================================================*/

    // Unary plus operator
    Vector2f Vector2f::operator + () {

        return (Vector2f (+this -> x,
                          +this -> y));
    }

/*============================================================================================================*/

    // Increment operator (prefix)
    Vector2f Vector2f::operator ++ () {

        ++this -> x;
        ++this -> y;

        return (*this);
    }

/*============================================================================================================*/

    // Increment operator (postfix)
    Vector2f Vector2f::operator ++ (int) {

        Vector2f original = *this;

        ++this -> x;
        ++this -> y;

        return (original);
    }

/*============================================================================================================*/

    // Subtraction operator (vector)
    Vector2f Vector2f::operator - (const Vector2f& RHS) {

        return (Vector2f (this -> x - RHS.x,
                          this -> y - RHS.y));
    }

/*============================================================================================================*/

    // Subtraction operator (float)
    Vector2f Vector2f::operator - (const float RHS) {

        return (Vector2f (this -> x - RHS,
                          this -> y - RHS));
    }

/*============================================================================================================*/

    // Unary minus operator
    Vector2f Vector2f::operator - () {

        return (Vector2f (-this -> x,
                          -this -> y));
    }

/*============================================================================================================*/

    // Decrement operator (prefix)
    Vector2f Vector2f::operator -- () {

        --this -> x;
        --this -> y;

        return (*this);
    }

/*============================================================================================================*/

    // Decrement operator (postfix)
    Vector2f Vector2f::operator -- (int) {

        Vector2f original = *this;

        --this -> x;
        --this -> y;

        return (original);
    }

/*============================================================================================================*/

    // Multiplication operator (matrix)
    Vector2f Vector2f::operator* (const Matrix3f& RHS) {

        Matrix3f rhs = RHS;

        return (rhs * *this);
    }

/*============================================================================================================*/

    // Multiplication operator (vector)
    Vector2f Vector2f::operator * (const Vector2f& RHS) {

        return (Vector2f (this -> x * RHS.x,
                          this -> y * RHS.y));
    }

/*============================================================================================================*/

    // Multiplication operator (float)
    Vector2f Vector2f::operator * (const float RHS) {

        return (Vector2f (this -> x * RHS,
                          this -> y * RHS));
    }

/*============================================================================================================*/

    // Division operator (vector)
    Vector2f Vector2f::operator / (const Vector2f& RHS) {

        return (Vector2f (this -> x / RHS.x,
                          this -> y / RHS.y));
    }

/*============================================================================================================*/

    // Division operator (float)
    Vector2f Vector2f::operator / (const float RHS) {

        return (Vector2f (this -> x / RHS,
                          this -> y / RHS));
    }

/*============================================================================================================*/
/*------RELATIONAL OPERATORS----------------------------------------------------------------------------------*/
/*============================================================================================================*/

    // Equal to operator
    bool Vector2f::operator == (const Vector2f& RHS) {

        return ((this -> x == RHS.x) &&
                (this -> y == RHS.y));
    }

/*============================================================================================================*/

    // Not equal to operator
    bool Vector2f::operator != (const Vector2f& RHS) {

        return ((this -> x != RHS.x) ||
                (this -> y != RHS.y));
    }

/*============================================================================================================*/
/*------COMPOUND ASSIGNMENT OPERATORS-------------------------------------------------------------------------*/
/*============================================================================================================*/

    // Addition assignment operator (vector)
    Vector2f& Vector2f::operator += (const Vector2f& RHS) {

        return (*this = *this + RHS);
    }

/*============================================================================================================*/

    // Addition assignment operator (float)
    Vector2f& Vector2f::operator += (const float RHS) {

        return (*this = *this + RHS);
    }

/*============================================================================================================*/

    // Subtraction assignment operator (vector)
    Vector2f& Vector2f::operator -= (const Vector2f& RHS) {

        return (*this = *this - RHS);
    }

/*============================================================================================================*/

    // Subtraction assignment operator (float)
    Vector2f& Vector2f::operator -= (const float RHS) {

        return (*this = *this - RHS);
    }

/*============================================================================================================*/

    // Multiplication assignment operator (matrix)
    Vector2f& Vector2f::operator*= (const Matrix3f& RHS) {

        return (*this = *this * RHS);
    }

/*============================================================================================================*/

    // Multiplication assignment operator (vector)
    Vector2f& Vector2f::operator *= (const Vector2f& RHS) {

        return (*this = *this * RHS);
    }

/*============================================================================================================*/

    // Multiplication assignment operator (float)
    Vector2f& Vector2f::operator *= (const float RHS) {

        return (*this = *this * RHS);
    }

/*============================================================================================================*/

    // Division assignment operator (vector)
    Vector2f& Vector2f::operator /= (const Vector2f& RHS) {

        return (*this = *this / RHS);
    }

/*============================================================================================================*/

    // Division assignment operator (float)
    Vector2f& Vector2f::operator /= (const float RHS) {

        return (*this = *this / RHS);
    }

/*============================================================================================================*/
/*------MEMBER OPERATORS--------------------------------------------------------------------------------------*/
/*============================================================================================================*/

    // Array subscript operator
    float& Vector2f::operator [] (int Index) {

        assert (Index > -1 && Index < 2);

        switch (Index) {

            case 0:
                return (this -> x);

            case 1:
                return (this -> y);

            default:
                return (this -> x);
        }
    }
}
