# Author: Ryan Goulding
# Student ID: 100556101
# Written in collaboration with: Francis Hackenberger, Justin Estaris, Andre Dallaire
import scipy as sc
import scipy.linalg as la

A = sc.matrix([-2.0,0.25,0.9,1.0])
b = sc.matrix([1.23,3.29,4.12,4.30])
xstar = la.lstsq(A,b)
print(xstar[0],xstar[3])