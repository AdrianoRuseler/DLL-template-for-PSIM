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
	static double nsum=0., sum=0., rms;
	double Tperiod;

	Tperiod=1./60.;

	if (t >= nsum*Tperiod)
	{
		nsum=nsum+1.;
		rms = sqrt(sum*delt/Tperiod);
		sum=0.;
	}

	out[0] = rms;
	sum=sum+in[0]*in[0];


// Place your code here............end
}



