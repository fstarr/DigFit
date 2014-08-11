#include "conv.h"

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
