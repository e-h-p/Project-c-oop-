#include<bits/stdc++.h>
using namespace std;
class stops{
public:
    string stopsName,time;
    int rent;
public:
     stops():stopsName(""),time(""),rent(0){};
    stops(string s,string s1,int r):stopsName(s),time(s1),rent(r)  { };
    void operator ++ (int){   ///operator overloading
        cout<<"\t\t\tEnter stops name: "; cin>>stopsName;
       cout<<"\t\t\tEnter train lefting Time: "; cin>>time;
       cout<<"\t\t\tEnter rent: "; cin>>rent;
    }
    void show();
};

void stops:: show()
{
    cout<<setiosflags(ios::left)<<setw(24)<<stopsName<<" "<<setw(9)<<rent<<setw(18)<<time;
}


