
/* Replace "dll.h" with the name of your header */
#include "dll.h"
#include <windows.h>

                                                                                                                                             


double t;  /*!< Time, passed from PSIM by value */
double delt;  /*!< Time step, passed from PSIM by value */
double *in;  /*!< Input array, passed from PSIM by reference */
double *out;  /*!< Output array, sent back to PSIM (Note: the values of out[*] can be modified in PSIM) */

/** \brief DLL routine funtion.
      * \param t: Time, passed from PSIM by value
      * \param delt: Time step, passed from PSIM by value
      * \param in: Input array, passed from PSIM by reference
      * \return output array, sent back to PSIM (Note: the values of out[*] can be modified in PSIM)
      * 
      * The maximum length of the input and output array "in" and "out" is 30.
      *
      * PSIM calls the DLL routine at each simulation time step. However, when the inputs of the DLL block are connected to the output of one of these discrete elements 
	  * (zero-order hold, unit delay, integrator, differentiator, z-domain transfer function block, and digital filters), 
	  * the DLL block is considered as a discrete element. In this case, the DLL block is called only at the discrete times.
	  *
	  * The DLL block receives the values from PSIM as the input, performs the calculation, and sends the output back to PSIM. 
	  * The node assignments are: the input nodes are on the left, and the output nodes are on the right. The sequence is from the top to the bottom. 
	  *
      */
 
      
__stdcall void simuser (double t, double delt, double *in, double *out)
{
// Place your code here............begin

///  Define "sum" as "static" in order to retain its value.
	static double lambda=0.0; 
	static double L=0.005;   

	double v;  /*!< Variable to recieve voltage value */
	double i;  /*!< Variable to recieve current value  */

	/// Receive the voltage from PSIM
	v = in[0];
	
	/// Integrate the voltage to obtain the flux linkage
	lambda = lambda + v*delt;

	/// Calculate the current
	i = lambda / L;

	/// Send the current back to PSIM
	out[0] = i;
	  
      

// Place your code here............end
}



