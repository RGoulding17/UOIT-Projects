#APRIORI ALGORITHM 
#Author Ryan Goulding
#Student ID 100556101
from itertools import combinations
import time

support = 5                 # the support threshold 
filename = 'netflix.data'     # change this to retail.dat for full data
apiori = []                 # list to hold all suppport pairs
initialCounts = {}          # dictionary to hold item counts
startTime = time.time()     # get current time
output = open('netflix_apriori_results.dat', 'w')

#count appearence of each number
with open(filename, 'r') as f:
    for basket in f:
        for item in basket.split():
            if item in initialCounts:
                initialCounts[item] +=1
            else:
                initialCounts[item] =1

#for each basket, see if every possible combination is supported
with open(filename, 'r') as f:
    for basket in f:
        basketCombos = combinations(basket.split(),2)
        
        for combo in basketCombos:
            #if the pair is supported add it to our list of supported pairs
            if initialCounts[combo[0]]>=support and initialCounts[combo[1]]>=support:
                output.write("%s\n" % str(combo))
      
        
endTime = time.time()               # get current time
totalTime = endTime - startTime     # calculate how long program took to run
print("Time to complete: ", totalTime)