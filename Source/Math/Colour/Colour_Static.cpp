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

#include <Renegade/Math/Colour/Colour.hpp>
#include <Renegade/Math/Mathf/Mathf.hpp>

// The Renegade namespace
namespace rge {

/*============================================================================================================*/
/*------STATIC VARIABLES--------------------------------------------------------------------------------------*/
/*============================================================================================================*/

    // Public
    const Colour Colour::white      = Colour (1);
    const Colour Colour::lightGray  = Colour (0.75f, 0.75f, 0.75f, 1);
    const Colour Colour::gray       = Colour (0.5f, 0.5f, 0.5f, 1);
    const Colour Colour::darkGray   = Colour (0.25f, 0.25f, 0.25f, 1);
    const Colour Colour::black      = Colour (0, 0, 0, 1);
    const Colour Colour::red        = Colour (1, 0, 0, 1);
    const Colour Colour::yellow     = Colour (1, 1, 0, 1);
    const Colour Colour::green      = Colour (0, 1, 0, 1);
    const Colour Colour::cyan       = Colour (0, 1, 1, 1);
    const Colour Colour::blue       = Colour (0, 0, 1, 1);
    const Colour Colour::magenta    = Colour (1, 0, 1, 1);

/*============================================================================================================*/
/*------STATIC FUNCTIONS--------------------------------------------------------------------------------------*/
/*============================================================================================================*/

    // Lerp between two colours
    Colour Colour::Lerp (const Colour& Start, const Colour& End, float Percentage) {

        return (Colour (Start.r + (End.r - Start.r) * Mathf::Clamp (0, 1, Percentage),
                        Start.g + (End.g - Start.g) * Mathf::Clamp (0, 1, Percentage),
                        Start.b + (End.b - Start.b) * Mathf::Clamp (0, 1, Percentage),
                        Start.a + (End.a - Start.a) * Mathf::Clamp (0, 1, Percentage)));
    }
}
