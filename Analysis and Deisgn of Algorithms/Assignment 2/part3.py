# -*- coding: utf-8 -*-
"""
Created on Tue Nov 19 13:11:31 2019

@author: ryan gouldig & justin estaris

"""
def FractionalKnapsack(capacity,values,weights):
    ratios = [0] * len(values)
    weight  = 0
    
    for i in range(len(values)):
        if  weight  + weights[i] <= capacity :
            ratios[i] = 1
            weight += weights[i]
        else:
            ratios[i] = (capacity- weight)/weights[i]
            weight = capacity
            break
    return ratios

values = [280,100,120,120]
weights = [40,10,20,24]
knapsackCapacity = 60;

#returns percentage of values/weights to fill our backpack
ratios = FractionalKnapsack(knapsackCapacity,values,weights)
print("ratio of weights/values to take: ",ratios)
print("Gives total value: ", sum(values*ratios for values, ratios in zip(values,ratios)))