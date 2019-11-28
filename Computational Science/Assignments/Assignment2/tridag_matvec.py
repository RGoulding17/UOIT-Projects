#Name: Ryan Goulding
#Student ID: 100556101
#Written in collaboration with: Francis Hackenberger, Justin Estaris, And Andre Dallaire
#Assignment 2
"""
Question 2a

Input: vector x E R^n, a E R^n, b E R^(n-1), c E R^(n-2)
    Y = Zeros Matrix
    for(k = 1 to n) {
        if(n - k > 3)
            Y[k] = A[k,k] * x[k] + A[k+1,k] * x[k+1] + A[k+2,k] * x[k+2]
        else if(n - k  == 2)
            Y[k] = A[k,k] * x[k] + A[k+1,k] * x[k+1]
        else
            Y[k] = A[k,k] * x[k]
    }
Output: vector y E R^n such that y = Ax
"""

"""
Question 2b
Assuming inializations and conditionals are free actions

Input: vector x E R^n, a E R^n, b E R^(n-1), c E R^(n-2)                    -free action
    Y = Zeros Matrix                                                        -free action
    for(k = 1 to n) {                                                       -n flops
        if(n - k > 3)                                                       -free action
            Y[k] = A[k,k] * x[k] + A[k+1,k] * x[k+1] + A[k+2,k] * x[k+2]    -5 flops
        else if(n - k  == 2)                                                -free action
            Y[k] = A[k,k] * x[k] + A[k+1,k] * x[k+1]                        -3 flops
        else                                                                -free action
            Y[k] = A[k,k] * x[k]                                            -1 flop
    }
Output: vector y E R^n such that y = Ax                                     -free action

Complexity = 9 total flops multiplied by n loops = 9n flops
"""

import scipy
import numpy
import matplotlib.pyplot as plt
import time
import math
from compare import generateRow,generateColumn

timeArray = []
timeArray2 = []

def tridag_matvec(column, bandA, bandB, bandC):
    size = len(bandA)           #Find the size of the matrix
    Y = scipy.zeros((size,1))   #Initialize the resulting matrix
    for k in range(size):
        if (size-k) >= 3:
            #Matrix dot product
            Y[k,0] = bandA[k,0] * column[k,0] + bandB[k,0] * column[k+1,0] + bandC[k,0] * column[k+2,0]
        elif (size-k) == 2:
            Y[k,0] = bandA[k,0] * column[k,0] + bandB[k,0] * column[k+1,0]
        else:
            Y[k,0] = bandA[k,0] * column[k,0]
    return Y

"""
Question 2c
"""
#Have to lower range to 5, creates a memory error otherwise
#for k in range(2, 8):         
for k in range(2, 5):
    startTime = time.time()
    tridag_matvec(generateColumn(int(math.pow(10, k))), generateColumn(int(math.pow(10,k))), generateColumn(int(math.pow(10,k)) - 1), generateColumn(int(math.pow(10,k)) - 2))
    endTime = time.time()
    timeArray.append(endTime - startTime)
    print("Size: " + str(math.pow(10, k)), "\t\tTime: " + str(endTime - startTime))

"""
Question 2d
"""
#Have to lower range to 5, creates a memory error otherwise
#for k in range(2, 8):
for k in range(2, 5):
    startTime = time.time()
    numpy.matmul(numpy.transpose(generateColumn(int(math.pow(10,k)))), generateRow(int(math.pow(10,k))))
    endTime = time.time()
    timeArray2.append(endTime - startTime)
    print("Size: " + str(math.pow(10, k)), "\t\tTime: " + str(endTime - startTime))


#lower range by 3 since we cannot generate more due to a memory error
#xvalues = range(1,7)
xvalues = range(1,4)
plt.plot(xvalues, timeArray, '-', xvalues, timeArray2, 'g^')  #Plot the values

plt.yscale('log')   #Change the yscale to logarithmic
plt.show            #Show the graphs  