# Author: Ryan Goulding 
# Student ID: 100556101
# Created in Collaboration with: Francis Hackenberger, Justin Estaris, Andre Dallaire""
from scipy.interpolate import interp1d

def construct_pols_piecewise(pairs, ts):
    xs = pairs[0]
    ys = pairs[1]
    
    px = interp1d(ts, xs)
    py = interp1d(ts, ys)
    
    return px, py
