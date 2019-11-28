#SON algorithm
#Author Ryan Goulding
#Student ID 100556101
from itertools import combinations
import time

# counts every apperance of every item in a given basket
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

#open the file, read a chunk of 255 bytes
with open(filename) as f:
    while True:
        #reset itemcounts for chunk
        itemCounts = {}
        basketCombos = []
        #chunk data
        chunk = f.readlines(255)
        #if the chunk is empty, break out of loop
        if not chunk:
            break
        #process item counts and append supported items to list
        for basket in chunk:
            basketCombos.append(combinations(basket.split(),2))
            item_counts(basket.split())
        for entry in basketCombos:
            for combo in entry:
                if itemCounts[combo[0]]>=support and itemCounts[combo[1]]>=support and combo not in candidatePairs:
                    candidatePairs.append(combo)
            
with open('son_results.dat', 'w') as f:
    for pair in candidatePairs:
        f.write("%s\n" % str(pair))

endTime = time.time()
totalTime = endTime - startTime
print("Time to complete: ", totalTime)