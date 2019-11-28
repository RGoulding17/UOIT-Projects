# Author: Ryan Goulding
# Student ID: 100556101
# Written in collaboration with Francis Hackenberger, Justin Estaris, and Andre Dallaire
import scipy
import copy

def Hess_LUP(L,U,P,n,pivot):                                                             
    for j in range(1,n):
        s = scipy.argmax(abs(U[j-1:n,j-1])) + j -1 

        if s != j-1: 
            U = swap(U,s,j-1,n)
            P = swap(P,s,j-1,n)
            
            if j>1:
                L = swap(L,s,j-1,j-1)
        
        for i in range(j+1,n+1):
            if abs(U[j-1,i-1]) < pivot:
                #we reached a pivot point
                break
            if not (i>j+1):
                L[i-1,j-1] = U[i-1,j-1]/U[j-1,j-1]
                for k in range(j,n+1):
                    U[i-1,k-1] = U[i-1,k-1] - L[i-1,j-1] * U[j-1,k-1]
    return L,U,P

def swap(M,i,j,k):
    dum = copy.copy(M[i,0:k])
    M[i,0:k] = copy.copy(M[j,0:k])
    M[j,0:k] = copy.copy(dum)
    return M  