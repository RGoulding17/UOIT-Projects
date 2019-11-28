#SON with Random Sampling algorithm 
from itertools import combinations, islice
import time 
import numpy as np

def item_counts(basket):
    for item in basket:
        if item in itemCounts:
            itemCounts[item]+=1
        else:
            itemCounts[item] = 1    

support = 2
filename = 'retail.dat' #change this to retail.dat for full data
itemCounts = {}
combos = []
candidateNumbers = []
candidatePairs = []
startTime = time.time()

with open(filename) as f:
    while True:
        itemCounts = {}
        chunk = f.readlines(255)
        if not chunk:
            break
        for basket in chunk:
            item_counts(basket.split())
        for item in itemCounts:
            if itemCounts[item]>=support and item not in candidateNumbers:
                candidateNumbers.append(item)
                
with open(filename) as f:
    for basket in f:
        basketCombos = combinations(basket.split(),2)
        for combo in basketCombos:
            if combo[0] in candidateNumbers and combo[1] in candidateNumbers and combo not in candidatePairs:
                candidatePairs.append(combo)
            
with open('son_rs_results.dat', 'w') as f:
    for pair in candidatePairs:
        f.write("%s\n" % str(pair))

endTime = time.time()
totalTime = endTime - startTime
print("Time to complete: ", totalTime)