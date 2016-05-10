/* Replace "dll.h" with the name of your header */
#include "dll.h"
#include <windows.h>

#include <math.h>
#include <stdio.h>


// Variables:
//      t: Time, passed from PSIM by value
//   delt: Time step, passed from PSIM by value
//     in: input array, passed from PSIM by reference
//    out: output array, sent back to PSIM (Note: the values of out[*] can
//         be modified in PSIM)

// The maximum length of the input and output array "in" and "out" is 30.

double t, delt;
double *in, *out;

__stdcall void simuser (double t, double delt, double *in, double *out)
{
// Place your code here............begin

//  Define "sum" as "static" in order to retain its value.
	static double lambda=0.0;
	static double L=0.005;

	double v, i;

	// Receive the voltage from PSIM
	v = in[0];
	
	// Integrate the voltage to obtain the flux linkage
	lambda = lambda + v*delt;

	// Calculate the current
	i = lambda / L;

	// Send the current back to PSIM
	out[0] = i;

// Place your code here............end
}



