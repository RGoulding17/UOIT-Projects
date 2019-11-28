#!/bin/sh
# CSCI 3060U - Phase III - Genesis
# Name: frontend_master.sh
# Author: Devon McGrath
# Description: This script automatically tests the front-end for each of the
# transactions. Each directory is assumed to be the name of a transaction with
# test files inside (e.g. login/, logout/, etc.). In each directory, there are
# up to three files associated with one test:
# 1) <transaction_name>_#.txt			- File used for all input
# 2) <transaction_name>_#_out_std.txt	- The redirected stdout output
# 3) <transaction_name>_#_out_tf.txt	- The transaction file created
#
# The input file must be present. The # indicates the test number, which starts
# at 1 (the script will loop continuously/sequentially increasing in a given
# directory until <transaction_name>_#.txt cannot be found).
#
# Additionally, there are also 2 input files for each of the tests in the
# corresponding directory. These contain the list of users and items to be
# used with the test input file (1) from above). These files are:
# a) _<transaction_name>_users.txt	- List of user accounts
# b) _<transaction_name>_items.txt	- List of items
#
# For each test, there will be output if and only if there is an error. At the
# end, the script will output the results with the number of tests
# passed/failed. This script assumes that the executable front-end is located
# '../../src/frontend/' and is called 'frontend'.

# Go through all the test directories
passed=0
failed=0
echo "Running tests..."
for d in */; do
	
	# Run the tests in each directory
	count=1
	tf="./${d}__tmp_out_tf__.out"
	tmp_out="./${d}/__tmp_stdout__.out"
	while [ -f "./${d}${d%?}_${count}.txt" ]
	do
		rm -f "$tf" "$tmp_out"
		base="./${d}${d%?}_${count}"
		

		# Run the test
		../../src/frontend/frontend -test ./${d}_${d%?}_users.txt ./${d}_${d%?}_items.txt $tf < ${base}.txt > $tmp_out

		# Check what files were created
		tf1=0
		if [ -f "$tf" ]; then
			tf1=1
		fi
		tf2=0
		if [ -f "${base}_out_tf.txt" ]; then
			tf2=1
		fi
		out1=0
		if [ -f "$tmp_out" ]; then
			out1=1
		fi
		out2=0
		if [ -f "${base}_out_std.txt" ]; then
			out2=1
		fi

		# Check the results for the transaction files
		stat=0
		msg1=""
		msg2=""
		if [ $tf1 -eq $tf2 ] && [ $tf1 -gt 0 ]; then
			res=`diff $tf ${base}_out_tf.txt -q`
			if [ "$res" != "" ]
			then
				stat=1
				msg1="ERROR: Transaction files are different!"
			fi
		elif [ $tf1 -gt 0 ]; then
			stat=1
			msg1="ERROR: Test created transaction file, but no transaction file was provided."
		elif [ $tf2 -gt 0 ]; then
			stat=1
			msg1="ERROR: Test did not create transaction file, but one was provided."
		fi
		
		# Check the results of the standard output files
		if [ $out1 -eq $out2 ] && [ $out1 -gt 0 ]; then
			res=`diff $tmp_out ${base}_out_std.txt -q`
			if [ "$res" != "" ]
			then
				stat=1
				msg2="ERROR: Output does not match!"
			fi
		elif [ $out1 -gt 0 ]; then
			stat=1
			msg2="ERROR: The program created output, but no test output was provided."
		elif [ $out2 -gt 0 ]; then
			stat=1
			msg2="ERROR: Test output was provided, but the program didn't output anything."
		fi
		
		# Display results (if error)
		if [ $stat -eq 0 ]
		then
			passed=$((passed+1))
		else
			echo "Test - ${d%?} $count failed:"
			echo "\t${msg1}\n\t${msg2}"
			failed=$((failed+1))
		fi
		count=$((count+1))
	done
	rm -f "$tf" "$tmp_out"
done

# Print final statistics
echo "Done.\n\n\t========== RESULTS =========="
if [ $failed -eq 0 ]
then
	echo "All $passed tests passed!"
else
	echo "Passed: $passed"
	echo "Failed: $failed"
fi

