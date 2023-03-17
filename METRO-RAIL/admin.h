#include"user.h"
class Admin;
Admin* ad;
class Admin :public train, public Random
{
private:
    string pass;
public:
    Admin() {  }
    void add_Train();
    void delete_train();
    bool get_pass(string s);
    void set_pass();
    void adminPassLoad();
    void adminPassUpdate();
    void MENU();
};
 void Admin::add_Train()
    {
        tr[train_name.size()]=new train;
        tr[train_name.size()]->gettrain();
        cout<<"\t\t\tPress any key for go back....."; getch(); system("cls");
    }

 void Admin::delete_train()
    {
        string str;
         cout<<"\n\n\n\t\t\t~~~Deleting Train~~~~\n\n";
        cout<<"\t\t\tEnter Train Name: ";
        cin>>str;
        for(int i=0;i<train_name.size();i++){
            if(train_name[i]==str){
                string str1=str;
                string str2=str;
                str+="gInfo.txt";
                str1+="Stop.txt";
                str2+="AvS.txt";
                 const char* s=str.c_str();
                  const char* s1=str1.c_str();
                   const char* s2=str2.c_str();
                train_name.erase(train_name.begin()+i);
                remove(s);
                remove(s1);
                remove(s2);
                for(int j=i;j<train_name.size();j++){
                    tr[j]=tr[j+1];
                }
                cout<<"\n\t\t\t~~~~ train Successfully Deleted~~~~";
                getch();
                 system("cls");
                return;
            }
        }

            cout<<"\n\t\t\t~~~~train Name not Found~~~~~~";
            getch();
            system("cls");
    }
 bool Admin::get_pass(string s)
 {
        if(pass==s) return true;
        return false;
}
   void Admin::set_pass()
   {
        cout<<"\n\n\t\t\t ~~~~~Changing Admin Password~~~~~\n";
        cout<<"\n\t\t\tEnter old Password : ";
        string str; cin>>str;

        if(str==pass){
    AB:
            cout<<"\n\t\t\tEnter New Password : "; cin>>str;
            string tmp;
            cout<<"\t\t\tConfirm Password: "; cin>>tmp;
              if(tmp!=str) {
                 cout<<"\t\t\t---------Confirmation mismatched-------\n";
                 goto AB;
             }
            pass=str;
            cout<<"\n\t\t\tPassword Updated successfully...";
              getch(); system("cls");
        }
       else {
        cout<<"\n\t\t\t Sorry...Password is not matched....";
        getch(); system("cls");
        set_pass();
       }
    }
void Admin::adminPassLoad()
    {
        ifstream ifile("admin.txt",ios::in);
        ifile>>pass;
       // cout<<pass<<endl;
        if(pass=="") pass="admin";
    }

     void Admin::adminPassUpdate()
    {
        ofstream ofile("admin.txt", ios::out);
        ofile<<pass<<'\n';
    }
void viewPassengerInfo()
    {

        cout<<"\n\n\n\t\t\t~~~Passenger\'s List~~~~\n";

        cout<<"\n\t\t    User no.\tName\n";
        cout<<"\t\t    --------   ------\n";
        for(int i=0;i<user.size();i++){
            cout<<"\t\t\t"<<i+1<<" \t"<<user[i]<<endl;
        }
        cout<<"\t\t    -------------------\n";
        cout<<"\n\tEnter \'0\' to go back.\n\tOR, Enter User no. to see the User's Profile : ";
        int ch; cin>>ch;
        system("cls");
        if(!ch) return ;
        if(ch>user.size()) {
                cout<<" Invalid number"<<endl;
                getch();
                system("cls");
                viewPassengerInfo();
        }
        else{
            us[ch-1]->viewProfile();
                cout<<"\n\tEnter \'0\' to go back.\n\tOR, Enter Others to see the User's Previous Records : ";
             char cho;cin>>cho;
             system("cls");
            if(cho=='0') viewPassengerInfo();
            us[ch-1]->viewPreviousRecords();
        }
        viewPassengerInfo();
    }

void introAdmin()
{
    cout<<"\n\t\t\t********************************\n";
	cout<<"\n\t\t\t[1] VIEW TRAINS \n";
	cout<<"\n\t\t\t[2] VIEW PASSENGERS INFO\n";
	cout<<"\n\t\t\t[3] ADD TRAIN\n";
	cout<<"\n\t\t\t[4] DELETE TRAIN\n";
	cout<<"\n\t\t\t[5] CHANGE ADMAIN PASSWORD\n";
	cout<<"\n\t\t\t[6] GO BACK\n";
	cout<<"\n\t\t\t[0] EXIT\n";
	cout<<"\n\t\t\t********************************\n";
	cout<<"\n\t\t\t********************************\n";
	cout<<"\n\t\t\tENTER YOUR CHOICE: ";
}
