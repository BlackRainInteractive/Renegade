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

    // Forward declare vector classes
    class Vector2f;
    class Vector3f;

    // The Vector4f implementation class
    class Vector4f {
    public:

        // Constructor / Destructor
        Vector4f ();
        Vector4f (float Value);
        Vector4f (float XAxis, float YAxis, float ZAxis, float WAxis);
        Vector4f (const Vector2f& Vector);
        Vector4f (const Vector3f& Vector);

        // Functions
        std::string ToString ();

        // Static Functions
        static float Dot        (const Vector4f& LHS, const Vector4f& RHS);
        static float Distance   (const Vector4f& Start, const Vector4f& End);
        static Vector4f Lerp    (const Vector4f& Start, const Vector4f& End, float Percentage);

        // Arithmetic operators
        Vector4f operator + (const Vector4f& RHS);
        Vector4f operator + (const float RHS);
        Vector4f operator + ();
        Vector4f operator++ ();
        Vector4f operator++ (int);
        Vector4f operator - (const Vector4f& RHS);
        Vector4f operator - (const float RHS);
        Vector4f operator - ();
        Vector4f operator-- ();
        Vector4f operator-- (int);
        Vector4f operator * (const Vector4f& RHS);
        Vector4f operator * (const float RHS);
        Vector4f operator / (const Vector4f& RHS);
        Vector4f operator / (const float RHS);

        // Relational operators
        bool operator == (const Vector4f& RHS);
        bool operator != (const Vector4f& RHS);

        // Compound assignment operators
        Vector4f& operator += (const Vector4f& RHS);
        Vector4f& operator += (const float RHS);
        Vector4f& operator -= (const Vector4f& RHS);
        Vector4f& operator -= (const float RHS);
        Vector4f& operator *= (const Vector4f& RHS);
        Vector4f& operator *= (const float RHS);
        Vector4f& operator /= (const Vector4f& RHS);
        Vector4f& operator /= (const float RHS);

        // Member operators
        float& operator [] (int Index);

        // Variables
        float x, y, z, w;
    };
}
