#!/bin/bash

if [ ! $# -eq 2 ]
then
	echo "Invalid number of parameters. Specify filesdir and searchstr."
	exit 1
fi

filesdir=$1
searchstr=$2

if [ ! -d $filesdir ]
then
	echo "$filesdir not a valid directory."
	exit 1
fi

filecount=$( find $filesdir -type f | wc -l )
matchcount=$( grep -r $searchstr $filesdir | wc -l )

echo "The number of files are $filecount and the number of matching lines are $matchcount"
