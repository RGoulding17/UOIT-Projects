# CSCI 3060U - Phase VI - 25QArat
# Name: daily.sh
# Author: Martin Tuzim
# Description: This script will do a daily random transaction from 1-10 different daily scripts
# choosing from 1-50 different daily actions
# Simply run by using ./daily.sh

echo "Running Daily Script"
amtoftests=$((1 + RANDOM % 10))
for i in $(seq 1 $amtoftests); do
	testnum=$((1 + RANDOM % 5))
	echo $testnum
	../../../src/frontend/frontend -test ./iofiles/user_files.txt ./iofiles/item_files.txt ./iofiles/mastertransactionpath.txt < ./dayscripts/day_$testnum.txt > tmp_$testnum.txt
done
echo "Done Running Tests"


