#ifndef __IIR_FLOAT_H
#define __IIR_FLOAT_H

#include <stdint.h>
#include <string.h>

#include "../conv.h"
#include "../fir/fir_float.h"

#define IIR_MAX_INPUT_LEN 80   // max. number of input samples
#define IIR_MAX_FLT_LEN 4      // filter depth
#define IIR_BUFFER_LEN (FIR_BUFFER_LEN + ) // input buffer size

/*
 * General IIR filter equation (with filter coefficients ak, bk):
 *
 * H(z) = ( b0 + b1 * z^-1 + ... + bN * z^-N ) /
 *        ( 1 + a1 * z^-1 + ... + aM * z^-M )
 *      = sum(bk * z^-k, k=0..N) /
 *        1+ sum(ak * z^-k, k=1..M)
 *
 * y[n] = sum( b[k] * x[n-k], k=0..N )
 *      - sum( a[k] * y[n-k], k=1..M )
 */

double iir_input_sample[IIR_BUFFER_LEN];

void iirFloatInit(void);
void iirFloat(double *firCoeffs, double *fdBckCoeffs, double *input, double *output, int length, int filterLength);

#endif // __IIR_FLOAT_H
