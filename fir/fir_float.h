/*
 * fir_float.h
 *
 * Description: FIR filter function declarations
 * Date:        2014-08-11
 * Author:      sfo (https://github.com/sfo)
 */
#ifndef __FIR_FLOAT_H
#define __FIR_FLOAT_H

#include <stdint.h>
#include <string.h>

#include "../conv.h"

// ToDo: make this changeable from function params
#define FIR_MAX_INPUT_LEN 80
#define FIR_MAX_FLT_LEN   63
#define FIR_BUFFER_LEN    (FIR_MAX_FLT_LEN - 1 + FIR_MAX_INPUT_LEN)

double fir_input_sample[FIR_BUFFER_LEN];

void firFloatInit(void);
void firFloat(double *coeffs, double *input, double *output, const int length, const int filterLength);
void firFloatStream(const double *coeffs, double *hist_input, const double *input, double *output, const int filterLength);

#endif //__FIR_FLOAT_H
