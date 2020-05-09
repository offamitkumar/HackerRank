
#awk '!/a|A/' $1

#grep -vi a

arr=($(cat))
echo ${arr[@]/*[aA]*/}
