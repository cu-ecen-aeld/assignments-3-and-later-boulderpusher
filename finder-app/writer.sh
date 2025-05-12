#!/bin/bash

if [ ! $# -eq 2 ]
then
	echo "Invalid number of parameters. Specify writefile and writestr."
	exit 1
fi

writefile=$1
writestr=$2

mkdir -p $( dirname $writefile)
echo $writestr > $writefile
