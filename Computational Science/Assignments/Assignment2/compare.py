import scipy
from random import randint

def generateRow(size):
    A = scipy.zeros((size, size))       #Generate 0 matrix
    for k in range(size):
        if (size-k) >= 3:               #Check condition for a,b,c
            A[k,k] = randint(-10,10)    #Fill in the diagonal (a values)
            A[k, k+1] = randint(-10,10) #Fill in the b values
            A[k, k+2] = randint(-10,10) #Fill in the c values
        elif (size-k) == 2:             #Check condition for a,b
            A[k,k] = randint(-10,10)    #Fill in the A values
            A[k,k+1] = randint(-10,10)  #Fill in the b values
        else:                           #Output final a
            A[k,k] = randint(-10,10)    #Fill in the a value
    return A
    
def generateColumn(size):
    A = scipy.zeros((size, 1))          #Generate 0 matrix
    for k in range(size):
        A[k,0] = randint(0,10)          #Fill in the columns with random values
    return A