#include <bits/stdc++.h>
using namespace std;

/*
Enter code for class Student here.
Read statement for specification.
*/
class Student{
    int age;
    int standard;
    string f_name , l_name;
    public:
    void set_age(int x){
        age = x;
    }
    void set_standard(int x){
        standard = x;
    }
    void set_first_name(string f_){
        f_name = f_;
    }
    void set_last_name(string l_){
        l_name  = l_;
    }
    int get_age(void){
        return age;
    }
    int get_standard(void){
        return standard;
    }
    string get_first_name(void){
        return f_name;
    }
    string get_last_name(void){
        return l_name;
    }
    string to_string(void){
        return std::to_string(age)+","+f_name+","+l_name+","+std::to_string(standard);
    }
};

int main() {
    int age, standard;
    string first_name, last_name;
    
    cin >> age >> first_name >> last_name >> standard;
    
    Student st;
    st.set_age(age);
    st.set_standard(standard);
    st.set_first_name(first_name);
    st.set_last_name(last_name);
    
    cout << st.get_age() << "\n";
    cout << st.get_last_name() << ", " << st.get_first_name() << "\n";
    cout << st.get_standard() << "\n";
    cout << "\n";
    cout << st.to_string();
    
    return 0;
}
