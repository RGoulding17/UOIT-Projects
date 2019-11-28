# Author: Ryan Goulding
# Student ID: 100556101
# Written in collaboration with: Francis Hackenberger, Justin Estaris, Andre Dallaire
import scipy.interpolate as sc
import numpy as np
import matplotlib.pyplot as plt
import math

def F(x):
    results = []
    for num in x:
        results.append(math.log((num+2)/(num+1)))
    return results

X = [0,1,3]
Y = [np.log(2.0),np.log(3.0/2.0),np.log(4.0/3.0)]
P = sc.lagrange(X,Y)


x = np.linspace(0,3,num=1000)
# find iterpolated values 1a
plt.plot(x, F(x))
plt.plot(x, P(x))
plt.title("Interpolated Vs. Function Values")
plt.xlabel("Function Values")
plt.ylabel("Interpolated Values")
plt.show()

# find interpolated error
plt.plot(x,abs(F(x)-P(x)))
plt.title("Error Values")
plt.xlabel("Domain")
plt.ylabel("Error of Interpolated Values")
plt.show()