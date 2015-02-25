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

// The Renegade Namespace
namespace rge {

/*============================================================================================================*/
/*------CONSTRUCTOR-------------------------------------------------------------------------------------------*/
/*============================================================================================================*/

    // Default constructor
    Matrix3f::Matrix3f () {

        this -> _value [0] = Vector3f (0);
        this -> _value [1] = Vector3f (0);
        this -> _value [2] = Vector3f (0);
    }

/*============================================================================================================*/

    // Construct from single value
    Matrix3f::Matrix3f (float Value) {


        this -> _value [0] = Vector3f (Value);
        this -> _value [1] = Vector3f (Value);
        this -> _value [2] = Vector3f (Value);
    }

/*============================================================================================================*/

    // Construct from nine values
    Matrix3f::Matrix3f (float X0, float Y0, float Z0,
                        float X1, float Y1, float Z1,
                        float X2, float Y2, float Z2) {

        this -> _value [0] = Vector3f (X0, Y0, Z0);
        this -> _value [1] = Vector3f (X1, Y1, Z1);
        this -> _value [2] = Vector3f (X2, Y2, Z2);
    }

/*============================================================================================================*/

    // Construct from three Vector3f's
    Matrix3f::Matrix3f (const Vector3f& Vec01,
                        const Vector3f& Vec02,
                        const Vector3f& Vec03) {

        this -> _value [0] = Vec01;
        this -> _value [1] = Vec02;
        this -> _value [2] = Vec03;
    }

/*============================================================================================================*/
/*------PUBLIC FUNCTIONS--------------------------------------------------------------------------------------*/
/*============================================================================================================*/

    // Format matrix as string
    std::string Matrix3f::ToString () {

        return (this -> _value [0].ToString () +
                this -> _value [1].ToString () +
                this -> _value [2].ToString ());
    }
}
