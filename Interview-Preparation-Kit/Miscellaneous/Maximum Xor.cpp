#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

struct TrieNode{
    TrieNode* left; // for 0
    TrieNode* right;  // for 1
    TrieNode():left{nullptr} , right{nullptr} {}
};
void add(TrieNode*root , int element){
    TrieNode*temp = root;
    for(int64_t i=31;i>=0; --i){
        bool currBit = ((element&(1<<i) )!= 0);
        if(i==2){
            int x = 10;
        }
        if(currBit){
            if(temp -> right == nullptr) {
                temp->right = new TrieNode();
            }
            temp = temp -> right;
        }else{
            if(temp -> left == nullptr) {
                temp->left = new TrieNode();
            }
            temp = temp -> left;
        }
    }
}
int query(TrieNode* root , int element){
    TrieNode*temp = root;
    int returnValue{};
    for(int64_t i=31;i>=0; --i){
        bool currBit = ((element&(1<<i) )!= 0);
        if(i==2){
            int x = 10;
        }
        if(currBit){
            if(temp ->left != nullptr){
                temp = temp -> left;
                returnValue+=(1<<i);
            }else if(temp -> right != nullptr){
                temp = temp -> right;
            }else{
                return returnValue;
            }
        }else{
            if(temp ->right != nullptr){
                temp = temp -> right;
                returnValue+=(1<<i);
            }else if(temp -> left != nullptr){
                temp = temp -> left;
            }else{
                return returnValue;
            }
        }
    }
    return returnValue;
}
// Complete the maxXor function below.
vector<int> maxXor(vector<int> arr, vector<int> queries) {
    // solve here
    TrieNode* root = new TrieNode();
    for(auto&itr:arr){
        add(root , itr);
    }
    vector<int>res;
    for(auto&itr:queries){
        res.push_back(query(root , itr));
    }
    return res;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));
    // freopen("input","r",stdin);
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    int m;
    cin >> m;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> queries(m);

    for (int i = 0; i < m; i++) {
        int queries_item;
        cin >> queries_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        queries[i] = queries_item;
    }

    vector<int> result = maxXor(arr, queries);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

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
