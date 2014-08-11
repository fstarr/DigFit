## DigFit - Digital Filter Implementation / Library

Currently contains an FIR filter implementation based on
[this blogpost](http://sestevenson.wordpress.com/implementation-of-fir-filtering-in-c-part-1/)
as well as an IIR filter implementation.

File `main.c` contains code for a sample program demonstrating both FIR and IIR
filter use.

Compile and run FIR/IIR filter sample program:

    $ gcc conv.c fir/fir_float.c iir/iir_float.c main.c -o main.out
    $ ./main.out

Enjoy!
