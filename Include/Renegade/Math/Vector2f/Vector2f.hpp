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
    class Vector3f;
    class Vector4f;
    class Matrix3f;

    // The Vector2f class
    class Vector2f {
    public:

        // Constructor / Destructor
        Vector2f ();
        Vector2f (float Value);
        Vector2f (float XAxis, float YAxis);
        Vector2f (const Vector3f& Vector);
        Vector2f (const Vector4f& Vector);

        // Functions
        std::string ToString ();

        // Static Functions
        static float Dot        (const Vector2f& LHS, const Vector2f& RHS);
        static float Distance   (const Vector2f& Start, const Vector2f& End);
        static Vector2f Lerp    (const Vector2f& Start, const Vector2f& End, float Percentage);

        // Arithmetic operators
        Vector2f operator + (const Vector2f& RHS);
        Vector2f operator + (const float RHS);
        Vector2f operator + ();
        Vector2f operator++ ();
        Vector2f operator++ (int);
        Vector2f operator - (const Vector2f& RHS);
        Vector2f operator - (const float RHS);
        Vector2f operator - ();
        Vector2f operator-- ();
        Vector2f operator-- (int);
        Vector2f operator * (const Matrix3f& RHS);
        Vector2f operator * (const Vector2f& RHS);
        Vector2f operator * (const float RHS);
        Vector2f operator / (const Vector2f& RHS);
        Vector2f operator / (const float RHS);

        // Relational operators
        bool operator == (const Vector2f& RHS);
        bool operator != (const Vector2f& RHS);

        // Compound assignment operators
        Vector2f& operator += (const Vector2f& RHS);
        Vector2f& operator += (const float RHS);
        Vector2f& operator -= (const Vector2f& RHS);
        Vector2f& operator -= (const float RHS);
        Vector2f& operator *= (const Matrix3f& RHS);
        Vector2f& operator *= (const Vector2f& RHS);
        Vector2f& operator *= (const float RHS);
        Vector2f& operator /= (const Vector2f& RHS);
        Vector2f& operator /= (const float RHS);

        // Member operators
        float& operator [] (int Index);

        // Variables
        float x, y;
    };
}
