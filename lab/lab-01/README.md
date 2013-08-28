## Getting Started

We will be using the JANUS supercomputer.
Please [apply for an account ](https://www.rc.colorado.edu/accountrequest) before you come to class.

### Goals

- Access the JANUS supercomputer
  - Learn to run code interactively
  - Learn to submit jobs
- Makefiles
  - We will use these for building code
  - Quick introduction
- Git
  - Recommended
  - Use [bitbucket](https://bitbucket.org/), it's private.
  - Use [github](https://github.com/), five private with edu address.
- Assignment
  - Create a `Makefile` for a benchmark code.
  - Generate some data using `Python` or another language of your choice
  - Plot the data
  - `submit` the assignment
  - `check` the assignment 

### Getting started with Janus

http://researchcomputing.github.io/support/

http://www.admin-magazine.com/HPC/Articles/Environment-Modules

### Makefiles

- Quick lecutre

### Git (optional)

Learn Git in 15 minutes
- http://try.github.io/levels/1/challenges/1

Bitbucket
- Create an account on [bitbucket.org](https://bitbucket.org).
- Add [ssh access](https://gist.github.com/mlunacek/6353920).

Github
- Request an edu account on [github.com](https://github.com/edu)
- Add ssh keys in a similar way.

### Assignment

We will be running a simple benchmark experiment from Chapter 1 of your book. 
To start make sure you have the latest copy of our github repository.
There are a few ways you can do this:
* Download the ZIP file
* Download the TAR ball
* Clone the repository

```
git clone https://github.com/ResearchComputing/HPSC-Fall-2013.git
```

We have provided you with a basic `Makefile`. Make sure you can compile the code
before you move on to the assignment.  To do this, start an interactive session, load the intel module, and type `make`:


```
qsub -I -q janus-debug -l nodes=1:ppn=1
module load intel/intel-13.0.0
make
```

#### A. Makefile

Modify the Makefile to use patterns `%` and automatic variables `$@,$<`.  Your goal is to not specify the exact target for any `.c` or `.f90` files. 
For example, this translates to mean do not include the string literals `dummy.c`,
`triad.f90` in your final Makefile.  This is exactly what we did in lab.

#### B. Scaling study

Once you have built the `triad` executable, you can run a single experiment 
by passing the value of `N` as an input.  You can run this on the command line 
by typing:

```
echo 10 | ./triad
```

You will see the following output.

```
 Length:           10    MFLOP/s:    1728.43411262444 
```

Write a script that will execute this script over the following N values:

```
10, 1e2, 1e3, 1e4, 1e5, 1e6, 1e7, 1e8
```

Your program should create a comma separated file (.csv) named `scaling.csv`.
Please do not put any spaces after the commas and include the header `key,value`. Your file should look similar to this.

```
key,value
1,621.206034092470
10,1591.33477486212
100,3516.33795512399
...
```

Add a `run` target to your Makefile that will generate `scaling.csv` when we type:

```
make run
```

#### C. Plot

Use your favorite plotting language to make a `.png` plot of your data.  Please 
include correctly labeled `x` and `y` axis and a title that include a description of the JANUS architecture.

Add a `plot` command you your Makefile that will generate `scaling.png` when we type:

```
make plot
```

#### Submission

Still working on this. 


























