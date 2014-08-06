#include <stdio.h>
#include <stdlib.h>

#include "fir/fir_float.h"

#define FILTER_LEN 4
#define SAMPLES 20

int main(int argc, char *argv[])
{
	double coeffs[FILTER_LEN] = {
		0.1, 0.2, 0.3, 0.4
	};

	double input[SAMPLES] = {
		1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
		11, 12, 13, 14, 15, 16, 17, 18, 19, 20
	};

	double output[SAMPLES];

	firFloatInit();
	firFloat(coeffs, input, output, SAMPLES, FILTER_LEN);

	int i;
	printf("coeffs[] = {\n");
	for(i=0; i<FILTER_LEN; i++) {
		printf("%.4f\n", coeffs[i]);
	}
	printf("}\n\n");

	printf("input[] = {\n");
	for(i=0; i<SAMPLES; i++) {
		printf("%.4f\n", input[i]);
	}
	printf("}\n\n");

	printf("output[] = {\n");
	for(i=0; i<SAMPLES; i++) {
		printf("%.4f\n", output[i]);
	}
	printf("}\n");

	return 0;
}
