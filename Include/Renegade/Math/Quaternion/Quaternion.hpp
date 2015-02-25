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

    // Forward declare vector3, and matrix3 classes
    class Vector3f;
    class Matrix4f;

    // The quaternion class
    class Quaternion {
    public:

        // Constructor / Destructor
        Quaternion ();
        Quaternion (float X, float Y, float Z, float W);
        Quaternion (const Vector3f& Vector);

        // Functions
        // TODO: Implement quaternion class
        std::string ToString ();

        // Arithmetic operators
        Quaternion operator * (const Quaternion& RHS);

        // Relational operators
        bool operator == (const Quaternion& RHS);
        bool operator != (const Quaternion& RHS);

        // Compound assignment operators
        Quaternion& operator *= (const Quaternion& RHS);

        // Member operators
        float& operator [] (int Index);

        // Static functions
        static Quaternion Inverse (const Quaternion& Quaternion);
        static Vector3f ToVector3 (const Quaternion& Quaternion);
        static Matrix4f ToMatrix4 (const Quaternion& Quaternion);

        // Variables
        float x, y, z, w;
    };
}
