read x
read y
read z
if [ $x -eq $y -a $y -eq $z ]
then
    echo EQUILATERAL
elif [ $x -eq $y -o $y -eq $z -o $x -eq $z ]
then
    echo ISOSCELES
else
    echo SCALENE
    fi
    
