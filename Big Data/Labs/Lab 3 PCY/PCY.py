#PCY ALGORITHM 
#Author Ryan Goulding
#Student ID 100556101
from collections import Counter
from itertools import combinations
import time 

# hashes each possible pair from a basket to a hashtable, counts apperances of each hash
def pairs(basket):
    pairs = combinations(basket,2)
    for pair in pairs:
        myHash = hash(pair)
        if myHash in hashTable:
            hashTable[myHash] +=1
        else:
            hashTable[myHash] =1

# Count's all apperance's of items in a given basket 
def item_counts(basket):
    for item in basket:
        if item in itemCounts:
            itemCounts[item]+=1
        else:
            itemCounts[item] = 1    

support = 2                 # support threshold
filename = 'sample_retail_big.dat'     #change this to retail.dat for full data
itemCounts = {}             # dictionary to hold item counts
hashTable = {}              # hashtable to hold hashed pairs
bitVector = {}              # bitvector that will hold supported hashed pairs
candidatePairs = []         # Supported pairs
startTime = time.time()     # get current time

#for each basket, count all the items inside and hash each possible pair to a hash map
with open(filename, 'r') as f:
    for basket in f:
        pairs(basket.split())
        item_counts(basket.split())

#create bit vector
for entry in hashTable.items():
    if(entry[1]>=support):
        bitVector[entry[0]] = 1     # if the pair is supported, set the bit vector to 1
    else:
        bitVector[entry[0]] = 0     # if the pair is not supported, set the bit vector to 0
        
# for each basket, find all possible pairs and check if they are supported and hash to a bitvector of 1      
with open(filename, 'r') as f:
    for basket in f:
        basketCombos = combinations(basket.split(),2)
        for combo in basketCombos:
            #if both numbers in the pair are supported, and we hash to a bitvector of 1, then add to pairs list
            if itemCounts[combo[0]]>=support and itemCounts[combo[1]]>=support and bitVector[hash(combo)] == 1:
                candidatePairs.append(combo)

#write to pcy_results.dat
with open('pcy_results.dat', 'w') as f:
    for pair in candidatePairs:
        f.write("%s\n" % str(pair))

endTime = time.time()               # get current time
totalTime = endTime - startTime     # calculate how long program took to run
print("Time to complete: ", totalTime)