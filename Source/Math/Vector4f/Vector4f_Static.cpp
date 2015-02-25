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

#include <Renegade/Math/Vector4f/Vector4f.hpp>
#include <Renegade/Math/Mathf/Mathf.hpp>
#include <cmath>

// The Renegade namespace
namespace rge {

/*============================================================================================================*/
/*------STATIC FUNCTIONS--------------------------------------------------------------------------------------*/
/*============================================================================================================*/

    // Dot product of two vectors
    float Vector4f::Dot (const Vector4f& LHS, const Vector4f& RHS) {

        float xAxis = LHS.x * RHS.x,
              yAxis = LHS.y * RHS.y,
              zAxis = LHS.z * RHS.z,
              wAxis = LHS.w * RHS.w;

        return (xAxis + yAxis + zAxis + wAxis);
    }

/*============================================================================================================*/

    // Distance between two vectors
    float Vector4f::Distance (const Vector4f& Start, const Vector4f& End) {

        float xAxis = std::pow ((End.x - Start.x), 2),
              yAxis = std::pow ((End.y - Start.y), 2),
              zAxis = std::pow ((End.z - Start.z), 2),
              wAxis = std::pow ((End.w - Start.w), 2);

        return (std::sqrt (xAxis + yAxis + zAxis + wAxis));
    }

/*============================================================================================================*/

    // Lerp between two vectors
    Vector4f Vector4f::Lerp (const Vector4f& Start, const Vector4f& End, float Percentage) {

        return (Vector4f (Start.x + (End.x - Start.x) * Mathf::Clamp (0, 1, Percentage),
                          Start.y + (End.y - Start.y) * Mathf::Clamp (0, 1, Percentage),
                          Start.z + (End.z - Start.z) * Mathf::Clamp (0, 1, Percentage),
                          Start.w + (End.w - Start.w) * Mathf::Clamp (0, 1, Percentage)));
    }
}
