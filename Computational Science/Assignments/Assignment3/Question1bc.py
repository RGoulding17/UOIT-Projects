# Author: Ryan Goulding
# Student ID: 100556101
# Written in collaboration with Francis Hackenberger, Justin Estaris, and Andre Dallaire

#Question 1b
'''
def Hess_LUP(L,U,P,n,pivot):                                                             
    for j columns in range(1,n):
        s = scipy.argmax(abs(U[j-1:n,j-1])) + j -1 
        
        if the largest number isn't on the diagonal, 
            U = swap(U,s,j-1,n)
            P = swap(P,s,j-1,n)
            
            if j is greater than 1
                L = swap(L,s,j-1,j-1)
        
        for i rows in range(1,n):
            if abs(U[j-1,i-1]) < pivot:
                we reached a pivot point, break
            if !(i>j+1): (not a zero)
                L[i-1,j-1] = U[i-1,j-1]/U[j-1,j-1]
                for k in range(j,n+1):
                    U[i-1,k-1] = U[i-1,k-1] - L[i-1,j-1] * U[j-1,k-1]
            else
                Lij = 0
    return L,U,P

def swap(M,i,j,k):
    dum = copy.copy(M[i,0:k])
    M[i,0:k] = copy.copy(M[j,0:k])
    M[j,0:k] = copy.copy(dum)
    return M      
'''

#Question 1c
'''
def Hess_LUP(L,U,P,n,pivot):                                                         
    for j columns in range(1,n):                                            multiply flop's by n
        s = scipy.argmax(abs(U[j-1:n,j-1])) + j -1                          5 flops
        
        if the largest number isn't on the diagonal, 
            U = swap(U,s,j-1,n)                                             1 flop
            P = swap(P,s,j-1,n)                                             1 flop
            
            if j is greater than 1
                L = swap(L,s,j-1,j-1)                                       2 flop
        
        for i rows in range(1,n):                                           multiply flop's by n
            if abs(U[j-1,i-1]) < pivot:                                     3 flops
                we reached a pivot point, break
            if !(i>j+1): (not a zero)                                       1 flop for addition
                L[i-1,j-1] = U[i-1,j-1]/U[j-1,j-1]                          7 flops
                for k in range(j,n+1):                                      multiply flop's by n
                    U[i-1,k-1] = U[i-1,k-1] - L[i-1,j-1] * U[j-1,k-1]       10 flops
            else
                Lij = 0
    return L,U,P

def swap(M,i,j,k):
    dum = copy.copy(M[i,0:k])
    M[i,0:k] = copy.copy(M[j,0:k])
    M[j,0:k] = copy.copy(dum)
    return M  
    
    
TOTAL FLOPS = (5+1+1+2+3+1+7+10)*n*n*n = 30n^3
'''