#!/bin/bash

use="usage: ./cCodeMaker.sh <-c|-cpp> <name> <description> -o <out file>\n"

#or/and operators working backwards but ok
if [ "$1" != "-c" ] && [ "$1" != "-cpp" ]; then
printf "$use"
else 

if [ "$3" == "" ]; then
printf "$use"
else

if [ "$4" == "" ]; then
bash ~/makeHeader.sh $2 $3
bash ~/cBodyMaker.sh $1
else

if [ "$5" == "" ]; then
printf "$use"
else
bash ~/makeHeader.sh $2 $3 >> "$5"
bash ~/cBodyMaker.sh $1 >> "$5"
printf "Created file $5\n"
fi

fi
fi
fi

