#include<bits/stdc++.h>

using namespace std;
//Implement the class Box  
//l,b,h are integers representing the dimensions of the box

// The class should have the following functions : 

// Constructors: 
// Box();
// Box(int,int,int);
// Box(Box);


// int getLength(); // Return box's length
// int getBreadth (); // Return box's breadth
// int getHeight ();  //Return box's height
// long long CalculateVolume(); // Return the volume of the box

//Overload operator < as specified
//bool operator<(Box& b)

//Overload operator << as specified
//ostream& operator<<(ostream& out, Box& B)
class Box{
    private:
        int l , b , h; 
    public:
        Box(){
            l = b = h = 0;
        };
        Box(int l , int b , int h) : l(l), b(b) , h(h) {} 
        Box(const Box&B){
            l = B.l;
            b = B.b; 
            h = B.h;
        }
        int getBreadth(void) {
            return b; 
        }
        int getHeight(void) {
            return h; 
        }
        int getLength(void) {
            return l; 
        }
        long long CalculateVolume(void) {
            return (long long)l * (long long)b * (long long)h; 
        }

        bool operator<(const Box &b2) {
            if(l  == b2.l){
                if(b == b2.b){
                    return h < b2.h;
                }else {
                    return b < b2.b;
                }
            }else{
                return l < b2.l;
            }
        }
        friend ostream& operator<<(ostream &cout , Box &B){
            cout << B.l << ' ' << B.b << ' ' << B.h; 
            return cout;
        }
};

void check2()
{
	int n;
	cin>>n;
	Box temp;
	for(int i=0;i<n;i++)
	{
		int type;
		cin>>type;
		if(type ==1)
		{
			cout<<temp<<endl;
		}
		if(type == 2)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			temp=NewBox;
			cout<<temp<<endl;
		}
		if(type==3)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			if(NewBox<temp)
			{
				cout<<"Lesser\n";
			}
			else
			{
				cout<<"Greater\n";
			}
		}
		if(type==4)
		{
			cout<<temp.CalculateVolume()<<endl;
		}
		if(type==5)
		{
			Box NewBox(temp);
			cout<<NewBox<<endl;
		}

	}
}

int main()
{
	check2();
}
