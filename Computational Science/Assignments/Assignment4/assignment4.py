# Author: Ryan Goulding 
# Student ID: 100556101
# Created in Collaboration with: Francis Hackenberger, Justin Estaris, Andre Dallaire
import numpy as np
import matplotlib.pyplot as plt
from set_t_values import set_t_values
from construct_pols import construct_pols
from construct_pols_piecewise import construct_pols_piecewise

pairs = [[0.0, 0.5, 1.1, 1.0, 0.2], \
         [2.0, 2.5, 2.7, 2.0, 2.1]]

ts = set_t_values(pairs)

px, py = construct_pols(pairs, ts)

newValues = np.linspace(ts[0], ts[-1], 100)

#plot
plt.ylabel("PY values")
plt.xlabel("PX values")
plt.scatter(px(ts),py(ts))
plt.plot(px(newValues),py(newValues)) 
plt.show()

pairs = [[0.0, 0.5, 1.1, 1.0, 0.2, 0.00, -0.3], \
         [2.0, 2.5, 2.7, 2.0, 2.1, 2.15, 2.15]]

ts = set_t_values(pairs)
newValues = np.linspace(ts[0], ts[-1], 100)
px, py = construct_pols(pairs, ts)
#plot
plt.ylabel("PY values")
plt.xlabel("PX values")
plt.scatter(px(ts),py(ts))
plt.plot(px(newValues),py(newValues)) 
plt.show()

newValues = np.linspace(ts[0], ts[-1], 100)
px, py = construct_pols_piecewise(pairs, ts)
#plot
plt.ylabel("PY values")
plt.xlabel("PX values")
plt.scatter(px(ts),py(ts))
plt.plot(px(newValues),py(newValues)) 
plt.show()