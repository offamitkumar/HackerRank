/*
 *
 *   SOLUTION IDEA : IN MY CASE HACERRANK CODE DOESN'T WORKED SO I TAKE INPUT MANUALLY 
 *
 *   create two arrays , call first array G1 and second array G2. 
 *   let the G1 array be representing grundy number for piles on which zero move is used
 *   G1[0]                             = 0;
 *   G1[1] = MEX{ G1[0] }              = 1;
 *   G1[2] = MEX{ G1[0], G1[1] }       = 2;
 *   G1[3] = MEX{ G1[0],G1[1],G1[2] }  = 3; 
 *   ... and so on...
 *   You might have noticed the pattern for grundy numbers in which zero move is already used 
 *
 *   
 *   let the G2 array be representing grundy number for piles on which zero move is not used
 *   so if we are calculating the answer for G2[2] then we got option of ZERO MOVE as our choice
 *   but if we use ZERO MOVE here then what will be answer for the that stage(i.e. MEX{G2[2] with zero move} ), well you calculated 
 *   that answer just above in G1 array. 
 *
 *   but this wouldn't help much in solving the whole problem as constraints are large and you can't do pre-calculation here 
 *
 *   So let's write down few stages of G2 array and see if we got a patter there also 
 *
 *   G2[0] = 0; // by standard definition
 *   G2[1] = MEX{ G1[1] , G2[0] } => MEX{1 , 0}       = 2
 *   G2[2] = MEX{ G1[2] , G2[1], G2[0] }              = 1
 *   G2[3] = MEX{ G1[3] , G2[2] , G2[1] , G2[0] }     = 4
 *   similarly G2[4]  => 3
 *             G2[5]  => 6
 *             G2[6]  => 5
 *
 *    if you observe carefully then you can see that 
 *    grundy_number[i] is   
 *                         i + 1 , if i is odd 
 *                         i - 1 , if i is even 
 */

#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the zeroMoveNim function below.
 */
char zeroMoveNim(vector<int> p) {
    /*
     * Write your code here.
     */
    int x{};
    for(auto&itr:p){
        if(itr&1){
            x ^= (itr + 1);
        }else {
            x ^= (itr - 1);
        }
    }
    if(x){
        return 'W';
    }else{
        return 'L';
    }
}

int main()
{
    int g; scanf("%d",&g);
    while(g--){
        int n; scanf("%d",&n);
        vector<int>v(n);
        for(auto&itr:v){
            cin >> itr;
        }
        cout <<  zeroMoveNim(v) << '\n'; 
    }
    return 0;
}

