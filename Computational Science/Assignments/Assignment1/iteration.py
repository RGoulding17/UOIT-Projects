"""
@Filename: iteration.py

@Name: Ryan Goulding
@Student #: 100556101
This code was written in collaboration with Justin Estaris, Francis Hackenberger, Andre Dallaire
"""
import math as math

#g(x) from assignment document
def g(x):
    return (1/(2*math.pi))*math.sin(math.pi * x) - (1/(2*math.pi))*(math.pow(x,2)) + x

#Question 1 C
def sequenceFunction(x0, kMax, epsError, epsResidual):
    x_prev = x0             #set previous x to inital x value x(k-1)
    x = g(x0)               #set x to equal the function g with the initial x as its input
    convergence = 0.00      #declare and set convergence to 0.0
    
    #loop from 0 to KMax
    for k in range(0, kMax):
        x_prev = x              #set previous x to current x
        x = g(x)                #calculate new x
        err = abs(x_prev - x)   #calculate absoulte error
        res = abs(x)            #calculate absolute residual
        
        print("Iteration:", str(k), "err:", str(err), "res:", res)
        
        #Check for epsilon values
        if err < epsError and res < epsResidual:
            print("Converged!")
            convergence = 1.00
            break

    #if the loop ends and convergence hasn't changed, we've failed
    if convergence == 0:
        print("Didn't converge")

    return(x, err, res)

#Test some values
print(str(sequenceFunction(1, 50, 1e-7, 1e-7)) + "\n\n")


#Question 1 D
iteration = 0       #Set a global variable for the iteration counter

def sequenceFunctionRecursion(x0, k, epsError, epsResidual):
    x_prev = x0             #set previous x to inital x value x(k-1)
    x = g(x0)               #calculate new x
    global iteration        #Call the global iteration variable
    iteration += 1          #Increase the iteration counter by 1
    err = abs(x_prev - x)   #calculate absoulte error
    res = abs(x)            #calculate absolute residual
    if k > 0:
        print("Iteration:", str(iteration), "err:", str(err), "res:", res)
        
        if err < epsError or res < epsResidual:    #Check for epsilon values
            print("Converged")
            return(x, err, res)
        x, err, res = sequenceFunctionRecursion(x, k-1, epsError, epsResidual) #Recursive call
        
    else:
        print("Didn't converge!")
        
    return(x, err, res)
        

#Test some values
print(str(sequenceFunctionRecursion(1, 50, 1e-7, 1e-7))+"\n\n")


#Question 1 E
"""
1e) What happens when x0 is 0:
        When x0 equals 0, the function for both x and x_prev are 0. Which makes err 
        equal to 0 and res equal to 0. Which are both lower than the epsilon
        values. 
    What happens when x0 is <0:
        There is a math out of range overflow which is caused by the err and res
        growing too large for the interpreter to handle.
"""