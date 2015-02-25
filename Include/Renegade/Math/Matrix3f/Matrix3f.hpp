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

#include <Renegade/Math/Vector3f/Vector3f.hpp>
#include <string>

// The Renegade Namespace
namespace rge {

    // The Matrix3f class
    class Matrix3f {
    public:

        // Constructor / Destructor
        Matrix3f ();
        Matrix3f (float Value);
        Matrix3f (float X0, float Y0, float Z0,
                  float X1, float Y1, float Z1,
                  float X2, float Y2, float Z2);
        Matrix3f (const Vector3f& Vec01, const Vector3f& Vec02, const Vector3f& Vec03);

        // Functions
        std::string ToString    ();

        // Static functions
        static float Determinant  (const Matrix3f& Matrix);
        static Matrix3f Identity  ();
        static Matrix3f Inverse   (const Matrix3f& Matrix);
        static Matrix3f Translate (const Vector2f& Position);
        static Matrix3f Rotate    (const float Rotation);
        static Matrix3f Scale     (const Vector2f& Scale);

        // Arithmetic operators
        Matrix3f operator + (const Matrix3f& RHS);
        Matrix3f operator + (const Vector3f& RHS);
        Matrix3f operator + (const float RHS);
        Matrix3f operator++ ();
        Matrix3f operator++ (int);
        Matrix3f operator - (const Matrix3f& RHS);
        Matrix3f operator - (const Vector3f& RHS);
        Matrix3f operator - (const float RHS);
        Matrix3f operator-- ();
        Matrix3f operator-- (int);
        Matrix3f operator * (const Matrix3f& RHS);
        Vector3f operator * (const Vector3f& RHS);
        Matrix3f operator * (const float RHS);

        // Relational operators
        bool operator == (const Matrix3f& RHS);
        bool operator != (const Matrix3f& RHS);

        // Compound assignment operators
        Matrix3f& operator += (const Matrix3f& RHS);
        Matrix3f& operator += (const Vector3f& RHS);
        Matrix3f& operator += (const float RHS);
        Matrix3f& operator -= (const Matrix3f& RHS);
        Matrix3f& operator -= (const Vector3f& RHS);
        Matrix3f& operator -= (const float RHS);
        Matrix3f& operator *= (const Matrix3f& RHS);
        Matrix3f& operator *= (const float RHS);

        // Member operators
        Vector3f& operator [] (int Column);

    private:

        // Variables
        Vector3f _value [3];
    };
}
