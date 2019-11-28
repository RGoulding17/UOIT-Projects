from itertools import combinations
import numpy as np
import time

support = 2
filename = 'sample_retail.dat' #change this to retail.dat for full data
itemCounts = {}
candidateNumbers = []
candidatePairs = []
startTime = time.time()

#chunk input file with random sampling    
num_lines = sum(1 for line in open(filename))

# set sample size to 5% of file
n = int(num_lines * 0.05)

#count appearence of each number
with open(filename) as f:
    fileContents = list(f)
    while True:
        itemCounts = {}
        try:
            chunk = np.ndarray.tolist(np.random.choice(fileContents,size=n))
            fileContents = [x for x in fileContents if x not in chunk]
        except:
            break   
        for basket in chunk:
            for item in basket.split():
                if str(item) in itemCounts:
                    itemCounts[str(item)] +=1
                else:
                    itemCounts[str(item)] =1
        for item in itemCounts:
            if itemCounts[str(item)]>=support and item not in candidateNumbers:
                candidateNumbers.append(item)

with open(filename, 'r') as f:
    for basket in f:
        basketCombos = combinations(basket.split(),2)  
        for combo in basketCombos:
            if combo[0] in candidateNumbers and combo[1] in candidateNumbers:
                candidatePairs.append(combo)

##store results to results.dat
with open('results.dat', 'w') as f:
    for pair in candidatePairs:
        f.write("%s\n" % str(pair))
        
endTime = time.time()
totalTime = endTime - startTime
print("Time to complete: ", totalTime)