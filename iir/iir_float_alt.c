#include "iir_float.h"

void iirFloatInit(void)
{
	memset(iir_input_sample, 0, sizeof(iir_input_sample));
}

/*
 * size              - number of input samples
 * firFilterLength   - filter depth (coeff. count) of FIR component
 * fdBckFilterLength - filter depth (coeff. count) of feedback component
 */
void iirFloat(double *firCoeffs, double *fdBckCoeffs, double *input, double *output, int length, int firFilterLength, int fdBckFilterLength)
{
	double acc; // accumulator for MACs
	double *pFirCoeffs; // pointer to FIR component coeffs
	double *pFdBckCoeffs; // pointer to feedback coeffs
	double *pInput; // pointer to input samples
	int n, k;

	// put new samples at high end of buffer
	memcpy(&iir_input_sample[filterLength-1], input, length * sizeof(double));

	// apply filter to each input sample
	for(n=0; n<length; n++) {
		pFirCoeffs = firCoeffs;
		pInput = &iir_input_sample[];
	}
}
