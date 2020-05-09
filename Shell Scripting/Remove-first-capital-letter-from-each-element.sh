#sed s/[A-Z]/./ $1 | paste -sd ' '

arr=($(cat))
echo ${arr[@]/[A-Z]/.}
