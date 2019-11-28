#Random Sampling algorithm 
#Author Ryan Goulding
#Student ID 100556101
from itertools import combinations
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
candidatePairs = []
startTime = time.time()

#chunk input file with random sampling    
num_lines = sum(1 for line in open(filename))

# set sample size to 5% of file
n = int(num_lines * 0.05)

# open the file and read a random selection of n lines from filename
with open(filename) as f:
    itemCounts = {}
    #take random sample n
    sample = list(np.random.choice(list(f.readlines()),n))
    for basket in sample:
        #count every apperance of every item for each basket                                                               
        item_counts(basket.split())
                
with open(filename) as f:
    for basket in f:
        # create all possible pairings from basket
        basketCombos = combinations(basket.split(),2)                                   
        for combo in basketCombos:
            try:
                 # try to see if the tuple is supported
                if itemCounts[combo[0]]>=support and itemCounts[combo[1]]>=support:
                    candidatePairs.append(combo)                                      
            except:
                # if we fail, that means the one of the elements in the tuple was never seen
                pass                                                                    

# write elements to results file           
with open('rs_results.dat', 'w') as f:                                                  
    for pair in candidatePairs:
        f.write("%s\n" % str(pair))

endTime = time.time()
totalTime = endTime - startTime
print("Time to complete: ", totalTime)