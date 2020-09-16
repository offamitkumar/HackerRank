#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
struct Person{
    string name; 
    int age; 

    virtual void getdata(void) = 0; 
    virtual void putdata(void) = 0; 
    Person(){
    }
};
struct Professor : public Person{
    int publication , curr_id; 
    static int id;
    Professor(){
        curr_id =id++;
    }
    void getdata(void) override {
        cin >> name >>  age >> publication; 
    };
    void putdata(void) override {
        cout << name << ' ' << age <<' ' << publication <<' ' << curr_id << '\n'; 
    }
};
int Professor::id =1;
struct Student : public Person{
    int curr_id; 
    int sum;
    static int id;
    Student(){
        sum = 0;
        curr_id = id++;
    }
    void getdata(void) override {

        cin >> name >>  age ; 
        int x; 
        for(int i=0; i<6; ++i){
            cin>>x; 
            sum+=x;
        }
    };
    void putdata(void) override {
        cout << name << ' ' << age <<' ' << sum<<' ' << curr_id << '\n'; 
    }
};
int Student::id = 1;
int main(){

    int n, val;
    cin>>n; //The number of objects that is going to be created.
    Person *per[n];

    for(int i = 0;i < n;i++){

        cin>>val;
        if(val == 1){
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for(int i=0;i<n;i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;

}
