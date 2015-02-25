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

#include <Renegade/Math/Vector4f/Vector4f.hpp>
#include <string>

// The Renegade Namespace
namespace rge {

    // The Matrix4f class
    class Matrix4f {
    public:

        // Constructor / Destructor
        Matrix4f ();
        Matrix4f (float Value);
        Matrix4f (float X0, float Y0, float Z0, float W0,
                  float X1, float Y1, float Z1, float W1,
                  float X2, float Y2, float Z2, float W2,
                  float X3, float Y3, float Z3, float W3);
        Matrix4f (const Vector4f& Vec01, const Vector4f& Vec02, const Vector4f& Vec03, const Vector4f& Vec04);

        // Functions
        std::string ToString    ();

        // Static functions
        static float Determinant  (const Matrix4f& Matrix);
        static Matrix4f Identity  ();
        static Matrix4f Inverse   (const Matrix4f& Matrix);
        static Matrix4f Translate (const Vector3f& Position);
        static Matrix4f Rotate    (const Vector3f& Rotation);
        static Matrix4f Scale     (const Vector3f& Scale);

        // Arithmetic operators
        Matrix4f operator + (const Matrix4f& RHS);
        Matrix4f operator + (const Vector4f& RHS);
        Matrix4f operator + (const float RHS);
        Matrix4f operator++ ();
        Matrix4f operator++ (int);
        Matrix4f operator - (const Matrix4f& RHS);
        Matrix4f operator - (const Vector4f& RHS);
        Matrix4f operator - (const float RHS);
        Matrix4f operator-- ();
        Matrix4f operator-- (int);
        Matrix4f operator * (const Matrix4f& RHS);
        Vector4f operator * (const Vector4f& RHS);
        Matrix4f operator * (const float RHS);

        // Relational operators
        bool operator == (const Matrix4f& RHS);
        bool operator != (const Matrix4f& RHS);

        // Compound assignment operators
        Matrix4f& operator += (const Matrix4f& RHS);
        Matrix4f& operator += (const Vector4f& RHS);
        Matrix4f& operator += (const float RHS);
        Matrix4f& operator -= (const Matrix4f& RHS);
        Matrix4f& operator -= (const Vector4f& RHS);
        Matrix4f& operator -= (const float RHS);
        Matrix4f& operator *= (const Matrix4f& RHS);
        Matrix4f& operator *= (const float RHS);

        // Member operators
        Vector4f& operator [] (int Column);

    private:

        // Variables
        Vector4f _value [4];
    };
}
