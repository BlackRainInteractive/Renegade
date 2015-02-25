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

#include <Renegade/Math/Vector3f/Vector3f.hpp>
#include <Renegade/Math/Mathf/Mathf.hpp>
#include <cmath>

// The Renegade namespace
namespace rge {

/*============================================================================================================*/
/*------STATIC FUNCTIONS--------------------------------------------------------------------------------------*/
/*============================================================================================================*/

    // Cross product of two vectors
    Vector3f Vector3f::Cross (const Vector3f& LHS, const Vector3f& RHS) {

        return (Vector3f (LHS.y * RHS.z - RHS.y * LHS.z,
                          LHS.z * RHS.x - RHS.z * LHS.x,
                          LHS.x * RHS.y - RHS.x * LHS.y));
    }

/*============================================================================================================*/

    // Dot product of two vectors
    float Vector3f::Dot (const Vector3f& LHS, const Vector3f& RHS) {

        float xAxis = LHS.x * RHS.x,
              yAxis = LHS.y * RHS.y,
              zAxis = LHS.z * RHS.z;

        return (xAxis + yAxis + zAxis);
    }

/*============================================================================================================*/

    // Distance between two vectors
    float Vector3f::Distance (const Vector3f& Start, const Vector3f& End) {

        float xAxis = std::pow ((End.x - Start.x), 2),
              yAxis = std::pow ((End.y - Start.y), 2),
              zAxis = std::pow ((End.z - Start.z), 2);

        return (std::sqrt (xAxis + yAxis + zAxis));
    }

/*============================================================================================================*/

    // Lerp between two vectors
    Vector3f Vector3f::Lerp (const Vector3f& Start, const Vector3f& End, float Percentage) {

        return (Vector3f (Start.x + (End.x - Start.x) * Mathf::Clamp (0, 1, Percentage),
                          Start.y + (End.y - Start.y) * Mathf::Clamp (0, 1, Percentage),
                          Start.z + (End.z - Start.z) * Mathf::Clamp (0, 1, Percentage)));
    }
}
