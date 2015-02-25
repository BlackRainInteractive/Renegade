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

#include <Renegade/Math/Matrix4f/Matrix4f.hpp>
#include <cassert>

// The Renegade Namespace
namespace rge {

/*============================================================================================================*/
/*------ARITHMETIC OPERATORS----------------------------------------------------------------------------------*/
/*============================================================================================================*/

    // Addition operator (matrix)
    Matrix4f Matrix4f::operator + (const Matrix4f& RHS) {

        return (Matrix4f (this -> _value [0] + RHS._value [0],
                          this -> _value [1] + RHS._value [1],
                          this -> _value [2] + RHS._value [2],
                          this -> _value [3] + RHS._value [3]));
    }

/*============================================================================================================*/

    // Addition operator (vector)
    Matrix4f Matrix4f::operator + (const Vector4f& RHS) {

        return (Matrix4f (this -> _value [0] + RHS,
                          this -> _value [1] + RHS,
                          this -> _value [2] + RHS,
                          this -> _value [3] + RHS));
    }

/*============================================================================================================*/

    // Addition operator (float)
    Matrix4f Matrix4f::operator + (const float RHS) {

        return (Matrix4f (this -> _value [0] + RHS,
                          this -> _value [1] + RHS,
                          this -> _value [2] + RHS,
                          this -> _value [3] + RHS));
    }

/*============================================================================================================*/

    // Increment operator (prefix)
    Matrix4f Matrix4f::operator ++ () {

        return (Matrix4f (++this -> _value [0],
                          ++this -> _value [1],
                          ++this -> _value [2],
                          ++this -> _value [3]));
    }

/*============================================================================================================*/

    // Increment operator (postfix)
    Matrix4f Matrix4f::operator ++ (int) {

        return (Matrix4f (this -> _value [0]++,
                          this -> _value [1]++,
                          this -> _value [2]++,
                          this -> _value [3]++));
    }

/*============================================================================================================*/

    // Subtraction operator (matrix)
    Matrix4f Matrix4f::operator - (const Matrix4f& RHS) {

        return (Matrix4f (this -> _value [0] - RHS._value [0],
                          this -> _value [1] - RHS._value [1],
                          this -> _value [2] - RHS._value [2],
                          this -> _value [3] - RHS._value [3]));
    }

/*============================================================================================================*/

    // Subtraction operator (vector)
    Matrix4f Matrix4f::operator - (const Vector4f& RHS) {

        return (Matrix4f (this -> _value [0] - RHS,
                          this -> _value [1] - RHS,
                          this -> _value [2] - RHS,
                          this -> _value [3] - RHS));
    }

/*============================================================================================================*/

    // Subtraction operator (float)
    Matrix4f Matrix4f::operator - (const float RHS) {

        return (Matrix4f (this -> _value [0] - RHS,
                          this -> _value [1] - RHS,
                          this -> _value [2] - RHS,
                          this -> _value [3] - RHS));
    }

/*============================================================================================================*/

    // Decrement operator (prefix)
    Matrix4f Matrix4f::operator -- () {

        return (Matrix4f (--this -> _value [0],
                          --this -> _value [1],
                          --this -> _value [2],
                          --this -> _value [3]));
    }

/*============================================================================================================*/

    // Decrement operator (postfix)
    Matrix4f Matrix4f::operator -- (int) {

        return (Matrix4f (this -> _value [0]--,
                          this -> _value [1]--,
                          this -> _value [2]--,
                          this -> _value [3]--));
    }

/*============================================================================================================*/

    // Multiplication operator (matrix)
    Matrix4f Matrix4f::operator * (const Matrix4f& RHS) {

        Matrix4f returnMatrix;
        Matrix4f rhs = RHS;

        for (int row = 0; row < 4; ++row) {

            for (int col = 0; col < 4; ++col) {

                for (int inner = 0; inner < 4; ++inner)
                    returnMatrix [row][col] += (this -> _value [row][inner] * rhs [inner][col]);
            }
        }

        return (returnMatrix);
    }

/*============================================================================================================*/

    // Multiplication operator (vector)
    Vector4f Matrix4f::operator * (const Vector4f& RHS) {

        return (Vector4f ((this -> _value [0][0] * RHS.x) + (this -> _value [1][0] * RHS.y) + (this -> _value [2][0] * RHS.z) + (this -> _value [3][0] * RHS.w),
                          (this -> _value [0][1] * RHS.x) + (this -> _value [1][1] * RHS.y) + (this -> _value [2][1] * RHS.z) + (this -> _value [3][1] * RHS.w),
                          (this -> _value [0][2] * RHS.x) + (this -> _value [1][2] * RHS.y) + (this -> _value [2][2] * RHS.z) + (this -> _value [3][2] * RHS.w),
                          (this -> _value [0][3] * RHS.x) + (this -> _value [1][3] * RHS.y) + (this -> _value [2][3] * RHS.z) + (this -> _value [3][3] * RHS.w)));
    }

/*============================================================================================================*/

    // Multiplication operator (float)
    Matrix4f Matrix4f::operator * (const float RHS) {

        return (Matrix4f (this -> _value [0] * RHS,
                          this -> _value [1] * RHS,
                          this -> _value [2] * RHS,
                          this -> _value [3] * RHS));
    }

/*============================================================================================================*/
/*------RELATIONAL OPERATORS----------------------------------------------------------------------------------*/
/*============================================================================================================*/

    // Equal to operator
    bool Matrix4f::operator == (const Matrix4f& RHS) {

        Matrix4f rhs = RHS;

        return (this -> _value [0] == rhs [0] &&
                this -> _value [1] == rhs [1] &&
                this -> _value [2] == rhs [2] &&
                this -> _value [3] == rhs [3]);
    }

/*============================================================================================================*/

    // Not equal to operator
    bool Matrix4f::operator != (const Matrix4f& RHS) {

        Matrix4f rhs = RHS;

        return (this -> _value [0] != rhs [0] ||
                this -> _value [1] != rhs [1] ||
                this -> _value [2] != rhs [2] ||
                this -> _value [3] != rhs [3]);
    }

/*============================================================================================================*/
/*------COMPOUND ASSIGNMENT OPERATORS-------------------------------------------------------------------------*/
/*============================================================================================================*/

    // Addition assignment operator (matrix)
    Matrix4f& Matrix4f::operator += (const Matrix4f& RHS) {

        return (*this = *this + RHS);
    }

/*============================================================================================================*/

    // Addition assignment operator (vector)
    Matrix4f& Matrix4f::operator += (const Vector4f& RHS) {

        return (*this = *this + RHS);
    }

/*============================================================================================================*/

    // Addition assignment operator (float)
    Matrix4f& Matrix4f::operator += (const float RHS) {

        return (*this = *this + RHS);
    }

/*============================================================================================================*/

    // Subtraction assignment operator (matrix)
    Matrix4f& Matrix4f::operator -= (const Matrix4f& RHS) {

        return (*this = *this - RHS);
    }

/*============================================================================================================*/

    // Subtraction assignment operator (vector)
    Matrix4f& Matrix4f::operator -= (const Vector4f& RHS) {

        return (*this = *this - RHS);
    }

/*============================================================================================================*/

    // Subtraction assignment operator (float)
    Matrix4f& Matrix4f::operator -= (const float RHS) {

        return (*this = *this - RHS);
    }

/*============================================================================================================*/

    // Multiplication assignment operator (matrix)
    Matrix4f& Matrix4f::operator *= (const Matrix4f& RHS) {

        return (*this = *this * RHS);
    }

/*============================================================================================================*/

    // Multiplication assignment operator (float)
    Matrix4f& Matrix4f::operator *= (const float RHS) {

        return (*this = *this * RHS);
    }

/*============================================================================================================*/
/*------MEMBER OPERATORS--------------------------------------------------------------------------------------*/
/*============================================================================================================*/

    // Function call operator
    Vector4f& Matrix4f::operator [] (int Column) {

        assert (Column > -1 && Column < 4);

        switch (Column) {

            case 0:
                return (this -> _value [0]);

            case 1:
                return (this -> _value [1]);

            case 2:
                return (this -> _value [2]);

            case 3:
                return (this -> _value [3]);

            default:
                return (this -> _value [0]);
        }
    }
}
