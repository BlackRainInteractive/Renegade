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
#include <Renegade/Math/Vector2f/Vector2f.hpp>
#include <Renegade/Math/Mathf/Mathf.hpp>
#include <cmath>

// The Renegade Namespace
namespace rge {

/*============================================================================================================*/
/*------STATIC FUNCTIONS--------------------------------------------------------------------------------------*/
/*============================================================================================================*/

    // Get the determinant of the matrix
    float Matrix3f::Determinant (const Matrix3f& Matrix) {

        Matrix3f m = Matrix;

        return (m[0][0] * m[1][1] * m[2][2] +
                m[0][1] * m[1][2] * m[2][0] +
                m[0][2] * m[1][0] * m[2][1] -
                m[0][0] * m[1][2] * m[2][1] -
                m[0][1] * m[1][0] * m[2][2] -
                m[0][2] * m[1][1] * m[2][0]);
    }

/*============================================================================================================*/

    // Get an identity matrix
    Matrix3f Matrix3f::Identity () {

        return (Matrix3f (1, 0, 0,
                          0, 1, 0,
                          0, 0, 1));
    }

/*============================================================================================================*/

    // Get the inverse of a matrix
    Matrix3f Matrix3f::Inverse (const Matrix3f& Matrix) {

        Matrix3f m  = Matrix;
        float det   = (1.0f / Matrix3f::Determinant (Matrix));

        return (Matrix3f ((m[1][1] * m[2][2] - m[1][2] * m[2][1]) * det,
                          (m[0][2] * m[2][1] - m[0][1] * m[2][2]) * det,
                          (m[0][1] * m[1][2] - m[0][2] * m[1][1]) * det,
                          (m[1][2] * m[2][0] - m[1][0] * m[2][2]) * det,
                          (m[0][0] * m[2][2] - m[0][2] * m[2][0]) * det,
                          (m[0][2] * m[1][0] - m[0][0] * m[1][2]) * det,
                          (m[1][0] * m[2][1] - m[1][1] * m[2][0]) * det,
                          (m[0][1] * m[2][0] - m[0][0] * m[2][1]) * det,
                          (m[0][0] * m[1][1] - m[0][1] * m[1][0]) * det));
    }

/*============================================================================================================*/

    // Return translation matrix
    Matrix3f Matrix3f::Translate (const Vector2f& Position) {

        return (Matrix3f (1, 0, Position.x,
                          0, 1, Position.y,
                          0, 0, 1));
    }

/*============================================================================================================*/

    // Return rotation matrix
    Matrix3f Matrix3f::Rotate (const float Rotation) {

        // Convert rotation to radians
        float rot (Mathf::ToRadians (Rotation));
        float zSin = std::sin (rot), zCos = std::cos (rot);

        // Transform z-axis
        return (Matrix3f (zCos, -zSin, 0,
                          zSin,  zCos, 0,
                          0, 0, 1));
    }

/*============================================================================================================*/

    // Return scale matrix
    Matrix3f Matrix3f::Scale (const Vector2f& Scale) {

        return (Matrix3f (Scale.x, 0, 0,
                          0, Scale.y, 0,
                          0, 0, 1));
    }
}
