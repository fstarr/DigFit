/*
 * fir_float.c
 *
 * Description: FIR filter implementation
 * Date:        2014-08-11
 * Author:      sfo (https://github.com/sfo)
 */
#include "fir_float.h"

/*
 * firFloatInit()
 *
 * Description: Initialize internal scratch pad memory of FIR function.
 *              For details see firFloat() and header file fir_float.h!
 *
 * Params:      void
 * Returns:     void
 */
void firFloatInit(void)
{
	memset(fir_input_sample, 0, sizeof(fir_input_sample));
}

/*
 * firFloat()
 *
 * Description: Apply FIR filter to input data values and store them
 *              in output array.
 *
 *              y[n] = sum(x[n-k]*h[k], k=0..N)
 *
 *              x[] = input samples, y[] = output samples,
 *              h[] = coeffs, N = filterLength
 *
 * Params:      coeffs       - pointer to array holding FIR filter coefficients
 *              input        - pointer to array holding input data samples
 *              output       - pointer to array to which output samples will be
 *                             written
 *              length       - number of input samples to process
 *              filterLength - FIR filter depth (number of coefficients)
 *
 * Returns:     void; Outputs are stored in output array that is provided as
 *              parameter.
 */
void firFloat(double *coeffs, double *input, double *output, const int length,
		const int filterLength)
{
	double acc; // accumulator for MACs
	double *pCoeff; // pointer to coeffs
	double *pInput; // pointer to input samples
	int n, k;

	// put new samples at high end of buffer
	memcpy(&fir_input_sample[filterLength-1], input, length * sizeof(double));

	// apply filter to each input sample
	for(n=0; n<length; n++) {
		pCoeff = coeffs;
		pInput = &fir_input_sample[filterLength-1+n];
		acc = 0;
		for(k=0; k<filterLength; k++) {
			acc += (*pCoeff++) * (*pInput--);
		}
		output[n] = acc;
	}

	// shift input samples back in time for next firFloat() call
	memmove(&fir_input_sample[0], &fir_input_sample[length],
			(filterLength-1) * sizeof(double));
}

/*
 * firFloatStream()
 *
 * Description: Apply FIR filter to ONE input sample and store output in
 *              output variable. Array containing input history need to be
 *              provided!
 *              This variant of the FIR filter is suitable for live-data
 *              processing as in embedded devices that continuously read input
 *              data from some kind of sensor, but lack the availability of
 *              large memory.
 *
 * Params:      coeffs       - pointer to array holding FIR coefficients
 *              hist_input   - array containing history of input samples
 *
 *                             Note: History values are added and arranged
 *                             by the function itself. Array needs to be
 *                             initialized with all zeroes before first run
 *                             of firFloatStream()!
 *
 *                             Note: Memory must be allocated a-priori with
 *                             respect to filterLength):
 *
 *                               double hist_input[filterLength] =
 *                               {0.0, ..., 0.0};
 *
 *              input        - pointer to variable holding input data sample
 *              output       - pointer to variable to which output data
 *                             sample will be written
 *              filterLength - filter depth (number of coefficients)
 *
 * Returns:     void; Outputs are stored in output variable that is provided as
 *              pointer parameter.
 */
void firFloatStream(const double *coeffs, double *hist_input, const double *input, double *output, const int filterLength)
{
	double y = 0;
	unsigned int k;

	// perform calculations for ONE input sample
	// shift input register forward and insert current value
	for(k=filterLength-1; k>0; k--) {
		hist_input[k] = hist_input[k-1];
	}

	// insert current input sample
	hist_input[0] = (*input);

	// calculate output
	for(k=0; k<filterLength; k++) {
		y += coeffs[k] * hist_input[k];
	}

	(*output) = y;
}
