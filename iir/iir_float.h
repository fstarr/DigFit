#ifndef __IIR_FLOAT_H
#define __IIR_FLOAT_H

#include <stdint.h>
#include <string.h>

void iirFloat(double *denomCoeffs, double *numCoeffs, double *input, double *output, int length, int denomFilterLen, int numFilterLen);
void iirFloatStream(double *denomCoeffs, double *numCoeffs, double *hist_intput, double *hist_output, double *input, double *output, int denomFilterLen, int numFilterLen);

#endif // __IIR_FLOAT_H
