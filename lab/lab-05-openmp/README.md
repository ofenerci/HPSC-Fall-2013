#Lab 05: OpenMP

__DUE: October 1st, 2013__

This assignment *should* be quick.  We will do more with OpenMP in the next few weeks as we talk more about parallelism.

##Matrix Multiply

Take you matrix multiply from the assignment four and make it even faster by adding shared-memory parallelism with OpenMP.  As in [lab 04](https://github.com/ResearchComputing/HPSC-Fall-2013/tree/master/lab/lab-04), please test your code with the `compare.py` file.  We will be using this to test your code also.  

Use the following module for building your code:

        module load HPSC_CLASS/lab05

## Grading

We will run your code on 5 different problem sizes using 1,6, and 12 threads.  Any test that gives the incorrect result will get zero points.  You will be graded on your accuracy and relative speed of the multi-thread examples.  Each test is worth 10 points for a total of 50 points.  

## What to turn in?
At the minimum, you should have a:

- Makefile
- At least one source file




