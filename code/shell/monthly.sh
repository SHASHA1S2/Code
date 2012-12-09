#!/bin/bash
month=$1
year="2012"
y=`date +%Y`
m=`date +%m`
if [ -z "$month" ];then
	month=$m
	year=$y
fi
for X in `ls`
do
	a=`stat -c %y "$X"`
	echo $a
	#b=`cut -d '-' -f2 "$a"`
	#c=`cut -d '-' -f1 "$a"`
	#echo $b
	#echo $c
	#if [$c -eq $month ] && [$b -eq $year]; then             # some error which i unable to figure out just commenting out so that the code could atleast run    		 	
	#	echo "$X" | cut -d '/' -f2
	#fi
done



