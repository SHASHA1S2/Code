#!/bin/bash
# Written by Jeret Lendman
# detrix42@gmail.com

wpath="Download/"

echo "enter path to the directory of the pictures for the wallpaper slide show"
echo "default is $wpath"
read sspath

len=${#sspath}
# testing first char of sspath
if [[ ${sspath:0:1} == '/' ]]
then 
	 wpath="${sspath%/}/"
else
	# test for ending '/'
	[[ $sspath == */ ]] || wpath=$wpath$sspath/
fi

echo workng path is $wpath

if [ ! -d $wpath ] 
then
	echo "Problem with the path you entered: $wpath"
	exit 1
fi

exec 3>wallpaper.xml

pics=( $wpath*.jpg )

echo '<background>' >&3
echo '  <starttime>' >&3
echo '    <year>2009</year>' >&3
echo '    <month>08</month>' >&3
echo '    <day>04</day>' >&3
echo '    <hour>00</hour>' >&3
echo '    <minute>00</minute>' >&3
echo '    <second>00</second>' >&3
echo '  </starttime>' >&3
echo '<!-- This animation will start at midnight. -->'  >&3

for (( i=0;i<${#pics[@]}-1;i++ ))
do
  echo '  <static>' >&3
  echo '    <duration>1795.0</duration>' >&3
  echo "    <file>${pics[$i]}</file>" >&3
  echo '  </static>' >&3
  echo '  <transition>' >&3
  echo '    <duration>5.0</duration>' >&3
  echo "    <from>${pics[$i]}</from>" >&3
  echo "    <to>${pics[$i+1]}</to>" >&3
  echo '  </transition>' >&3
done

l=$((${#pics[@]}-1))
echo "l = $l"
  echo '  <static>' >&3
  echo '    <duration>1795.0</duration>' >&3
  echo "    <file>${pics[$l]}</file>" >&3
  echo '  </static>' >&3
  echo '  <transition>' >&3
  echo '    <duration>5.0</duration>' >&3
  echo "    <from>${pics[$l]}</from>" >&3
  echo "    <to>${pics[0]}</to>" >&3
  echo '  </transition>' >&3

echo '</background>' >&3

echo "copying XML file to ${wpath}background-1.xml"
cp ./wallpaper.xml ${wpath}background-1.xml
echo "removing tempary XML file"
rm ./wallpaper.xml
