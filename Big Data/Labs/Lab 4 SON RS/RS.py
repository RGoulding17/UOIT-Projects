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

#chunk input file with random sampling    
num_lines = sum(1 for line in open(filename))

# set sample size to 5% of file
n = int(num_lines * 0.05)

with open(filename) as f:
    itemCounts = {}
    sample = list(np.random.choice(list(f.readlines()),n))
    for basket in sample:
        item_counts(basket.split())
                
with open(filename) as f:
    for basket in f:
        basketCombos = combinations(basket.split(),2)
        for combo in basketCombos:
            try:
                if itemCounts[combo[0]]>=support and itemCounts[combo[1]]>=support:
                    candidateNumbers.append(combo)
            except:
                pass
            
with open('son_rs_results.dat', 'w') as f:
    for pair in candidatePairs:
        f.write("%s\n" % str(pair))

endTime = time.time()
totalTime = endTime - startTime
print("Time to complete: ", totalTime)