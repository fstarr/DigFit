#ifndef __IIR_FLOAT_H
#define __IIR_FLOAT_H

#include <stdint.h>
#include <string.h>

void iirFloat(double *denomCoeffs, double *nomCoeffs, double *input, double *output, int length, int denomFilterLen, int nomFilterLen);

#endif // __IIR_FLOAT_H
