# RSA-Algorithm-in-C-
Implementation of RSA in C++

This program implements the RSA crypto-system in C++ using GNU integer interface. To run this program, your computer must have GNU libary installed. 

The program includes a Makefile. To compile the program, run "make" in the terminal.

After compiling, run "./rsa SecurityLevel". After running, the program will generate the RSA parameters randomly, and you can encrypt or decrypt your messages using the parameters according to instruction.

The security level can be 80, 112, 128, 192, 256, which correspond to the RSA modulus bits of 1024, 2048, 3072, 7680, 15360.
