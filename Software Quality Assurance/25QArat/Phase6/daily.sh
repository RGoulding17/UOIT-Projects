# CSCI 3060U - Phase VI - 25QArat
# Name: daily.sh
# Author: Martin Tuzim
# Description: This script will do a daily random transaction from 1-10 different daily scripts
# choosing from 1-10 different daily actions
# Simply run by using ./daily.sh

echo "Running Daily Script"
echo "Running Front End Simulator"
amtoftests=$((1 + RANDOM % 10))
for i in $(seq 1 $amtoftests); do
	testnum=$((1 + RANDOM % 10))
	../FrontEnd/src/frontend/frontend -test ./iofiles/user_files.txt ./iofiles/item_files.txt ./iofiles/mastertransactionpath.txt < ./dayscripts/day_$testnum.txt > tmp_$testnum.txt
done
echo "Running Back End Simulator"
	java -classpath ../Phase5/bin Main ./iofiles/mastertransactionpath.txt ./iofiles/item_files.txt ./iofiles/user_files.txt
echo "Done Running Tests"
