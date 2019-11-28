# Author: Ryan Goulding 
# Student ID: 100556101
# Created in Collaboration with: Francis Hackenberger, Justin Estaris, Andre Dallaire
import math

def set_t_values(pairs):
    ts = [0]
    for i in range(1, len(pairs[0])):
        ts.append(ts[i - 1] + math.sqrt(((pairs[0][i] - pairs[0][i - 1]) ** 2) + ((pairs[1][i] - pairs[1][i - 1]) ** 2)))
    
    return ts