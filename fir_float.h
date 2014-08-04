#ifndef __FIR_FLOAT_H
#define __FIR_FLOAT_H

#include <stdint.h>
#include <string.h>

// ToDo: make this changeable from function params
#define MAX_INPUT_LEN 80
#define MAX_FLT_LEN   63
#define BUFFER_LEN    (MAX_FLT_LEN - 1 + MAX_INPUT_LEN)

double input_sample[BUFFER_LEN];

void firFloatInit(void);
void firFloat(double *coeffs, double *input, double *output, int length, int filterLength);

void int16ToFloat(int16_t *input, double *output, int length);
void int32ToFloat(int32_t *input, double *output, int length);

void floatToInt16(double *input, int16_t *output, int length);
void floatToInt32(double *input, int32_t *output, int length);

#endif //__FIR_FLOAT_H
