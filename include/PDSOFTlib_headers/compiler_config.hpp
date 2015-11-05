//   Created by Denis-Michael Lux on 05. November 2015.
//
//   This file is part of PDSOFTlib.
//
//   PDSOFTlib is free software: you can redistribute it and/or modify
//   it under the terms of the GNU General Public License as published by
//   the Free Software Foundation, either version 3 of the License, or
//   (at your option) any later version.
//
//   PDSOFTlib is distributed in the hope that it will be useful,
//   but WITHOUT ANY WARRANTY; without even the implied warranty of
//   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//   GNU General Public License for more details.
//
//   You should have received a copy of the GNU General Public License
//   along with PDSOFT.  If not, see <http://www.gnu.org/licenses/>.

#ifndef PDSOFT_compiler_hpp
#define PDSOFT_compiler_hpp

// Library version
#undef  PDSOFT_MAJOR
#define PDSOFT_MAJOR 1

#undef  PDSOFT_MINOR
#define PDSOFT_MINOR 0

#undef  PDSOFT_PATCH
#define PDSOFT_PATCH 0

// Define the default number of used threads for multithreaded parts
#ifdef _OPENMP

    // include OpenMP headers for the OpenMP API
    #include <omp.h>

    // Number of default used threads is the max
    // number of possible threads
    #undef  PDSOFT_MAX_THREADS
    #define PDSOFT_MAX_THREADS omp_get_max_threads()
#else

    // setting the number of default used threads for
    // multithreaded parts to 1
    #undef  PDSOFT_MAX_THREADS
    #define PDSOFT_MAX_THREADS 1
#endif

/*- Processor information -*/
#define PDSOFT_PROJECT_ARCH "x86_64"

/*- SOFT config -*/
// SOFT Threshold
#undef  DSOFT_THRESHOLD
#define DSOFT_THRESHOLD 20

/*- Namespace macros -*/
// Macro shortcut for standard PDSOFT namespace
#undef  PDSOFT_BEGIN
#define PDSOFT_BEGIN           namespace pdsoft {

#undef  PDSOFT_END
#define PDSOFT_END             }

// Macro for nested standard namespace.
#define PDSOFT_NAMESPACE(a)    namespace pdsoft { namespace a {
    
#undef  PDSOFT_NAMESPACE_END
#define PDSOFT_NAMESPACE_END   }}

/*- Debugging messages -*/
// The debug mode flag is used to determine
// whether debug messages of methods should
// be printed or not. What messages get printed
// depends on the specific flags.
#undef  PDSOFT_DEBUG
#define PDSOFT_DEBUG 1

// the PDSOFT_SHOW_WARNINGS flag indicates
// that warning messages should be printed
// to console if they occure in execution.
#undef  PDSOFT_SHOW_WARNINGS
#define PDSOFT_SHOW_WARNINGS 1

// The PDSOFT_SHOW_ERRORS flag indicates
// that error messages should be printed
// to console if they occure in execution.
#undef  PDSOFT_SHOW_ERRORS
#define PDSOFT_SHOW_ERRORS 1

/*- Debugging log -*/
// Printing error message to the stderr console
#define pdsoft_error(fmt, ...)\
        do {\
            if(PDSOFT_DEBUG && PDSOFT_SHOW_ERRORS)\
                fprintf(stderr, "** [PDSOFTLib error]   %s:%d:%s(): " fmt " **\n",\
                    __FILE__, __LINE__, __func__, __VA_ARGS__\
                );\
            exit(EXIT_FAILURE);\
        } while(0)

// printing warning message to the stderr console
#define pdsoft_warning(fmt, ...)\
        do {\
            if (PDSOFT_DEBUG && PDSOFT_SHOW_WARNINGS)\
                fprintf(stderr, "** [PDSOFTLib warning] %s:%d:%s(): " fmt " **\n",\
                    __FILE__, __LINE__, __func__, __VA_ARGS__\
                );\
        } while(0)
      
/*- Attributes -*/
// force inlining of function
#undef  pdsoft_inline
#define pdsoft_inline          inline __attribute__((always_inline))
        
#undef  pdsoft_deprecated
#define pdsoft_deprecated      __attribute__((deprecated))

#define pdsoft_nonnull(...)    __attribute__((nonnull(__VA_ARGS__)))

#undef  pdsoft_pure
#define pdsoft_pure            __attribute__((pure))

#define pdsoft_aligned(n)      __attribute__((aligned((n))))

#endif
