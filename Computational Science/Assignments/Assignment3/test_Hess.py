# Author: Ryan Goulding
# Student ID: 100556101
# Written in collaboration with Francis Hackenberger, Justin Estaris, and Andre Dallaire
import numpy as np
import matplotlib.pyplot as plt
import time
from Hess_LUP import Hess_LUP

def generateMatrix(n):
    for i in range(0,n):
        for j in range(0,n):
            if not (i>j+1):
                U[i,j]= np.random.randint(-10,high=10)
            else:
                U[i,j]=0
    return U

pivot = 1e-12
time_results = []

for p in range(4,12):
    n=2**p
    L = np.identity(n)
    U = np.identity(n)
    P = np.identity(n)
    U = generateMatrix(n)
    
    start = time.time()
    Hess_LUP(L,U,P,n,pivot)
    stop = time.time()
    time_results.append(stop-start)
    
#plot results
ymax = np.amax(time_results)+np.amax(time_results)/10
plt.ylim(0,ymax)
plt.ylabel("Runtime (in seconds)")
plt.xlabel("n^p")
plt.plot([16,32,64,128,256,512,1024,2048],time_results) 
plt.show()