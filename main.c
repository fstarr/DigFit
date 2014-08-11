#include <stdio.h>
#include <stdlib.h>

#include "fir/fir_float.h"
#include "iir/iir_float.h"

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
	printf("*** FIR filter test ***\n");
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

	/*** IIR Filter Test ***/

	double denomCoeffs[FILTER_LEN+1] = {
		1.0, 0.1, 0.2, 0.3, 0.4
	};

	double numCoeffs[FILTER_LEN+3] = {
		0.1, 0.2, 0.3, 0.4, 0.3, 0.2, 0.1
	};

	// run IIR filter on input plus 2*(FILTER_LEN+3) further inputs
	// since the filter has a delay. Reasonable value to use here is
	// twice the group delay value
	double iir_input[SAMPLES+2*(FILTER_LEN+3)] = {
		1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
		11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0
	};

	iirFloat(denomCoeffs, numCoeffs, iir_input, output, SAMPLES+2*(FILTER_LEN+3), FILTER_LEN+1, FILTER_LEN+3);

	printf("*** IIR filter test ***\n");
	printf("denomCoeffs[] = {\n");
	for(i=0; i<FILTER_LEN+1; i++) {
		printf("%.4f\n", denomCoeffs[i]);
	}
	printf("}\n\n");

	printf("numCoeffs[] = {\n");
	for(i=0; i<FILTER_LEN+3; i++) {
		printf("%.4f\n", numCoeffs[i]);
	}
	printf("}\n\n");

	printf("input[] = {\n");
	for(i=0; i<SAMPLES; i++) {
		printf("%.4f\n", iir_input[i]);
	}
	printf("}\n\n");

	printf("output[] = {\n");
	for(i=0; i<SAMPLES+2*(FILTER_LEN+3); i++) {
		printf("%.4f\n", output[i]);
	}
	printf("}\n");

	/*** IIR Stream Filter Test ***/
	double in, out;
	double hist_i[FILTER_LEN+3] = { 0.0 };
	double hist_o[FILTER_LEN+1] = { 0.0 };

	printf("input/hist_i/hist_o/output[] = {\n");
	for(i=0; i<SAMPLES+2*(FILTER_LEN+3); i++) {
		in = (i<20) ? (i+1) : 0;
		iirFloatStream(denomCoeffs, numCoeffs, hist_i, hist_o, &in, &out, FILTER_LEN+1, FILTER_LEN+3);
		printf("%.4f/%.4f/%.4f/%.4f\n", in, hist_i[1], hist_o[1], out);
	}
	printf("}\n");

	return 0;
}
