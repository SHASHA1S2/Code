#!/bin/bash
 
awk '
BEGIN {count=0;FS=",";	print "\\documentclass{article}";print"\\begin{document}";print"\\begin{tabular}{|l |l| l|}";print "\\hline  Batsmen & Total & Average \\\\  \\hline "; print" & & \\\\";}
{
	if($1!="" && $2!="")
	{
	count=count+1;
	inn=$2;
	total=0;
	i=3;
	while(i<=NF)
		{total=total+$i;i=i+1;}
	if(inn==0)
	{print $1,"&",total,"&","ND","\\\\";}
	if(inn!=0)
	{print $1,"&",total,"&",total/inn,"\\\\";}
	if (count%5==0)
		{print "\\hline"}	
	}
}
END {print "\\hline";
	print "\\end{tabular}";
	print"\\end{document}";} ' b.csv

pdflatex b.tex
evince b.pdf

