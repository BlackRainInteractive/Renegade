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

#include <string>

// The Renegade namespace
namespace rge {

    // Forward declare classes
    class Vector2f;
    class Vector4f;
    class Matrix4f;

    // The Vector3f class
    class Vector3f {
    public:

        // Constructor / Destructor
        Vector3f ();
        Vector3f (float Value);
        Vector3f (float XAxis, float YAxis, float ZAxis);
        Vector3f (const Vector2f& Vector);
        Vector3f (const Vector4f& Vector);

        // Functions
        std::string ToString ();

        // Static Functions
        static Vector3f Cross  ( const Vector3f& LHS, const Vector3f& RHS);
        static float Dot        (const Vector3f& LHS, const Vector3f& RHS);
        static float Distance   (const Vector3f& Start, const Vector3f& End);
        static Vector3f Lerp    (const Vector3f& Start, const Vector3f& End, float Percentage);

        // Arithmetic operators
        Vector3f operator + (const Vector3f& RHS);
        Vector3f operator + (const float RHS);
        Vector3f operator + ();
        Vector3f operator++ ();
        Vector3f operator++ (int);
        Vector3f operator - (const Vector3f& RHS);
        Vector3f operator - (const float RHS);
        Vector3f operator - ();
        Vector3f operator-- ();
        Vector3f operator-- (int);
        Vector3f operator * (const Matrix4f& RHS);
        Vector3f operator * (const Vector3f& RHS);
        Vector3f operator * (const float RHS);
        Vector3f operator / (const Vector3f& RHS);
        Vector3f operator / (const float RHS);

        // Relational operators
        bool operator == (const Vector3f& RHS);
        bool operator != (const Vector3f& RHS);

        // Compound assignment operators
        Vector3f& operator += (const Vector3f& RHS);
        Vector3f& operator += (const float RHS);
        Vector3f& operator -= (const Vector3f& RHS);
        Vector3f& operator -= (const float RHS);
        Vector3f& operator *= (const Matrix4f& RHS);
        Vector3f& operator *= (const Vector3f& RHS);
        Vector3f& operator *= (const float RHS);
        Vector3f& operator /= (const Vector3f& RHS);
        Vector3f& operator /= (const float RHS);

        // Member operators
        float& operator [] (int Index);

        // Variables
        float x, y, z;
    };
}
