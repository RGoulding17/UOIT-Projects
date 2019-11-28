# Author: Ryan Goulding 
# Student ID: 100556101
# Created in Collaboration with: Francis Hackenberger, Justin Estaris, Andre Dallaire
from scipy.interpolate import lagrange

def construct_pols(pairs, ts):
    xs = pairs[0]
    ys = pairs[1]
    
    px = lagrange(ts, xs)
    py = lagrange(ts, ys)
    
    return px, py
