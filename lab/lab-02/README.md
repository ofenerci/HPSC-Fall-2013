# Lab 2

There are two parts to this assignment: pipeline latency and matrix multiplication

## Lab lecture and General Information
- Janus hints 
- Discuss part A
- Discuss part B
- python example (1D)

### Quick start

1. It's best to work interactively.  Everyone should have an allocation associated with your name.  If you don't, 
please email me.  First, login.

        ssh username@login.rc.colorado.edu

2. Then add the following lines to your `.my.bash_profile`.

        module load torque/torque-4.2.3
        module load moab/moab-7.2.2 

    This will load the basic modules you need every time you login.  

3.  Create an interactive session.

        qsub -I -q janus-debug -l nodes=1:ppn=12

    Although you are only using one core, your results will be more accurate if you reserve the entire node. 

4. Download the Lab02 files from github.
    
        git clone https://github.com/ResearchComputing/HPSC-Fall-2013.git

    or, you can update your current distribution if you copied the files before modifying them.

        git pull

5. Load the lab02 module.
    
        module load HPSC_CLASS/lab02

## Part A: Pipeline Latency

###Problem 1.1 on page 34 of "Introduction to High Performance Computing for Scientists and Engineers"

- You should use `1e9` for the value of `SLICES`
- The divide latency assumption implies that, on JANUS, the maximum performance is 2800 MFLOPS.

#### Running

You will be estimating the divide latency for several different compiler settings.  Please see the 
`Makefile` for more information.  Please make sure you code works with the following commands:

    make intel-slow
    make intel-novec
    make intel-fast
    make gcc-slow
    make gcc-novec
    make gcc-fast

#### Output

In addition to anything that `make` prints out, we will be looking for <b>three</b> lines of information per run.

    time    = 3.69
    MFLOPS  = 271.003
    latency = 10.332

The time is in seconds, the MFLOPS is Mega Floating Point Operations per Second, and the latency is in seconds.

#### Report

Please include a table that summarizes these values for each of the compiler settings listed above.  Name this file `parta.txt`.


## Part B: Matrix Matrix multiply

Write a simple matrix multiply in C, C++, or FORTRAN.  I have supplied you with an example written in Python.
- Use the `generate_matrix.py` python script to generate test cases.  This is the exact code we will use to grade your
assignment. 

        python generate_matrix.py -m 10 -n 5 -f matrix.10x5
        python generate_matrix.py -m 5 -n 8 -f matrix.5x8


- Your Makefile will accept variables.  Please make sure that your program builds and runs the given arguments.  For example:

        make matrix-multiply VA=matrix.4.4 VB=matrix.4.4 VC=output4.4

    The `target` is `matrix-multiply`. Here we are squaring the `matrix.4.4` and writing the output to the file `output.4.4`.

- Please use the same output convention that we use on the input files.

        rows cols
        xxx xxx xxx xxx xxx
        xxx xxx xxx xxx ...
        xxx
        ...

    The first line contains the size of the matrix.  The next several lines are the rows of the matrix, where each element is separated by a space.

### Evaluate

Please evaluate the time it takes your code to run on the following test cases.

- 10x10
- 100x100
- 500x500
- 1000x1000

Please include a plot of this output and name it `plotb.png`.

## Check and Submit

Please submit:
- Makefile
- Any source code needed for parts A and B.
- `parta.txt`
- `partb.png`

<b> I will update the `check` and `submit` functions after Lab 01 is completed. </b>

## Grading

### Part A

- Correct values (3) for each test (6):   18 points
- Table summarizing the results:          10 points

### Part B
- Correct results on 6 tests:         18 points
- Code runs faster than python:       10 points
- partb.png  10 points

<b>total</b> 66 points























	
	