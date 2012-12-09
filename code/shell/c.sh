
echo $a
ls -l |
awk '
BEGIN {FS="-"}
{ print $4;}' 
