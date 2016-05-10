#ifndef _DLL_H_
#define _DLL_H_


#include <stdio.h>


// Variables:
//      t: Time, passed from PSIM by value
//   delt: Time step, passed from PSIM by value
//     in: input array, passed from PSIM by reference
//    out: output array, sent back to PSIM (Note: the values of out[*] can
//         be modified in PSIM)

// The maximum length of the input and output array "in" and "out" is 30.

extern "C" {

	void __stdcall __declspec(dllexport) simuser (double t, double delt, double *in, double *out);
}

#endif


