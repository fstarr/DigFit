#include <stdio.h>
#include <stdlib.h>
#include "iir_float.h"

/*
 * iirFloat()
 *
 * Description: Apply IIR filter to input data values and store them in
 *              output array.
 *
 *              y[n] = sum(b[k]*x[n-k], k=0..N) - sum(a[k]*y[n-k], k=1..M)
 *
 *              x[] = intput samples, y[] = output samples,
 *              b[] = numCoeffs, a[] = denomCoeffs, N = numFilterLen,
 *              M = denomFilterLen
 *
 * Params:      denomCoeffs    - pointer to array holding IIR denominator
 *                               coefficients
 *              numCoeffs      - pointer to array holding IIR numerator
 *                               coefficients
 *              input          - pointer to array holding input data samples
 *              output         - pointer to array to which output samples will
 *                               be written
 *              length         - number of input samples to process
 *                               NOTE: iirFloat() has a delay, so it should be
 *                               run on M more input data samples than provided
 *                               in 'input'. Reasonable values for M are twice
 *                               the group delay (~2*(N+1)).
 *              numFilterLen   - number of numerator coefficients
 *              denomFilterLen - number of denominator coefficients
 *
 * Returns:     void; Outputs are stored in output array that is provided as
 *              parameter.
 */
void iirFloat(double *denomCoeffs, double *numCoeffs, double *input, double *output, int length, int denomFilterLen, int numFilterLen)
{
	int j, k, N;
	double y, *reg;

	// determine degre of polynomial
	N = (denomFilterLen > numFilterLen) ? (denomFilterLen-1) : (numFilterLen-1);

	// initialize delay registers
	reg = (double *) malloc((N+1)*sizeof(double));
	memset(reg, 0, sizeof(reg));

	// perform calculations
	for(j=0; j<length; j++)
	{
		// shift delay register values.
		for(k=N; k>0; k--)
			reg[k] = reg[k-1];

		// denominator
		reg[0] = input[j];

		for(k=1; k<=denomFilterLen; k++)
			reg[0] -= denomCoeffs[k] * reg[k];

		// numerator
		y = 0;
		for(k=0; k<=numFilterLen; k++)
			y += numCoeffs[k] * reg[k];

		output[j] = y;
	}

	// free memory
	free((void *)reg);
}

