read N
sum=0
for i in $(seq $N)
do
    read y
    sum=$(( $sum + $y  ))
done
printf "%.3f" $(echo "$sum/$N" | bc -l)
