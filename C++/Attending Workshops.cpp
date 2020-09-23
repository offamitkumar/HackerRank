#include<bits/stdc++.h>

using namespace std;

//Define the structs Workshops and Available_Workshops.
//Implement the functions initialize and CalculateMaxWorkshops
struct Workshop{
    int start_time; 
    int end_time; 
    Workshop(){}
    Workshop(int a, int b) {
        start_time = a; 
        end_time = a+b;
    }
};
bool compare(Workshop &a , Workshop&b) {
    return a.end_time < b.end_time;
}
struct Available_Workshops{
    int n;
    Workshop *arr;
    Available_Workshops(){}
    Available_Workshops(int n) {
        this->n = n;
        arr = new Workshop[n];
    }
    void sortArray(void) {
        sort(arr , arr+n , compare);
    }
};

Available_Workshops* initialize(int *start_t , int *end_t , int n) {
    Available_Workshops *itr = new Available_Workshops(n);
    for (int i=0; i < n; ++i) {
        itr->arr[i] = Workshop(start_t[i] , end_t[i]);
    }
    itr->sortArray();
    return itr;
}

int CalculateMaxWorkshops(Available_Workshops*ptr) {
    int counter{}; 
    int current_time = 0;
    for(int i=0; i<ptr->n;  ++i) {
        if(current_time <= ptr->arr[i].start_time){
            current_time = ptr->arr[i].end_time; 
            ++counter;
        }
    }
    return counter;
}

int main(int argc, char *argv[]) {
    int n; // number of workshops
    cin >> n;
    // create arrays of unknown size n
    int* start_time = new int[n];
    int* duration = new int[n];

    for(int i=0; i < n; i++){
        cin >> start_time[i];
    }
    for(int i = 0; i < n; i++){
        cin >> duration[i];
    }

    Available_Workshops * ptr;
    ptr = initialize(start_time,duration, n);
    cout << CalculateMaxWorkshops(ptr) << endl;
    return 0;
}
