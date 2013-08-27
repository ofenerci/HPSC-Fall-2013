## Getting Started

We will be using the JANUS supercomputer.
Please [apply for an account](https://www.rc.colorado.edu/accountrequest) before you come to class.

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
- Assignment
  - Create a `Makefile` for a benchmark code.
  - Generate some data using `Python` or another language of your choice
  - Plot the data (we will help with this)
  - Check the assignment 
  - Submit the assignment

### Getting started with Janus

http://researchcomputing.github.io/support/

### Makefiles

### Git

[Bitbucket ssh key help](https://confluence.atlassian.com/display/BITBUCKET/Set+up+SSH+for+Git)

To generate an ssh key, type:

    ssh-keygen

When prompted for a filename, enter `id_bitbucket`.  This will create two keys (files) in your `~/.ssh` directory: 
a public and private key.
    
    id_bitbucket.pub 
    id_bitbucket

Now we add this to our `~/.ssh/config` file.

    touch ~/.ssh/config
  
Open the file and add the following lines:

    Host bitbucket.org 
      IdentityFile ~/.ssh/id_bitbucket

Install the public key on your Bitbucket account.  See [step 6](https://confluence.atlassian.com/display/BITBUCKET/Set+up+SSH+for+Git).
Make sure everything works:

    ssh -T git@bitbucket.org

### Assignment



