
#include"train.h"
#include"record.h"
#include"virtual.h"
class User;
vector<string>user;
User* us[100];

class User: public train, public Random  ///inheritance
{
protected:
    string user_name,first_name,last_name,email,password,nid_no,address,gender,contact_no;
    vector<Record>records;
public:
    User()  {  }
    void setUsername(string str){
    user_name=str;
    }
    void viewPreviousRecords();
    void viewProfile();
    void registration();
    void bookTicket();
    template<typename T>
    void cancellTicket(T p);
    void updateUser();
    void loadUser();
    template<typename Type>
    bool get_pass(Type s1,Type s2){
        if(user_name==s1 && password==s2) return true;
        return false;
    }
    string get_user_name(){
    return user_name;
    }
    friend void viewPassengerInfo();  ///Friend Function
    void userlogIn();
    void MENU();

};

void userSignUP()
 {
     us[user.size()]=new User;
        us[user.size()]->registration();
 }
void introUser()
{
    cout<<"\n\t\t\t===============================\n";
	cout<<"\t\t\t=      DHAKA METRO RAIL       =\n";
	cout<<"\t\t\t===============================\n\n";
	cout<<"\n\t\t\t[1] VIEW TRAIN SCHEDULE\n";
	cout<<"\n\t\t\t[2] BOOK TICKET\n";
	cout<<"\n\t\t\t[3] CANCEL TICKET\n";
	cout<<"\n\t\t\t[4] VIEW BOOKING HISTORY\n";
	cout<<"\n\t\t\t[5] VIEW PROFILE\n";
	cout<<"\n\t\t\t[6] GO BACK\n";
	cout<<"\n\t\t\t[0] EXIT\n";
	cout<<"\n\t\t\t********************************";
	cout<<"\n\t\t\t********************************";
	cout<<"\n\t\t\tENTER YOUR CHOICE: ";
}
void introUser1()
{
      cout<<"\n\t\t\t===============================\n";
	cout<<"\t\t\t=      DHAKA METRO RAIL       =\n";
	cout<<"\t\t\t===============================\n\n";
	cout<<"\t\t\t\t----User Menu------\n";
	cout<<"\n\t\t\t[1] LOG IN\n";
	cout<<"\n\t\t\t[2] SIGN UP\n";
	cout<<"\n\t\t\t[3] GO BACK\n";
	cout<<"\n\t\t\t[0] EXIT\n";
	cout<<"\n\t\t\t********************************";
	cout<<"\n\t\t\t********************************";
	cout<<"\n\t\t\tENTER YOUR CHOICE: ";
}

void userNameload(){
    ifstream ifile("userName.txt",ios::in);
    ifile.seekg(0,ios::end);
  int   size_ = ifile.tellg();
    ifile.seekg(0);
    while(ifile.tellg()<size_-1)
    {
        string tmp;
        ifile>>tmp;
        user.push_back(tmp);
    }
}
void userNameUpdate(){
 ofstream osfile("userName.txt",ios::out);
    for(auto p: user)
    {
        osfile<<p<<'\n';
    }
}

void User::viewPreviousRecords()
{
     cout<<"\n\n\t\t\t\t~~~~~~~~~~ Booking History~~~~~~~~~~\n"<<endl;
     cout<<"\t  Timestamp\t   Tkt-ID   Tra-Name   Total-Tkt  Boarding-Point  Destination-Point  Total-fare  Status\n";
    cout<<" ----------------------------------------------------------------------------------------------------------------\n";
    if(records.size()==0){
        cout<<"\n\n\t\t\t\t~~~~~~~No, Booking History~~~~~~\n";
        cout<<"\t\t Press any key for go back.....";
        getch(); system("cls");
        return;
    }
    for(int i=0;i<records.size();i++){
        records[i].showRecord();
    }
        cout<<" \n-------------------------------------------------------------------------------------------------------------------\n";
        cout<<"\t\t Press any key for go back....."; getch(); system("cls");

}
 void User::registration()
 {
     cout<<"\n\t\t\t=================================\n";
     cout<<"\t\t\t=       User Registration       =\n";
     cout<<"\t\t\t=================================\n\n";
     Q:
     cout<<"\tUser Name(Must user lower case): "; cin>>user_name;
     for(auto p: user){
        if(p==user_name){
            cout<<"User Name Already Exists"<<endl;
            goto Q;
        }
     }
     for(int i=0;i<user_name.length();i++){
        if(!islower(user_name[i])){
            cout<<"Formet Doesn't Match"<<endl;
            goto Q;
        }
     }
     cout<<"\tFirst Name: "; cin>>first_name;
     cout<<"\tLast Name: "; cin>>last_name;
     cout<<"\tGender: "; cin>>gender;
     cout<<"\tEmail: "; cin>>email;
     cout<<"\tNID No: "; cin>>nid_no;
     cout<<"\tAddress: "; cin>>address;
     cout<<"\tContact no: "; cin>>contact_no;
     A:
     cout<<"\tPassword: "; cin>>password;
     string tmp;
     cout<<"\tConfirm Password: "; cin>>tmp;
     if(tmp!=password) {
        cout<<"\t\t\t---------Confirmation mismatched-------\n";
        goto A;
     }
     user.push_back(user_name);
     cout<<"\n\t\t...........You are now registered.......... \n";
     cout<<"\t\t Press any key for go back....."; getch(); system("cls");
 }
 void User::viewProfile()
 {
      cout<<"\n\n\n\t\t\t\t"<<user_name<<"'s Profile\n";
    cout<<"\t\t-------------------------------------\n";
    cout<<"\t\t"<<setiosflags(ios::left)<<setw(10)<<"User Name"<<": "<<user_name<<endl;
     cout<<"\t\t"<<setw(10)<<"First Name"<<": "<<first_name<<endl;

     cout<<"\t\t"<<setw(10)<<"Last Name"<<": "<<last_name<<endl;
     cout<<"\t\t"<<setw(10)<<"Gender"<<": "<<gender<<endl;
     cout<<"\t\t"<<setw(10)<<"Email"<<": "<<email<<endl;
     cout<<"\t\t"<<setw(10)<<"NID No"<<": "<<nid_no<<endl;
     cout<<"\t\t"<<setw(10)<<"Address"<<": "<<address<<endl;
     cout<<"\t\t"<<setw(10)<<"Contact no"<<": "<<contact_no<<endl;
     cout<<"\t\t-------------------------------------";
 }
 void User:: updateUser()
 {
      ofstream ofile(user_name+"UGInfo.txt",ios::out);
      ofile<<user_name<<'\n';
        ofile<<first_name<<'\n';
        ofile<<last_name<<'\n';
        ofile<<email<<'\n';
        ofile<<password<<'\n';
        ofile<<nid_no<<'\n';
        ofile<<address<<'\n';
        ofile<<gender<<'\n';
         ofile<<contact_no<<'\n';
    ofstream osfile(user_name+"rec.txt",ios::out);
    for(auto p:records)
    {
        osfile<<p.train_name<<'\n';
        osfile<<p.date<<'\n';
        osfile<<p.status<<'\n';
        osfile<<p.from<<'\n';
        osfile<<p.to<<'\n';
        osfile<<p.total_fare<<'\n';
        osfile<<p.num_of_ticket<<'\n';
        osfile<<p.ticket_ID<<'\n';
        osfile<<p.train_no<<'\n';
    }


 }
void User::loadUser()
{
    ifstream ifile(user_name+"UGInfo.txt",ios::in);
     ifile>>user_name;
    ifile>>first_name;
    ifile>>last_name;
    ifile>>email;
    ifile>>password;
    ifile>>nid_no;
    ifile>>address;
    ifile>>gender;
    ifile>>contact_no;
    ifstream isfile(user_name+"rec.txt",ios::in);
    isfile.seekg(0,ios::end);
  int   size_ = isfile.tellg();
    isfile.seekg(0);
    while(isfile.tellg()<size_-1)
    {
        Record r;char ch;
        isfile>>r.train_name;
        isfile>>r.date;
        isfile>>r.status;
        isfile>>r.from;
        isfile>>r.to;
        isfile>>r.total_fare;
        isfile>>r.num_of_ticket;
        isfile>>r.ticket_ID;
        isfile>>r.train_no;
        records.push_back(r);
    }
}
void User::bookTicket()
{
    int no;
        cout<<"\n\t\t\t\t Ticket Booking\n";
       cout<<"\t\t\t    -------------------------\n";
       cout<<"\n\n\t\t\tEnter Train No: "; cin>>no;
        if(no>0 && no<=train_name.size()){
                int n,s,e;
                cout<<"\n\t\t\tNumber of Ticket you want to buy: "; cin>>n;
            cout<<"\n\t\t\tBoarding Point No: ";cin>>s;
            cout<<"\n\t\t\tDestination Point No: "; cin>>e;
            if(s<e && e<=tr[no-1]->totalstops && e>0){
                    int flag=1;
                for(int i=s-1;i<e-1;i++){
                    if(tr[no-1]->availableseat[i]<n) {
                        flag=0;
                        break;
                    }
                }
            if(flag) {
                    int pay=tr[no-1]->stop[e-1].rent - tr[no-1]->stop[s-1].rent;
                   cout<<"\n\t\t\tYou must pay: "<<pay*n<<endl;
                   char x;
                 cout<<"\t\t\tPress any Key for Pay and Confirm ticket\n\t\t\tOR, Press \'0\' for Go Back..:"; cin>>x;
                 if(x!='0'){

                    cout<<"\n\n\t\t\t~~~~~Ticket successfully Booked~~~~~\n"<<endl;
                     cout<<"\t\t\t~~~Ticket ID: "<<tr[no-1]->ticket<<"~~~~\n\n";
                     cout<<"\t\t\tPress any key for go back.....";
                     for(int i=s-1;i<e-1;i++){
                            tr[no-1]->availableseat[i]-=n;
                     }
                    Record R;
                    R.train_name=tr[no-1]->name;
                    R.from=tr[no-1]->stop[s-1].stopsName;
                    R.to=tr[no-1]->stop[e-1].stopsName;
                    R.num_of_ticket=n;
                    R.total_fare=pay*n;
                    R.status="Paid";
                   R.train_no=no-1;
                   time_t now = time(0);
                   string str=ctime(&now);
	                for(int i=0;i<str.length();i++){
                        if(str[i]==' ')str[i]='_';
	                }
	                str.pop_back();
	                R.date=str;
	                R.ticket_ID=tr[no-1]->ticket++;
	                records.push_back(R);
                 }
                 else{
                        system("cls"); return;
                 }
            }
            else cout<<"\n\n\t\t\t~~~~Ticket is unavailable as user limit is exited~~~~";
            }
            else cout<<"\n\n\t\t\t~~~~Invalid Boarding and Destination Point No.~~~~";
        }
        else {
            cout<<"\n\n\t\t\t~~~~~Train no- "<<no<<" is not available~~~~~";
        }
        getch();
        system("cls");

}
template<typename T>

void User::cancellTicket(T p)
{
    cout<<"\n\t\t\t\t Ticket Cancelling\n";
       cout<<"\t\t\t    -------------------------\n";
    int tmp;
     cout<<"\n\n\t\t\tEnter your ticket ID: "; cin>>tmp;
     bool flag=1,flag2=1;
     for(int x=0;x<us[p]->records.size();x++){
        if(us[p]->records[x].ticket_ID==tmp){
                     flag=0;
                if(us[p]->records[x].status=="Cancelled"){
                    cout<<"\n\t\t\t~~~~Ticket already Cancelled~~~~";
                    break;
                }

            us[p]->records[x].status="Cancelled";
             string s1=us[p]->records[x].from ,s2=us[p]->records[x].to;
             int st=0,en=0;
             string str=us[p]->records[x].train_name;
             for(int k=0;k<train_name.size();k++){
                if(train_name[k]==str){
                        flag2=0;
                      for(int i=0;i<tr[k]->stop.size();i++){
                if(tr[k]->stop[i].stopsName==s1) st=i+1;
                if(tr[k]->stop[i].stopsName==s2) en=i+1;
             }
             for(int i=st-1;i<en-1;i++){
                tr[k]->availableseat[i]+=us[p]->records[x].num_of_ticket;
             }
              cout<<"\n\t\t\t----------------Ticket Successfully Cancelled--------------------";
                }
             }
             if(flag2) cout<<"\n\t\t\t-------------Sorry, Time up!!! Cancellation is not Available----------";

        }

     }
     if(flag) cout<<"\n\n\t\t\t~~~~~Ticket ID not found~~~~~";
     getch();
     system("cls");
}





