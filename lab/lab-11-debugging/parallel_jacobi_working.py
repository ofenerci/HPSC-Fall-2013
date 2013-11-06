#!/usr/bin/env python
from mpi4py import MPI
import numpy as np
import math

class ParallelJacobi:

    def __init__(self, **kwargs):
        
        self.comm = MPI.COMM_WORLD
        self.rank = self.comm.rank
        self.size = self.comm.size

        self.T = kwargs.get('T', 2.0)
        self.R = kwargs.get('R', 2.0)
        self.B = kwargs.get('B', 1.0)
        self.L = kwargs.get('L', 1.0)
        default_n = math.sqrt(self.size*4) # ghost
        self.n = kwargs.get('n', default_n ) + 2
 
        self.create_cart()
        self.neighbors()
        self.create_matrix()
        self.create_sub_matrix()

        self.ghost_create_matrix()

    # Thomas went over these methods
    def create_cart(self):
        N = 2
        dims = MPI.Compute_dims(self.size, N) # MPI_Dims_create in C
        self.c_comm = self.comm.Create_cart(dims, [False, False], True) # MPI_Cart_create in C
        self.c_rank = self.c_comm.Get_rank()
        self.c_size = self.c_comm.Get_size()

    def neighbors(self):
        self.top, self.bottom = self.c_comm.Shift(0, 1)
        self.left,  self.right  = self.c_comm.Shift(1, 1)

    # Use neighbors to fill in borders
    def create_sub_matrix(self):
        self.sub_n = (self.n-2)/float(math.sqrt(self.size)) + 2 # ghost boundary
        self.sub_A = np.zeros((self.sub_n, self.sub_n))

        if self.top == -2:
            self.sub_A[0,:] = int(self.T)     # Top
        if self.bottom == -2:
            self.sub_A[self.sub_n-1,:] = int(self.B)  # Bottom
        if self.left == -2:
            self.sub_A[:,0] = int(self.L)     # Left
        if self.right == -2:
            self.sub_A[:,self.sub_n-1] = int(self.R)  # Right
        
    def create_matrix(self):
        self.A = None
        if self.c_rank == 0:
            self.A = np.zeros([self.n, self.n], dtype=np.float64)
            self.A[0,:] = int(self.T)     # Top
            self.A[self.n-1,:] = int(self.B)  # Bottom
            self.A[:,0] = int(self.L)     # Left
            self.A[:,self.n-1] = int(self.R) 

    # Shift methods
    def communicate(self):
        self._shift_up()
        self._shift_down()
        self._shift_right()
        self._shift_left()

    def _shift_down(self):
        pass

    def _shift_up(self):
        pass

    def _shift_right(self):
        pass

    def _shift_left(self):
        pass
 
    # Gather methods
    def gather_matrix(self):
        pass
    
    # Test these methods
    def test_gather(self):
        pass

    def test_shift(self):
        pass

    # Print methods
    def printstate(self):
        self.gather_matrix()
        if self.c_rank == 0:
            print ''
            for i in range(1,self.A.shape[0]-1):
                if i % (self.sub_n -2) and i !=1:
                    print '-'*6*(self.A.shape[0])
                for j in range(1,self.A.shape[1]-1):
                    if j % (self.sub_n -2) and j != 1:
                        print '|',
                    print "{:6.2f}".format(self.A[i,j]),
                print ''
            print ''

    def iterate(self):
        A_new = self.sub_A.copy()
        for i in np.arange(1., self.sub_n-1):
            for j in np.arange(1.,  self.sub_n-1):
                A_new[i,j] = (self.sub_A[i,j+1] + self.sub_A[i,j-1] + self.sub_A[i-1,j] + self.sub_A[i+1,j])*0.25
    
        self.sub_A = A_new.copy()
        

