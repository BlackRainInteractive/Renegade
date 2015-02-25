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
#include <Renegade/Math/Vector2f/Vector2f.hpp>
#include <Renegade/Math/Vector4f/Vector4f.hpp>

// The Renegade namespace
namespace rge {

/*============================================================================================================*/
/*------CONSTRUCTOR-------------------------------------------------------------------------------------------*/
/*============================================================================================================*/

    // The default constructor
    Vector3f::Vector3f () : x (0),
                            y (0),
                            z (0) {
    }

/*============================================================================================================*/

    // Construct from single value
    Vector3f::Vector3f (float Value) : x (Value),
                                       y (Value),
                                       z (Value) {
    }

/*============================================================================================================*/

    // Construct from x and y axis
    Vector3f::Vector3f (float XAxis, float YAxis, float ZAxis) : x (XAxis),
                                                                 y (YAxis),
                                                                 z (ZAxis) {
    }

/*============================================================================================================*/

    // Construct from Vector2f
    Vector3f::Vector3f (const Vector2f& Vector) : x (Vector.x),
                                                  y (Vector.y),
                                                  z (0) {
    }

/*============================================================================================================*/

    // Construct from Vector4f
    Vector3f::Vector3f (const Vector4f& Vector) : x (Vector.x),
                                                   y (Vector.y),
                                                   z (Vector.z) {
    }

/*============================================================================================================*/
/*------PUBLIC FUNCTIONS--------------------------------------------------------------------------------------*/
/*============================================================================================================*/

    // Format vector as string
    std::string Vector3f::ToString () {

        return (std::to_string (this -> x) + ", " +
                std::to_string (this -> y) + ", " +
                std::to_string (this -> z) + "\n");
    }
}
