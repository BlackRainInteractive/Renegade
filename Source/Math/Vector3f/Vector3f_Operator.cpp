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

#include <Renegade/Math/Vector3f/Vector3f.hpp>
#include <Renegade/Math/Matrix4f/Matrix4f.hpp>
#include <cassert>

// The Renegade namespace
namespace rge {

/*============================================================================================================*/
/*------ARITHMETIC OPERATORS----------------------------------------------------------------------------------*/
/*============================================================================================================*/

    // Addition operator (vector)
    Vector3f Vector3f::operator + (const Vector3f& RHS) {

        return (Vector3f (this -> x + RHS.x,
                          this -> y + RHS.y,
                          this -> z + RHS.z));
    }

/*============================================================================================================*/

    // Addition operator (float)
    Vector3f Vector3f::operator + (const float RHS) {

        return (Vector3f (this -> x + RHS,
                          this -> y + RHS,
                          this -> z + RHS));
    }

/*============================================================================================================*/

    // Unary plus operator
    Vector3f Vector3f::operator + () {

        return (Vector3f (+this -> x,
                          +this -> y,
                          +this -> z));
    }

/*============================================================================================================*/

    // Increment operator (prefix)
    Vector3f Vector3f::operator ++ () {

        ++this -> x;
        ++this -> y;
        ++this -> z;

        return (*this);
    }

/*============================================================================================================*/

    // Increment operator (postfix)
    Vector3f Vector3f::operator ++ (int) {

        Vector3f original = *this;

        ++this -> x;
        ++this -> y;
        ++this -> z;

        return (original);
    }

/*============================================================================================================*/

    // Subtraction operator (vector)
    Vector3f Vector3f::operator - (const Vector3f& RHS) {

        return (Vector3f (this -> x - RHS.x,
                          this -> y - RHS.y,
                          this -> z - RHS.z));
    }

/*============================================================================================================*/

    // Subtraction operator (float)
    Vector3f Vector3f::operator - (const float RHS) {

        return (Vector3f (this -> x - RHS,
                          this -> y - RHS,
                          this -> z - RHS));
    }

/*============================================================================================================*/

    // Unary minus operator
    Vector3f Vector3f::operator - () {

        return (Vector3f (-this -> x,
                          -this -> y,
                          -this -> z));
    }

/*============================================================================================================*/

    // Decrement operator (prefix)
    Vector3f Vector3f::operator -- () {

        --this -> x;
        --this -> y;
        --this -> z;

        return (*this);
    }

/*============================================================================================================*/

    // Decrement operator (postfix)
    Vector3f Vector3f::operator -- (int) {

        Vector3f original = *this;

        --this -> x;
        --this -> y;
        --this -> z;

        return (original);
    }

/*============================================================================================================*/

    // Multiplication operator (matrix)
    Vector3f Vector3f::operator* (const Matrix4f& RHS) {

        Matrix4f rhs = RHS;

        return (rhs * *this);
    }

/*============================================================================================================*/

    // Multiplication operator (vector)
    Vector3f Vector3f::operator * (const Vector3f& RHS) {

        return (Vector3f (this -> x * RHS.x,
                          this -> y * RHS.y,
                          this -> z * RHS.z));
    }

/*============================================================================================================*/

    // Multiplication operator (float)
    Vector3f Vector3f::operator * (const float RHS) {

        return (Vector3f (this -> x * RHS,
                          this -> y * RHS,
                          this -> z * RHS));
    }

/*============================================================================================================*/

    // Division operator (vector)
    Vector3f Vector3f::operator / (const Vector3f& RHS) {

        return (Vector3f (this -> x / RHS.x,
                          this -> y / RHS.y,
                          this -> z / RHS.z));
    }

/*============================================================================================================*/

    // Division operator (float)
    Vector3f Vector3f::operator / (const float RHS) {

        return (Vector3f (this -> x / RHS,
                          this -> y / RHS,
                          this -> z / RHS));
    }

/*============================================================================================================*/
/*------RELATIONAL OPERATORS----------------------------------------------------------------------------------*/
/*============================================================================================================*/

    // Equal to operator
    bool Vector3f::operator == (const Vector3f& RHS) {

        return ((this -> x == RHS.x) &&
                (this -> y == RHS.y) &&
                (this -> z == RHS.z));
    }

/*============================================================================================================*/

    // Not equal to operator
    bool Vector3f::operator != (const Vector3f& RHS) {

        return ((this -> x != RHS.x) ||
                (this -> y != RHS.y) ||
                (this -> z != RHS.z));
    }

/*============================================================================================================*/
/*------COMPOUND ASSIGNMENT OPERATORS-------------------------------------------------------------------------*/
/*============================================================================================================*/

    // Addition assignment operator (vector)
    Vector3f& Vector3f::operator += (const Vector3f& RHS) {

        return (*this = *this + RHS);
    }

/*============================================================================================================*/

    // Addition assignment operator (float)
    Vector3f& Vector3f::operator += (const float RHS) {

        return (*this = *this + RHS);
    }

/*============================================================================================================*/

    // Subtraction assignment operator (vector)
    Vector3f& Vector3f::operator -= (const Vector3f& RHS) {

        return (*this = *this - RHS);
    }

/*============================================================================================================*/

    // Subtraction assignment operator (float)
    Vector3f& Vector3f::operator -= (const float RHS) {

        return (*this = *this - RHS);
    }

/*============================================================================================================*/

    // Multiplication assignment operator (matrix)
    Vector3f& Vector3f::operator*= (const Matrix4f& RHS) {

        Matrix4f rhs = RHS;

        return (*this = rhs * *this);
    }

/*============================================================================================================*/

    // Multiplication assignment operator (vector)
    Vector3f& Vector3f::operator *= (const Vector3f& RHS) {

        return (*this = *this * RHS);
    }

/*============================================================================================================*/

    // Multiplication assignment operator (float)
    Vector3f& Vector3f::operator *= (const float RHS) {

        return (*this = *this * RHS);
    }

/*============================================================================================================*/

    // Division assignment operator (vector)
    Vector3f& Vector3f::operator /= (const Vector3f& RHS) {

        return (*this = *this / RHS);
    }

/*============================================================================================================*/

    // Division assignment operator (float)
    Vector3f& Vector3f::operator /= (const float RHS) {

        return (*this = *this / RHS);
    }

/*============================================================================================================*/
/*------MEMBER OPERATORS--------------------------------------------------------------------------------------*/
/*============================================================================================================*/

    // Array subscript operator
    float& Vector3f::operator [] (int Index) {

        assert (Index > -1 && Index < 3);

        switch (Index) {

            case 0:
                return (this -> x);

            case 1:
                return (this -> y);

            case 2:
                return (this -> z);

            default:
                return (this -> x);
        }
    }
}
