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

You might find this [tutorial](http://researchcomputing.github.io/support/) helpful.

Here is a good tutorial on using [modules](http://www.admin-magazine.com/HPC/Articles/Environment-Modules).

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

### Assignment (in 10 steps)

If you have issues with any of these steps, please email us and we will help you get up and running.

1. log into JANUS.  Replace `username` with your CU username.

    ```
    ssh username@login.rc.colorado.edu
    ```

  This will take you to a login host.  Type `hostname` to verify.

2. Let's move to a different host so tha we are not running code on the login nodes.  For this assignment, you can use one of the janus-compile* nodes. Type one of the following lines:

  ```
  ssh janus-compile1
  ssh janus-compile2
  ssh janus-compile3
  ssh janus-compile4
  ```

3. We will be running a simple benchmark experiment from Chapter 1 of your book.  To start make sure you have the latest copy of our github repository.  To clone the repository (one step, easy to update) type:

    ```
    git clone https://github.com/ResearchComputing/HPSC-Fall-2013.git
    ```

  You now have a directory structure like `/home/username/HPSC-Fall-2013`. 

4. Change into the lab01 directory.

  ```
  cd HPSC-Fall-2013/lab/lab-01
  ```

5. We have provided you with a basic `Makefile`. Make sure you can compile the code before you move on to the assignment.  To do this load the intel module, and type `make`:

  ```
  module load intel/intel-13.0.0
  make
  ```

6. __Modify the Makefile__

   Use patterns `%` and automatic variables `$@,$<` like we did in lab.  Your goal is to not specify the exact target for any `.c` or `.f90` files. 
  This means do not include the string literals `dummy.c`,
  `triad.f90` in your final Makefile.  This is exactly what we did in lab. Type `make` to be sure it is still working.

  ```
  make
  ```

7. __Scaling study__

  Once you have built the `triad` executable, you can run a single experiment by passing the value of `N` as an input.  You can run this on the command line by typing:

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

8. Add a `run` target to your Makefile that will generate `scaling.csv` when we type:

  ```
  make run
  ```

9. __Plot__

  Use your favorite plotting language to make a `.png` plot of your data.  Please include correctly labeled `x` and `y` axis and a title that include a description of the JANUS architecture.  Here is the one from lab, please feel free to copy it if you'd like.

  ```
  Performance vs Array Size \nIntel Xeon CPU X5660 @ 2.80GHz 12288 KB Cache
  ```


10. __Submission__

  You can check to make sure you have done most of the work by running the `check` command.  In the directory with your work, type:

  ```
  /curc/tools/grading/scripts/check
  ```

  I've added the `make check` to the repository `Makefile`. Please create a tar file of your work and submit it to d2l.  Please name the file 
  assignment1.tar`.  Please be sure to include the following files:
  - Makefile
  - scaling.png
  - you script file for generating the scaling results
  - any other files your program uses

























