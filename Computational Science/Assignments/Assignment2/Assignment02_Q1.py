#Author: Ryan Goulding 
#Student ID: 100556101
#Code written in collaboration with Francis Hackenberger, Justin Estaris and Andre Dallaire
#Assignment 2

import scipy
from scipy import linalg as slin
from numpy import linalg as nlin

# Q1 a)
A = [[1,2,-4],[2,4,1],[-2,-1,3]]
B = [[2,0,-4],[2,-4,1],[2,10,3]]
C = [[2,0],[50,1]]
R = [[2],[-3],[1]]

""" Matrix LU decomposition
    1  2 -4          1  0  0         1  0  0
U = 2  4  1     P =  0  1  0    L =  0  1  0
   -2 -1  3          0  0  1         0  0  1
   
----------------------------------------------------

    2  4  1          0  1  0         1  0  0
U = 1  2 -4     P =  1  0  0    L =  0  1  0
   -2 -1  3          0  0  1         0  0  1

----------------------------------------------------

    2  4  1          0  1  0         1  0  0
U = 0  0 -9/2   P =  1  0  0    L = 1/2 1  0
    0  3  4          0  0  1        -1  0  1
   
----------------------------------------------------

    2  4  1          0  1  0         1  0  0
U = 0  3  4     P =  0  0  1    L = -1  1  0
    0  0 -9/2        1  0  0        1/2 0  1
"""

P, L, U = slin.lu(A)

# Q1 b)
P = scipy.transpose(P)
R = scipy.dot(P, R)
Y = slin.solve_triangular(L, R, lower=True)
DX = slin.solve_triangular(U, Y, lower=False)

print(DX)

"""
x1 = [-1.85185185]
x2 = [ 0.37037037]
x3 = [-0.77777778]
"""

# Q1 c)
"""
 2  0 -4   2
 2 -4  1  -3
 2 10  3   1
 
 2  0 -4   2
 0 -4  5  -5
 0 10  7  -1
 
 2  0 -4      2
 0 -4  5     -5
 0  0  19.5  -13.5
 
 x1 = -5/13
 x2 =  5/13
 x3 = -9/13
"""

# Q1 d)
print("Condition number: " + nlin.cond(C).astype(str))

""" 
The condition number is 1252, we found that q=3.
Therefore we can copute 3 digits less, which gives us
an accuracy of 2 for x.
"""