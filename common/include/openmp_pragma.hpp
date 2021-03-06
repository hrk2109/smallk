// Copyright 2014 Georgia Institute of Technology
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#pragma once

// Use the _Pragma operator to wrap OpenMP pragmas in a macro.  Helps with 
// compilation for compilers that do not support OpenMP.
// The OpenMP code defines the _OPENMP macro.  Elemental defines the
// HAVE_OPENMP macro for 'hybrid' build types prior to release 0.84.
// Elemental release 0.84 changed HAVE_OPENMP to ELEM_HAVE_OPENMP.

#if ELEM_VER >= 85
#include "El.hpp"
#else
#include "elemental.hpp"
#endif

#if defined _OPENMP && (defined HAVE_OPENMP || defined ELEM_HAVE_OPENMP || defined EL_HAVE_OPENMP)
#include <omp.h>
#define SMALLK_HAVE_OPENMP 1
#define OPENMP_PRAGMA(x) _Pragma(#x)
#define OPENMP_API_CALL(x) x
#else
#define OPENMP_PRAGMA(x)
#define OPENMP_API_CALL(x)
#endif


