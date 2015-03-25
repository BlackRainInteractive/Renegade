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

// The Renegade Namespace
namespace rge {

    // The colour class
    class Colour {
    public:

        // Constructor / Destructor
        Colour ();
        Colour (float Value);
        Colour (float Red, float Green, float Blue, float Alpha);

        // Functions
        std::string ToString ();

        // Static Functions
        static Colour Lerp (const Colour& Start, const Colour& End, float Percentage);

        // Arithmetic operators
        Colour operator + (const Colour& RHS);
        Colour operator + (const float RHS);
        Colour operator + ();
        Colour operator++ ();
        Colour operator++ (int);
        Colour operator - (const Colour& RHS);
        Colour operator - (const float RHS);
        Colour operator - ();
        Colour operator-- ();
        Colour operator-- (int);
        Colour operator * (const Colour& RHS);
        Colour operator * (const float RHS);
        Colour operator / (const Colour& RHS);
        Colour operator / (const float RHS);

        // Relational operators
        bool operator == (const Colour& RHS);
        bool operator != (const Colour& RHS);

        // Compound assignment operators
        Colour& operator += (const Colour& RHS);
        Colour& operator += (const float RHS);
        Colour& operator -= (const Colour& RHS);
        Colour& operator -= (const float RHS);
        Colour& operator *= (const Colour& RHS);
        Colour& operator *= (const float RHS);
        Colour& operator /= (const Colour& RHS);
        Colour& operator /= (const float RHS);

        // Member operators
        float& operator [] (int Index);

        // Variables
        float r, g, b, a;

        // Static variables
        static const Colour white;
        static const Colour lightGray;
        static const Colour gray;
        static const Colour darkGray;
        static const Colour black;
        static const Colour red;
        static const Colour yellow;
        static const Colour green;
        static const Colour cyan;
        static const Colour blue;
        static const Colour magenta;
    };
}
