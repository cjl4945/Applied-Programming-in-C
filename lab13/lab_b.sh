#!/bin/bash


function parmFun {
	echo "The passed parameters are:" $1 $2
}

function random {
	retnum=999
	echo $retnum
}
	
echo "parmFun was called with the passed variables $1 $2"
parmFun one two
echo "A call was made to a function that returns a number"
random 
