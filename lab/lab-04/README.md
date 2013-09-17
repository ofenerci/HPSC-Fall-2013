#Lab 04 Matrix Multiply with Data Access Optimization

__Due: October 1, 2013__

You will improve the runtime performance of your `matrix_multiply` from lab 03 by optimizing the way your program manages data.  Specifically, you will be finding the best loop order and block size for your matrix multiply.

You will need to read and write HDF5 files.  You may use the code from lab 03 if you'd like.  You many want to also read and write text files for testing and debugging, but this is not required for your grade.  Please see the lab 03 `io_hdf.cpp` file for help.

Please use the following module:

    module load HPSC_CLASS/lab04

We will run you code on several random files created with the `generate_matrix.py` tool from Lab 03.  You will be graded on the correctness and efficiency of your answers.