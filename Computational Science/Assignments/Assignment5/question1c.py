# Author: Ryan Goulding
# Student ID: 100556101
# Written in collaboration with: Francis Hackenberger, Justin Estaris, Andre Dallaire
import matplotlib.pyplot as plt
import numpy as np
import scipy.interpolate as sc
import math

def F(x):
    results = []
    for num in x:
        results.append(math.log((num+2)/(num+1)))
    return results

errors = []

for M in range(3,100):
    # generate grid
    x = np.linspace(0,3,M)
    
    #interpolant calc
    y = F(x)
    interpolatedPoly = sc.lagrange(x,y)
    interpolatedValues = interpolatedPoly(x)
    
    #error calc
    errorValue = max(abs(y-interpolatedValues))
    
    #append error
    errors.append(errorValue)

#plot results
plt.loglog(np.arange(3,100),errors)
plt.show()