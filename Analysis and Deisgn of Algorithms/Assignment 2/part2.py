# -*- coding: utf-8 -*-
"""
Created on Mon Nov 18 14:43:57 2019

@author: Ryan Goulding & Justin Estaris
"""
import random

def getDigit(num, digit):
    working = num // 10**digit
    newNum = working % 10
    return newNum


def RadixSort(maxDigits,numbers):
    for i in range(0, maxDigits):
        
        counts = [0] * 10
        sortedArray = [0] * len(numbers) 
        
        for n in numbers:
            counts[getDigit(n,i)] += 1
            
        for k in range(1,10):
            counts[k] += counts[k-1]
        
        for j in reversed(numbers):
            index = getDigit(j,i)
            sortedArray[counts[index]-1] = j
            counts[index] -= 1      
        
        for i in range(len(numbers)):
            numbers[i] = sortedArray[i]
    
    return numbers


numbers = list(range(0, 1000000))
random.shuffle(numbers)

maxNum = max(numbers)
maxDigits = len(str(maxNum))

RadixSort(maxDigits,numbers)

    
    

