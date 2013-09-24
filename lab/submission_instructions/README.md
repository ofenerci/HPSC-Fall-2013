# Submission Instructions

You are now able to submit your work directly on Janus and the instructions are *very* simple.  We will give you access to a directory with your username for each assignment.  You will be allowed to copy, create, and run code in that directory up until the due date, at which point, we will change the permissions and grade your work.

## Example: Assignment 1

This is the directory containing my code:
        
    login04 >pwd
    /home/molu8455/projects/teaching/current/bitbucket/lab-01

To submit my code, I copy it to the `assignment-01` directory.

    login04 >cp * /curc/tools/grading/assignments/assignment-01/$USER

You can run execute in this directory if you'd like.

    login04 >cd /curc/tools/grading/assignments/assignment-01/$USER

    login04 >make clean
    rm -f *.o triad
    login04 >make
    icc -c   -c -o timing.o timing.c
    icc -c   -c -o dummy.o dummy.c
    ifort -O2 -c triad.f90 -o triad.o
    ifort -O2 timing.o dummy.o triad.o -o triad 
    login04 >make run

After the due date, when you try to access your directory, you will be denied.

    login04 >ls -l assignment-01/$USER
    ls: cannot open directory assignment-01/molu8455: Permission denied

## Privacy

Only you can see your files.

    login04 >ls -l assignment-01
    total 180
    drwx------ 2 alsi6188 root         4096 Sep 24 10:26 alsi6188
    drwx------ 2 alwe4277 root         4096 Sep 24 11:12 alwe4277
    drwx------ 2 anga0091 root         4096 Sep 24 11:13 anga0091
    ...
    drwx------ 2 trbi3060 root         4096 Sep 24 10:52 trbi3060
    drwx------ 2 tygo3699 root         4096 Sep 24 10:53 tygo3699
    drwx------ 2 xiya8696 root         4096 Sep 24 11:12 xiya8696

After the due date:

    [root@bumba assignments]# ls -l assignment-01
    total 180
    drwx------. 2 root root   4096 Sep 24 10:26 alsi6188
    drwx------. 2 root root   4096 Sep 24 11:12 alwe4277
    drwx------. 2 root root   4096 Sep 24 11:13 anga0091
    ...
    drwx------. 2 root root   4096 Sep 24 10:52 trbi3060
    drwx------. 2 root root   4096 Sep 24 10:53 tygo3699
    drwx------. 2 root root   4096 Sep 24 11:12 xiya8696



