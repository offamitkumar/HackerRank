#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the runningMedian function below.
 */
vector<double> runningMedian(vector<int> a) {
    /*
     * Write your code here.
     */
    priority_queue<int> max_heap;
    priority_queue<int ,vector<int>, greater<int>> min_heap;
    vector<double>d;
    for(auto&itr:a){
        if(max_heap.size() == 0){
            max_heap.push(itr);
        }else{
            if(itr < max_heap.top()){
                max_heap.push(itr);
            }else{
                min_heap.push(itr);
            }
            if( abs( (int)min_heap.size() - (int)max_heap.size() ) > 1 ){
                if(min_heap.size() > max_heap.size() ){
                    max_heap.push(min_heap.top());
                    min_heap.pop();
                }else{
                    min_heap.push(max_heap.top());
                    max_heap.pop();
                }
            }
        }
        if(min_heap.size()  == max_heap.size() ){
            double mid = ((double)min_heap.top() + (double)max_heap.top()) / 2.0;
            d.push_back(mid);
        }else if(max_heap.size() > min_heap.size()){
            d.push_back(max_heap.top());
        }else {
            d.push_back(min_heap.top());
        }
    }
    return d;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int a_count;
    cin >> a_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> a(a_count);

    for (int a_itr = 0; a_itr < a_count; a_itr++) {
        int a_item;
        cin >> a_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        a[a_itr] = a_item;
    }

    vector<double> result = runningMedian(a);

    for (int result_itr = 0; result_itr < result.size(); result_itr++) {
        fout << result[result_itr];

        if (result_itr != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}
