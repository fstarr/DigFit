/***********************************************/
/* fir_float.c                                 */
/*                                             */
/* Description: FIR filter implementation      */
/* Date:        2014-08-11                     */
/* Author:      sfo (https://github.com/sfo)   */
/***********************************************/
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
void firFloat(double *coeffs, double *input, double *output, int length,
		int filterLength)
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

