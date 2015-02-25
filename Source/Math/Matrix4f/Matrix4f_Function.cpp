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

// The Renegade Namespace
namespace rge {

/*============================================================================================================*/
/*------CONSTRUCTOR-------------------------------------------------------------------------------------------*/
/*============================================================================================================*/

    // Default constructor
    Matrix4f::Matrix4f () {

        this -> _value [0] = Vector4f (0);
        this -> _value [1] = Vector4f (0);
        this -> _value [2] = Vector4f (0);
        this -> _value [3] = Vector4f (0);
    }

/*============================================================================================================*/

    // Construct from single value
    Matrix4f::Matrix4f (float Value) {


        this -> _value [0] = Vector4f (Value);
        this -> _value [1] = Vector4f (Value);
        this -> _value [2] = Vector4f (Value);
        this -> _value [3] = Vector4f (Value);
    }

/*============================================================================================================*/

    // Construct from nine values
    Matrix4f::Matrix4f (float X0, float Y0, float Z0, float W0,
                        float X1, float Y1, float Z1, float W1,
                        float X2, float Y2, float Z2, float W2,
                        float X3, float Y3, float Z3, float W3) {

        this -> _value [0] = Vector4f (X0, Y0, Z0, W0);
        this -> _value [1] = Vector4f (X1, Y1, Z1, W1);
        this -> _value [2] = Vector4f (X2, Y2, Z2, W2);
        this -> _value [3] = Vector4f (X3, Y3, Z3, W3);
    }

/*============================================================================================================*/

    // Construct from three Vector3f's
    Matrix4f::Matrix4f (const Vector4f& Vec01,
                        const Vector4f& Vec02,
                        const Vector4f& Vec03,
                        const Vector4f& Vec04) {

        this -> _value [0] = Vec01;
        this -> _value [1] = Vec02;
        this -> _value [2] = Vec03;
        this -> _value [3] = Vec04;
    }

/*============================================================================================================*/
/*------PUBLIC FUNCTIONS--------------------------------------------------------------------------------------*/
/*============================================================================================================*/

    // Format matrix as string
    std::string Matrix4f::ToString () {

        return (this -> _value [0].ToString () +
                this -> _value [1].ToString () +
                this -> _value [2].ToString () +
                this -> _value [3].ToString ());
    }
}
