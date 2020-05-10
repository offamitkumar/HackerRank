num=0
read N
read arr
for i in ${arr[*]}
do
    num=$(( $num^$i))
done
echo $num
