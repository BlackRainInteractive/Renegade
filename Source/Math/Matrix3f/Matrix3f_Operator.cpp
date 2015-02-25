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

#include <Renegade/Math/Matrix3f/Matrix3f.hpp>
#include <cassert>

// The Renegade Namespace
namespace rge {

/*============================================================================================================*/
/*------ARITHMETIC OPERATORS----------------------------------------------------------------------------------*/
/*============================================================================================================*/

    // Addition operator (matrix)
    Matrix3f Matrix3f::operator + (const Matrix3f& RHS) {

        return (Matrix3f (this -> _value [0] + RHS._value [0],
                          this -> _value [1] + RHS._value [1],
                          this -> _value [2] + RHS._value [2]));
    }

/*============================================================================================================*/

    // Addition operator (vector)
    Matrix3f Matrix3f::operator + (const Vector3f& RHS) {

        return (Matrix3f (this -> _value [0] + RHS,
                          this -> _value [1] + RHS,
                          this -> _value [2] + RHS));
    }

/*============================================================================================================*/

    // Addition operator (float)
    Matrix3f Matrix3f::operator + (const float RHS) {

        return (Matrix3f (this -> _value [0] + RHS,
                          this -> _value [1] + RHS,
                          this -> _value [2] + RHS));
    }

/*============================================================================================================*/

    // Increment operator (prefix)
    Matrix3f Matrix3f::operator ++ () {

        return (Matrix3f (++this -> _value [0],
                          ++this -> _value [1],
                          ++this -> _value [2]));
    }

/*============================================================================================================*/

    // Increment operator (postfix)
    Matrix3f Matrix3f::operator ++ (int) {

        return (Matrix3f (this -> _value [0]++,
                          this -> _value [1]++,
                          this -> _value [2]++));
    }

/*============================================================================================================*/

    // Subtraction operator (matrix)
    Matrix3f Matrix3f::operator - (const Matrix3f& RHS) {

        return (Matrix3f (this -> _value [0] - RHS._value [0],
                          this -> _value [1] - RHS._value [1],
                          this -> _value [2] - RHS._value [2]));
    }

/*============================================================================================================*/

    // Subtraction operator (vector)
    Matrix3f Matrix3f::operator - (const Vector3f& RHS) {

        return (Matrix3f (this -> _value [0] - RHS,
                          this -> _value [1] - RHS,
                          this -> _value [2] - RHS));
    }

/*============================================================================================================*/

    // Subtraction operator (float)
    Matrix3f Matrix3f::operator - (const float RHS) {

        return (Matrix3f (this -> _value [0] - RHS,
                          this -> _value [1] - RHS,
                          this -> _value [2] - RHS));
    }

/*============================================================================================================*/

    // Decrement operator (prefix)
    Matrix3f Matrix3f::operator -- () {

        return (Matrix3f (--this -> _value [0],
                          --this -> _value [1],
                          --this -> _value [2]));
    }

/*============================================================================================================*/

    // Decrement operator (postfix)
    Matrix3f Matrix3f::operator -- (int) {

        return (Matrix3f (this -> _value [0]--,
                          this -> _value [1]--,
                          this -> _value [2]--));
    }

/*============================================================================================================*/

    // Multiplication operator (matrix)
    Matrix3f Matrix3f::operator * (const Matrix3f& RHS) {

        Matrix3f returnMatrix;
        Matrix3f rhs = RHS;

        for (int row = 0; row < 3; ++row) {

            for (int col = 0; col < 3; ++col) {

                for (int inner = 0; inner < 3; ++inner)
                    returnMatrix [row][col] += (this -> _value [row][inner] * rhs [inner][col]);
            }
        }

        return (returnMatrix);
    }

/*============================================================================================================*/

    // Multiplication operator (vector)
    Vector3f Matrix3f::operator * (const Vector3f& RHS) {

        return (Vector3f ((this -> _value [0][0] * RHS.x) + (this -> _value [1][0] * RHS.y) + (this -> _value [2][0] * RHS.z),
                          (this -> _value [0][1] * RHS.x) + (this -> _value [1][1] * RHS.y) + (this -> _value [2][1] * RHS.z),
                          (this -> _value [0][2] * RHS.x) + (this -> _value [1][2] * RHS.y) + (this -> _value [2][2] * RHS.z)));
    }

/*============================================================================================================*/

    // Multiplication operator (float)
    Matrix3f Matrix3f::operator * (const float RHS) {

        return (Matrix3f (this -> _value [0] * RHS,
                          this -> _value [1] * RHS,
                          this -> _value [2] * RHS));
    }

/*============================================================================================================*/
/*------RELATIONAL OPERATORS----------------------------------------------------------------------------------*/
/*============================================================================================================*/

    // Equal to operator
    bool Matrix3f::operator == (const Matrix3f& RHS) {

        Matrix3f rhs = RHS;

        return (this -> _value [0] == rhs [0] &&
                this -> _value [1] == rhs [1] &&
                this -> _value [2] == rhs [2]);
    }

/*============================================================================================================*/

    // Not equal to operator
    bool Matrix3f::operator != (const Matrix3f& RHS) {

        Matrix3f rhs = RHS;

        return (this -> _value [0] != rhs [0] ||
                this -> _value [1] != rhs [1] ||
                this -> _value [2] != rhs [2]);
    }

/*============================================================================================================*/
/*------COMPOUND ASSIGNMENT OPERATORS-------------------------------------------------------------------------*/
/*============================================================================================================*/

    // Addition assignment operator (matrix)
    Matrix3f& Matrix3f::operator += (const Matrix3f& RHS) {

        return (*this = *this + RHS);
    }

/*============================================================================================================*/

    // Addition assignment operator (vector)
    Matrix3f& Matrix3f::operator += (const Vector3f& RHS) {

        return (*this = *this + RHS);
    }

/*============================================================================================================*/

    // Addition assignment operator (float)
    Matrix3f& Matrix3f::operator += (const float RHS) {

        return (*this = *this + RHS);
    }

/*============================================================================================================*/

    // Subtraction assignment operator (matrix)
    Matrix3f& Matrix3f::operator -= (const Matrix3f& RHS) {

        return (*this = *this - RHS);
    }

/*============================================================================================================*/

    // Subtraction assignment operator (vector)
    Matrix3f& Matrix3f::operator -= (const Vector3f& RHS) {

        return (*this = *this - RHS);
    }

/*============================================================================================================*/

    // Subtraction assignment operator (float)
    Matrix3f& Matrix3f::operator -= (const float RHS) {

        return (*this = *this - RHS);
    }

/*============================================================================================================*/

    // Multiplication assignment operator (matrix)
    Matrix3f& Matrix3f::operator *= (const Matrix3f& RHS) {

        return (*this = *this * RHS);
    }

/*============================================================================================================*/

    // Multiplication assignment operator (float)
    Matrix3f& Matrix3f::operator *= (const float RHS) {

        return (*this = *this * RHS);
    }

/*============================================================================================================*/
/*------MEMBER OPERATORS--------------------------------------------------------------------------------------*/
/*============================================================================================================*/

    // Function call operator
    Vector3f& Matrix3f::operator [] (int Column) {

        assert (Column > -1 && Column < 3);

        switch (Column) {

            case 0:
                return (this -> _value [0]);

            case 1:
                return (this -> _value [1]);

            case 2:
                return (this -> _value [2]);

            default:
                return (this -> _value [0]);
        }
    }
}
