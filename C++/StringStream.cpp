#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

vector<int> parseInts(string str) {
	// Complete this function
    int tempInt;
    char tempChar;
    vector<int>result;
    stringstream inputStream(str);
    while(inputStream){
        inputStream>>tempInt;
        if(inputStream)
            inputStream>>tempChar;
        result.push_back(tempInt);
    }
    return result;
}

int main() {
    string str;
    cin >> str;
    vector<int> integers = parseInts(str);
    for(int i = 0; i < integers.size(); i++) {
        cout << integers[i] << "\n";
    }
    
    return 0;
}
