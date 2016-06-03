
/* Replace "dll.h" with the name of your header */
#include "DllHeader.h"
#include <windows.h>

#include <stdio.h>
#include <math.h>


/* Required: DLL needs to set all fields in aSizes.                          */
/* Called once before the simulation.                                        */
void plecsSetSizes(struct SimulationSizes* aSizes){
/** \brief plecsSetSizes funtion.
      * \param numInputs: The width of the input signal that the DLL expects. The length of the input array in the SimulationState struct is set to this value.
      * \param numOutputs: The number of outputs that the DLL generates. The width of the output signal of the DLL block and the length of the output array in the SimulationState struct is set to this value.
      * \param numStates: The number of discrete states that the DLL uses. The length of the states array in the SimulationState struct is set to this value.
      * \param numParameters: The length of the parameter vector that the DLL expects. A vector with numParameters elements must be supplied in the Parameters field of the component parameters of the DLL block. The parameters are passed in the parameters array in the SimulationState struct.
      *  
      * In the implementation of plecsSetSizes the DLL has to set all the fields of the supplied structure.
      */

// Place your code here............begin

aSizes->numInputs=1;  // The width of the input signal that the DLL expects.
aSizes->numOutputs=1; // The number of outputs that the DLL generates.
aSizes->numStates=1;  // The number of discrete states that the DLL uses.
aSizes->numParameters=1; // The number of discrete states that the DLL uses.

// Place your code here............end
}
   
      
/* Required: DLL needs to set outputs depending on inputs and states.        */
/* Called whenever the simulation time reaches a multiple of the sample      */
/* time.                                                                     */
void plecsOutput(struct SimulationState* aState){
/** \brief plecsOutput funtion.
      * \param inputs: The values of the input signal for the current simulation step. The values are read-only. The array length is the value of the numInputs field that was set in the plecsSetSizes method.
      * \param outputs: The output values for the current simulation step. These values must be set by the DLL. The array length is the value of the numOutputs field that was set in the plecsSetSizes method.
      * \param states: The values of the discrete states of the DLL. These values can be read and modified by the DLL. The array length is the value of the numStates field that was set in the plecsSetSizes method.
      * \param parameters: The values of the parameters that were set in the Parameters field in the component parameters of the DLL block. The values are read-only. The array length is the value of the numParameters field that was set in the plecsSetSizes method.
      * \param time: The simulation time of the current simulation step.
      * \param errorMessage: The DLL may indicate an error condition by setting an error message. The simulation will be stopped after the current simulation step.
      * \param userData: A pointer to pass data from one call into the DLL to another. The value is not touched by PLECS.
      *
      *
      * This function is called whenever the simulation time reaches a multiple of the Sample time of the DLL block.
      */

// Place your code here............begin


///  Define as "static" in order to retain its value.
    double delt = 1e-6; 
    
	double lambda = aState->states[0]; 
	
	double L = aState->parameters[0];   

	double v;  /*!< Variable to recieve voltage value */
	double i;  /*!< Variable to recieve current value */

	/// Receive the voltage from PLECS
	v = aState->inputs[0];
	
//	delt = aState->time - delt;
	/// Integrate the voltage to obtain the flux linkage
	lambda = lambda + v*delt;

	/// Calculate the current
	i = lambda / L;
	
	aState->states[0]=lambda;
	
	/// Send the current back to PLECS
	aState->outputs[0] = i;
	
// Place your code here............end
  
}
      
      
/* Optional: DLL may acquire resources, initialize states and outputs.       */
/* Called once during the initialization of a new simulation.                */
void plecsStart(struct SimulationState* aState){
/** \brief plecsStart funtion.
      * \param inputs: The values of the input signal for the current simulation step. The values are read-only. The array length is the value of the numInputs field that was set in the plecsSetSizes method.
      * \param outputs: The output values for the current simulation step. These values must be set by the DLL. The array length is the value of the numOutputs field that was set in the plecsSetSizes method.
      * \param states: The values of the discrete states of the DLL. These values can be read and modified by the DLL. The array length is the value of the numStates field that was set in the plecsSetSizes method.
      * \param parameters: The values of the parameters that were set in the Parameters field in the component parameters of the DLL block. The values are read-only. The array length is the value of the numParameters field that was set in the plecsSetSizes method.
      * \param time: The simulation time of the current simulation step.
      * \param errorMessage: The DLL may indicate an error condition by setting an error message. The simulation will be stopped after the current simulation step.
      * \param userData: A pointer to pass data from one call into the DLL to another. The value is not touched by PLECS.
      *
      *
      * This function is called once at the start of a new simulation. It may be used to set initial outputs or states, initialize internal data structures, acquire resources etc.
      */
      
// Place your code here............begin

aState->states[0]=0.0;


// Place your code here............end 
     
}
     
   
     
     
     
     
/* Optional: DLL may release any acquired resources.                         */
/* Called when the simulation is finished, even when an error occured.       */
void plecsTerminate(struct SimulationState* aState){
/** \brief plecsTerminate funtion.
      *
      *
      * This function is called once when the simulation is finished. It may be used to free any resources that were acquired by the DLL.
      */

// Place your code here............begin


// Place your code here............end
}




