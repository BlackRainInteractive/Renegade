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
#include <Renegade/Math/Mathf/Mathf.hpp>
#include <Renegade/Math/Vector3f/Vector3f.hpp>
#include <cmath>

// The Renegade Namespace
namespace rge {

/*============================================================================================================*/
/*------STATIC FUNCTIONS--------------------------------------------------------------------------------------*/
/*============================================================================================================*/

    // Get the determinant of the matrix
    float Matrix4f::Determinant (const Matrix4f& Matrix) {

        Matrix4f m = Matrix;

        return (m[0][3] * m[1][2] * m[2][1] * m[3][0] - m[0][2] * m[1][3] * m[2][1] * m[3][0] - m[0][3] * m[1][1] * m[2][2] * m[3][0] + m[0][1] * m[1][3] * m[2][2] * m[3][0] +
                m[0][2] * m[1][1] * m[2][3] * m[3][0] - m[0][1] * m[1][2] * m[2][3] * m[3][0] - m[0][3] * m[1][2] * m[2][0] * m[3][1] + m[0][2] * m[1][3] * m[2][0] * m[3][1] +
                m[0][3] * m[1][0] * m[2][2] * m[3][1] - m[0][0] * m[1][3] * m[2][2] * m[3][1] - m[0][2] * m[1][0] * m[2][3] * m[3][1] + m[0][0] * m[1][2] * m[2][3] * m[3][1] +
                m[0][3] * m[1][1] * m[2][0] * m[3][2] - m[0][1] * m[1][3] * m[2][0] * m[3][2] - m[0][3] * m[1][0] * m[2][1] * m[3][2] + m[0][0] * m[1][3] * m[2][1] * m[3][2] +
                m[0][1] * m[1][0] * m[2][3] * m[3][2] - m[0][0] * m[1][1] * m[2][3] * m[3][2] - m[0][2] * m[1][1] * m[2][0] * m[3][3] + m[0][1] * m[1][2] * m[2][0] * m[3][3] +
                m[0][2] * m[1][0] * m[2][1] * m[3][3] - m[0][0] * m[1][2] * m[2][1] * m[3][3] - m[0][1] * m[1][0] * m[2][2] * m[3][3] + m[0][0] * m[1][1] * m[2][2] * m[3][3]);
    }

/*============================================================================================================*/

    // Get an identity matrix
    Matrix4f Matrix4f::Identity () {

        return (Matrix4f (1, 0, 0, 0,
                          0, 1, 0, 0,
                          0, 0, 1, 0,
                          0, 0, 0, 1));
    }

/*============================================================================================================*/

    // Get the inverse of a matrix
    Matrix4f Matrix4f::Inverse (const Matrix4f& Matrix) {

        Matrix4f m  = Matrix;
        float det   = (1.0f / Matrix4f::Determinant (Matrix));

        return (Matrix4f ((m[1][2] * m[2][3] * m[3][1] - m[1][3] * m[2][2] * m[3][1] + m[1][3] * m[2][1] * m[3][2] - m[1][1] * m[2][3] * m[3][2] - m[1][2] * m[2][1] * m[3][3] + m[1][1] * m[2][2] * m[3][3]) * det,
                          (m[0][3] * m[2][2] * m[3][1] - m[0][2] * m[2][3] * m[3][1] - m[0][3] * m[2][1] * m[3][2] + m[0][1] * m[2][3] * m[3][2] + m[0][2] * m[2][1] * m[3][3] - m[0][1] * m[2][2] * m[3][3]) * det,
                          (m[0][2] * m[1][3] * m[3][1] - m[0][3] * m[1][2] * m[3][1] + m[0][3] * m[1][1] * m[3][2] - m[0][1] * m[1][3] * m[3][2] - m[0][2] * m[1][1] * m[3][3] + m[0][1] * m[1][2] * m[3][3]) * det,
                          (m[0][3] * m[1][2] * m[2][1] - m[0][2] * m[1][3] * m[2][1] - m[0][3] * m[1][1] * m[2][2] + m[0][1] * m[1][3] * m[2][2] + m[0][2] * m[1][1] * m[2][3] - m[0][1] * m[1][2] * m[2][3]) * det,
                          (m[1][3] * m[2][2] * m[3][1] - m[1][2] * m[2][3] * m[3][1] - m[1][3] * m[2][0] * m[3][2] + m[1][0] * m[2][3] * m[3][2] + m[1][2] * m[2][0] * m[3][3] - m[1][0] * m[2][2] * m[3][3]) * det,
                          (m[0][2] * m[2][3] * m[3][1] - m[0][3] * m[2][2] * m[3][1] + m[0][3] * m[2][0] * m[3][2] - m[0][0] * m[2][3] * m[3][2] - m[0][2] * m[2][0] * m[3][3] + m[0][0] * m[2][2] * m[3][3]) * det,
                          (m[0][3] * m[1][2] * m[3][1] - m[0][2] * m[1][3] * m[3][1] - m[0][3] * m[1][0] * m[3][2] + m[0][0] * m[1][3] * m[3][2] + m[0][2] * m[1][0] * m[3][3] - m[0][0] * m[1][2] * m[3][3]) * det,
                          (m[0][2] * m[1][3] * m[2][0] - m[0][3] * m[1][2] * m[2][0] + m[0][3] * m[1][0] * m[2][2] - m[0][0] * m[1][3] * m[2][2] - m[0][2] * m[1][0] * m[2][3] + m[0][0] * m[1][2] * m[2][3]) * det,
                          (m[1][1] * m[2][3] * m[3][1] - m[1][3] * m[2][1] * m[3][1] + m[1][3] * m[2][0] * m[3][1] - m[1][0] * m[2][3] * m[3][1] - m[1][1] * m[2][0] * m[3][3] + m[1][0] * m[2][1] * m[3][3]) * det,
                          (m[0][3] * m[2][1] * m[3][1] - m[0][1] * m[2][3] * m[3][1] - m[0][3] * m[2][0] * m[3][1] + m[0][0] * m[2][3] * m[3][1] + m[0][1] * m[2][0] * m[3][3] - m[0][0] * m[2][1] * m[3][3]) * det,
                          (m[0][1] * m[1][3] * m[3][1] - m[0][3] * m[1][1] * m[3][1] + m[0][3] * m[1][0] * m[3][1] - m[0][0] * m[1][3] * m[3][1] - m[0][1] * m[1][0] * m[3][3] + m[0][0] * m[1][1] * m[3][3]) * det,
                          (m[0][3] * m[1][1] * m[2][0] - m[0][1] * m[1][3] * m[2][0] - m[0][3] * m[1][0] * m[2][1] + m[0][0] * m[1][3] * m[2][1] + m[0][1] * m[1][0] * m[2][3] - m[0][0] * m[1][1] * m[2][3]) * det,
                          (m[1][2] * m[2][1] * m[3][1] - m[1][1] * m[2][2] * m[3][1] - m[1][2] * m[2][0] * m[3][1] + m[1][0] * m[2][2] * m[3][1] + m[1][1] * m[2][0] * m[3][2] - m[1][0] * m[2][1] * m[3][2]) * det,
                          (m[0][1] * m[2][2] * m[3][1] - m[0][2] * m[2][1] * m[3][1] + m[0][2] * m[2][0] * m[3][1] - m[0][0] * m[2][2] * m[3][1] - m[0][1] * m[2][0] * m[3][2] + m[0][0] * m[2][1] * m[3][2]) * det,
                          (m[0][2] * m[1][1] * m[3][1] - m[0][1] * m[1][2] * m[3][1] - m[0][2] * m[1][0] * m[3][1] + m[0][0] * m[1][2] * m[3][1] + m[0][1] * m[1][0] * m[3][2] - m[0][0] * m[1][1] * m[3][2]) * det,
                          (m[0][1] * m[1][2] * m[2][0] - m[0][2] * m[1][1] * m[2][0] + m[0][2] * m[1][0] * m[2][1] - m[0][0] * m[1][2] * m[2][1] - m[0][1] * m[1][0] * m[2][2] + m[0][0] * m[1][1] * m[2][2]) * det));
    }

/*============================================================================================================*/

    // Return translation matrix
    Matrix4f Matrix4f::Translate (const Vector3f& Position) {

        return (Matrix4f (1, 0, 0, Position.x,
                          0, 1, 0, Position.y,
                          0, 0, 1, Position.z,
                          0, 0, 0, 1));
    }

/*============================================================================================================*/

    // Return rotation matrix (vector)
    Matrix4f Matrix4f::Rotate (const Vector3f& Rotation) {

        // Convert rotation to radians
        Vector3f rot (Mathf::ToRadians (Rotation.x),
                      Mathf::ToRadians (Rotation.y),
                      Mathf::ToRadians (Rotation.z));

        float xSin = std::sin (rot.x), xCos = std::cos (rot.x),
              ySin = std::sin (rot.y), yCos = std::cos (rot.y),
              zSin = std::sin (rot.z), zCos = std::cos (rot.z);

        // Transform x-axis
        Matrix4f rotX (1, 0, 0, 0,
                       0, xCos, -xSin, 0,
                       0, xSin,  xCos, 0,
                       0, 0, 0, 1);

        // Transform y-axis
        Matrix4f rotY (yCos, 0, ySin, 0,
                       0, 1, 0, 0,
                      -ySin, 0, yCos, 0,
                       0, 0, 0, 1);

        // Transform z-axis
        Matrix4f rotZ (zCos, -zSin, 0, 0,
                       zSin,  zCos, 0, 0,
                       0, 0, 1, 0,
                       0, 0, 0, 1);

        return (rotZ * rotY * rotX);
    }

/*============================================================================================================*/

    // Return scale matrix
    Matrix4f Matrix4f::Scale (const Vector3f& Scale) {

        return (Matrix4f (Scale.x, 0, 0, 0,
                          0, Scale.y, 0, 0,
                          0, 0, Scale.z, 0,
                          0, 0, 0, 1));
    }
}
