#ifndef __CONV_H
#define __CONV_H

#include <stdint.h>
#include <string.h>

void int16ToFloat(int16_t *input, double *output, int length);
void int32ToFloat(int32_t *input, double *output, int length);

void floatToInt16(double *input, int16_t *output, int length);
void floatToInt32(double *input, int32_t *output, int length);

#endif // __CONV_H
