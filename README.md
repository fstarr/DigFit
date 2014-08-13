## DigFit - Digital Filter Implementation / Library

Currently contains *two variants* of an *FIR filter implementation* (one based on
[this blogpost](http://sestevenson.wordpress.com/implementation-of-fir-filtering-in-c-part-1/))
as well as *IIR filter implementations* using floating point operations.

File `main.c` contains code for a sample program demonstrating both FIR and IIR
filter variants.

Compile and run FIR/IIR filter sample program:

    $ gcc conv.c fir/fir_float.c iir/iir_float.c main.c -o main.out
    $ ./main.out

Or using the quick & dirty makefile:

    $ make
    $ ./main.out

Enjoy!
