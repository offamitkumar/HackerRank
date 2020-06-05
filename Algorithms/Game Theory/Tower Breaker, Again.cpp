#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

/*
 * Complete the towerBreakers function below.
 */
const int MAXN = (int)1e5+1000;
bool first_time = true;
vector<int>grundy_number(MAXN);
void pre_calculate(void){
    grundy_number[0] = 0;
    grundy_number[1] = 0;
    for(int height = 2; height < MAXN; ++height){
        set<int>visited;
        for(int j = 1; j * j <= height; ++j){
            // calculating grundy number for height "height" 

            if(height % j == 0){
                // assume that height of tower is 6 then we can break the tower in both ways 
                // 2 tower of height 3
                // 3 tower of height 2
                
                if(height / j != 1){ // for Y towers of X height 

                    int X = j; // height of new tower 
                    int Y = height / j; // number of new towers 
                    if( Y & 1 ) {
                        visited.insert(grundy_number[X]);
                    }else { 
                        // if number of tower are even then both player will take the same move 
                        // and no new stage will be achieved 
                        visited.insert(0);
                    }
                }

                if(j > 1){ // for X towers of Y height 
                    int X = height/j; //  new height of j towers 
                    if(j & 1){
                        visited.insert(grundy_number[X]);
                    }else{
                        visited.insert(0);
                    }
                }
            }
        }
        int mex = -1;
        for(int i=0;i < 555; ++i){
            if(visited.find(i)==visited.end()){
                mex = i; 
                break;
            }
        }
        grundy_number[height] = mex;
    }

}
int towerBreakers(vector<int> arr) {
    /*
     * Write your code here.
     */
    if(first_time){
        pre_calculate();
        first_time = false;
    }
    int ans = 0;
    for(auto&itr:arr){
        ans ^= grundy_number[itr];
    }
    return ans ? 1 : 2;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int arr_count;
        cin >> arr_count;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string arr_temp_temp;
        getline(cin, arr_temp_temp);

        vector<string> arr_temp = split_string(arr_temp_temp);

        vector<int> arr(arr_count);

        for (int arr_itr = 0; arr_itr < arr_count; arr_itr++) {
            int arr_item = stoi(arr_temp[arr_itr]);

            arr[arr_itr] = arr_item;
        }

        int result = towerBreakers(arr);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
