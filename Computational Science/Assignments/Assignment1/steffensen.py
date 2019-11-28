"""
@Filename: steffensen.py

@Name: Ryan Goulding
@Student #: 100556101
This code was written in collaboration with Justin Estaris, Francis Hackenberger, Andre Dallaire
"""
#Question 2 A & B
#importing the Math Library
import math

#This function returns result of the equation 
def f(x):
    return math.exp(-(x ** 2) + x) - (x / 2) - 1.0836

#This function returns result of the equation 
def df(x):
    return ((-2 * x + 1) * math.exp(-(x ** 2) + x)) - (1 / 2)

#This is the steffensen function 
#The inputs are x, error, and residual
#The ouput x* 
def steffensen(x0, kMax, epsilon):
    x = x0
    for i  in range(0, kMax):       # Repeat N Times
        y1 = x                      # Set y1 = x
        y2 = y1 - (f(y1) / df(y1))  # One Newton step, starts from y1 and calls the result y2
        y3 = y2 - (f(y2) / df(y2))  # One Newton step, starts from y2 and calls the result y3  
        x = y1 - (((y2 - y1) ** 2) / (y3 - (2 * y2) + y1)) #Set X to be the equation
        residual = abs(f(x))
        print("Iteration = %d, approximation = %e, residual = %e" %(i, x, residual))
        
        # If |f(x)| < episilon print "converged!"
        if residual < epsilon:
            print ("converged!")
            break
    # Print the solution
    print("solution = %e, residual = %e" %(x, residual))
    
# Code pulled from Lecture 4
def Newton(x0, kmax, tolf, tolx):
    x = x0
    conv = 0
    for i in range(1, kmax + 1):
        r = f(x)
        dx = -r/df(x)
        x = x + dx
        err = abs(dx)
        residual = abs(r)
        print('Iteration = %d x = %e error = %e residual = %e' % (i, x, err, residual))
        if err < tolx and residual < tolf:
            conv = 1
            break
    if conv == 0:
        print('No convergence!')
    return x,err,residual

print("Steffensen: ", steffensen(1, 10, 1e-6))
print("Newton: ", Newton(1, 10, 1e-6, 1e-6))