# Author: Ryan Goulding 
# Student ID: 100556101
# Created in Collaboration with: Francis Hackenberger, Justin Estaris, Andre Dallaire
'''
#Part A - set t values pseudocode
function set t values (points)
    Tlist = array inialized with 1 zero inside
    for i in length(points[getX's]):
        Tlist.append(FindEuclidian(Tlist, Points[getX's]))
    
    output Tlist

#Part B contructs pols pseudocode
Function contruct_pols(points, Tlist)
    xlist = get X's from points[]
    ylist = get Y's from points[]
    
    px = GetLagrange(Tlist, xlist)
    py = GetLagrange(Tlist, ylist)
    
    output px & py
'''