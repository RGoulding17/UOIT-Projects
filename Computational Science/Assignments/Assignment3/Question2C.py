#Assignment 3 - Question 2 c)
# Student ID: 100556101
# Written in collaboration with Francis Hackenberger, Justin Estaris, and Andre Dallaire
import numpy as np
import matplotlib.pyplot as plt

# 1. Forms the Vandermonde Matrix         
x = np.array([0, 1, 2, 3, 4])   # x_k
y = np.array([0, 1, 5, 14, 35]) # y_k
V = np.vander(x, 5)             # Vandermonde matrix
print("Vandermonde Matrix: ")
print(V)

# 2. Solves the linear system corresponding to the interpolation conditions
def evaluate(x, y, V):
    a = np.dot(np.linalg.inv(V), y)
    print("Coeffcients: ", a)
    total = 0
    for k in range(len(a)):
        total += (x**k) * a[len(a)-1-k]
    return total

# 3. Produce a figure that shows the interpolant as well as the points in the table
plt.figure()
points = np.linspace(0, 5)
plt.plot(points, interpolate(points, y, V))
plt.plot(x, y, 'bo')
plt.legend(['Interpolant', 'Points'])
plt.show()