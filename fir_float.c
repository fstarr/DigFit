#include "fir_float.h"

void firFloatInit(void)
{
	memset(input_sample, 0, sizeof(input_sample));
}

void firFloat(double *coeffs, double *input, double *output, int length,
		int filterLength)
{
	double acc; // accumulator for MACs
	double *pCoeff; // pointer to coeffs
	double *pInput; // pointer to input samples
	int n, k;

	// put new samples at high end of buffer
	memcpy(&input_sample[filterLength-1], input, length * sizeof(double));

	// apply filter to each input sample
	for(n=0; n<length; n++) {
		pCoeff = coeffs;
		pInput = &input_sample[filterLength-1+n];
		acc = 0;
		for(k=0; k<filterLength; k++) {
			acc += (*pCoeff++) * (*pInput--);
		}
		output[n] = acc;
	}

	// shift input samples back in time for next firFloat() call
	memmove(&input_sample[0], &input_sample[length],
			(filterLength-1) * sizeof(double));
}

void int16ToFloat(int16_t *input, double *output, int length)
{
	int i;
	for(i=0; i<length; i++) {
		output[i] = (double) input[i];
	}
}

void int32ToFloat(int32_t *input, double *output, int length)
{
	int i;
	for(i=0; i<length; i++) {
		output[i] = (double) input[i];
	}
}

void floatToInt16(double *input, int16_t *output, int length)
{
	int i;
	for(i=0; i<length; i++) {
		if(input[i] > 32767.0) {
			input[i] = 32767.0;
		}
		else if(input[i] < -32768.0) {
			input[i] = -32768.0;
		}

		output[i] = (int16_t) input[i];
	}
}

void floatToInt32(double *input, int32_t *output, int length)
{
	int i;
	for(i=0; i<length; i++) {
		if(input[i] > 2147483647.0) {
			input[i] = 2147483647.0;
		}
		else if(input[i] < -2147483648.0) {
			input[i] = -2147483648.0;
		}

		output[i] = (int32_t) input[i];
	}
}

