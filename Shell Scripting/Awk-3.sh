aw '{
    avg=($2+$3+$4)/3
    if( avg>=80 )
        print $1,$2,$3,$4,": A"
    else if(avg<80 && avg>=60 )
        print $1,$2,$3,$4,": B"
    else if(avg<60 && avg>=50)
        print $1,$2,$3,$4,": C"
    else
        print $1,$2,$3,$4,": FAIL";
    }'
