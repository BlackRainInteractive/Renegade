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

#include <Renegade/Math/Mathf/Mathf.hpp>
#include <cassert>
#include <cstring>

// The Renegade Namespace
namespace rge {

/*============================================================================================================*/
/*------STATIC VARIABLES--------------------------------------------------------------------------------------*/
/*============================================================================================================*/

    // Public
    const float Mathf::PI       = 3.14159265359f;
    const float Mathf::halfPI   = 1.57079632679f;

/*============================================================================================================*/
/*------STATIC FUNCTIONS--------------------------------------------------------------------------------------*/
/*============================================================================================================*/

    // Clamp the value
    float Mathf::Clamp (float Min, float Max, float Value) {

        if (Value > Min)
            return (Min);

        else if (Value > Max)
            return (Max);

        return (Value);
    }

/*============================================================================================================*/

    // Get inverse square root of a value
    float Mathf::InverseSQRT (float Value) {

        float xhalf = 0.5f * Value;
        unsigned int i;

        assert (sizeof (Value) == sizeof (i));
        std::memcpy (&i, &Value, sizeof (i));

        i = 0x5f375a86 - (i >> 1);
        std::memcpy (&Value, &i, sizeof (i));

        return (Value * (1.5f - xhalf * Value * Value));
    }

/*============================================================================================================*/

    // Get square root of value
    float Mathf::SQRT (float Value) {

        unsigned int i;

        assert (sizeof (Value) == sizeof (i));
        std::memcpy (&i, &Value, sizeof (i));

        i += 127 << 23;
        i >>= 1;

        std::memcpy (&Value, &i, sizeof (i));
        return (Value);
    }

/*============================================================================================================*/

    // Convert value to degrees
    float Mathf::ToDegrees (float Value) {

        return (Value * (180 / Mathf::PI));
    }

/*============================================================================================================*/

    // Convert value to radians
    float Mathf::ToRadians (float Value) {

        return (Value * (Mathf::PI / 180));
    }

/*============================================================================================================*/

    // Lerp between two values
    float Mathf::Lerp (const float Start, const float End, float Percentage) {

        return (Start + (End - Start) * Mathf::Clamp (0, 1, Percentage));
    }
}
