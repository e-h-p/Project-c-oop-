#include<iostream>
using namespace std;
class Record
{
public:
    string train_name,date,status,from,to;
    int total_fare,num_of_ticket,ticket_ID,train_no;
    Record() {   }
   void showRecord();
};
void Record::showRecord(){
    cout<<"\n "<<setiosflags(ios::left)<<setw(25)<<date<<" "<<setw(9)<<ticket_ID<<" "<<setw(10)<<train_name<<" "<<setw(10)<<num_of_ticket<<" "<<setw(15)<<from<<" "<<setw(18)<<to<<" "<<setw(10)<<total_fare<<" "<<setw(15)<<status;
}
