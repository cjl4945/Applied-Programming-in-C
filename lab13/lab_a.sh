#!/bin/bash
#----------------------------------------------------------------------------
# Simple command exercises
# student copy
#----------------------------------------------------------------------------

# Create a 2 word variable and print it out
DC="dog cat"
echo "The variable is $DC"

# Read a number from the command line
echo "Enter any number"
read num

echo "The number is $num" 

# Use the number in a simple if statement
if [ $num -gt 3 ]; then
	echo "The number $num is greater than 3"

else
	echo "The number $num is less than or equal to 3"  

fi
# Do some math with the number
NN=$num
let NN+=1
echo "$num + 1 =" $NN

# Do some math with the number using the alternative method
echo "Alternative method to adding the numbers"
echo "$num + 1 =" $[ $num +1 ] 
 	


# Count from 0 to 3
printf "\n"
echo "Looping from 1 to 3"
i=1
while [ $i -le 3 ]
do
	echo "$i."
	let i+=1
done
# Cycle through a list
printf "\n"
declare -a arr=("one" "two" "three")
i=1
for word in ${arr[*]}
do
	echo "$i. $word"
	let i+=1
done

# Verify string comparison functions 
echo "Enter dog (or not)"
read word
if [ $word == dog ]; then
	echo "The word you entered is dog"
else
	echo "The word you entered is not dog"

fi
# Simple if statement
echo "Enter a number [1-3]"
read number
if [ $number -eq 1 ]; then
	echo "You picked $number, which 1"

elif [ $number -eq 2 ]; then
	echo "You picked $number, which 2"

elif [ $number -eq 3 ]; then
	echo "You picked $number, which 3"

else
	echo "You didn't pick numbers 1-3, you picked $number"

fi
# Exercise the case statement


# Get and print the current directory
directory=`pwd`
echo "The current location is $directory"
