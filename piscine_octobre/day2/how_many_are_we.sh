#!/bin/bash
if [ $1 ]
then
	cut -d ';' -f 3 | grep $1 -ic
else
	cut -d ';' -f 3 | wc -l
fi 
