## Lab 03

In this lab, you will **A**) compare the performance of reading and writing data files, and **B**) compare the performance of matrix multiply. 
Please submit your results as a single __pdf__ document.  For this assigment, you do not need to submit code for grading.

### Relevant Links

[Why Modern CPUs are Starving and What Can be Done About it](http://www.pytables.org/docs/CISE-12-2-ScientificPro.pdf)

[Every Programmer Should Know These Latency Numbers](http://architects.dzone.com/articles/every-programmer-should-know)

### Part A: File IO

Run several experiments that compare the peformance of reading and writing a text file (`io_text.cpp`) to reading and writing from HDF5 (`io_hdf.cpp`).  Please feel free to modify the code in any way you need to for the experiments you run.  At a minimum, we are looking for a **graph** that summarizes your experiment comparing the problem size on the *x axis* and the time in seconds on the *y axis*.  This is a vague description so please feel free to be creative if you'd like.  

In your report, please include:
- 10 points: a *short description* of your experiment(s). 
- 10 points: a **graph** of your results.
- 10 points: a *brief answer* to the question: How much faster is HDF5 when reading and writing square matrices? 

Total points: 30

### Part B: Matrix Multiply Performance

Compare the perormance of your matrix multiply implementation with the Intel Math Kernel Library (MKL) using HDF5 (`matrix_multiply.cpp`).  Run several experiments and include a graph of the runtime in seconds on the *y axis* and the problem size on the *y axis*.  Please also include a graph that shows the level 2 and 3 cache misses (*y axis*) for each experiment you run (problem size, *x axis*). Please feel free to modify the code as needed.

Your report should include:
- 10 points: a *short description* of your experiment(s). 
- 10 points: a **graph** of your timing results.
- 10 points: a **graph** of your cache results.
- 10 points: a *brief answer* to the question: How much faster is the MKL using HDF5 than a *naive* matrix multiply using text files?

### Advice:

#### Modules
Please use the lab 3 module.

    module load HPSC_CLASS/lab03

#### Matrix files:
You will probably be testing larger problems.  Please do do any multiplication tests that are over 28000x28000 as it will likely crash the nodes.  Also, please only work on a reserved node.  You can test small problems on janus-compile, but for anythign substantial, you'll need to have an entire node (e.g. `nodes=1:ppn=12`).

#### Running code
The code base contains `generate_matrix.py` that you can use to generate matrix files.  The command

    python generate_matrix.py -m 10 -n 5 -f filename -t h5

will create an HDF5 file called `filename.h5`.  Similarly, you can create a text file called `filename.txt` by typing

    python generate_matrix.py -m 10 -n 5 -f filename -t txt

**Please delete** the matrix files once you are done with them.

Here is an example of how to run the matrix multiply with MKL and HDF5.

    make
    python generate_matrix.py -m 1000 -n 1000 -f matrix.A.h5 -t h5
    python generate_matrix.py -m 1000 -n 1000 -f matrix.B.h5 -t h5
    ./matrix_multiply matrix.A.h5 matrix.B.h5 matrix.C.h5
    rm matrix.*.h5

### Using `psrun`

There are two steps to get cache information using `psrun`.
- Generate the xml file:
    
        psrun ./matrix_multiply matrix.A.h5 matrix.B.h5 matrix.C.h5

    This creates a file called `matrix_multiply.0.*.xml`, where `*` uniquely identifies the run.

- Process the XML file.

        psprocess matrix_multiply.0.*.xml

    This will generate the cache summary.




















