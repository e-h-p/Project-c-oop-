#include"admin.h"

void loadProgram()
{
    userNameload();
    trainNameload();
    ad=new Admin;
    ad->adminPassLoad();
    for(int i=0;i<train_name.size();i++){
         tr[i]=new train;
          tr[i]->setname(train_name[i]);
          tr[i]->load();
    }
    for(int i=0;i<user.size();i++){
        us[i]=new User;
        us[i]->setUsername(user[i]);
        us[i]->loadUser();
    }
}
void updateProgram()
{
    userNameUpdate();
     trainNameUpdate();
     ad->adminPassUpdate();
      for(int i=0;i<train_name.size();i++){
          tr[i]->update();
    }
    for(int i=0;i<user.size();i++){
        us[i]->updateUser();
    }
     cout<<"\n\n\n\t\t\t\t ******* Thanks For Being With Us *******\n";
    cout<<"\n\t\t\t\t\t~~~~~Have a Good Day~~~~~\n\n\n";
}
void User::userlogIn()
 {
      string tmp1,tmp2;
         cout<<"\n\t\t\t=================================\n";
     cout<<"\t\t\t=       User Log in             =\n";
     cout<<"\t\t\t=================================\n\n";
     cout<<"\t\t\tEnter User Name: "; cin>>tmp1;
     cout<<"\n\t\t\tPassword: "; cin>>tmp2;
	bool flag=false;
        for(int p=0;p<user.size();p++){
            if(us[p]->get_pass<string>(tmp1,tmp2)){
                    flag=true;
                cout<<"\n\t\t\t---------Login successfully-----------";
                getch();
                     system("cls");
                  int choice=1;
                  while(1){
                                       cout<<"\n\t\t\t~~~~Welcome,"<<us[p]->get_user_name()<<"~~~~";
                        introUser();
                        cin>>choice;
                  system("cls");
            switch(choice){
                case 1: us[p]->viewTrainSchedule(); break;
                case 2: us[p]->bookTicket(); break;
                case 3: us[p]->cancellTicket<int>(p); break;
                case 4: us[p]->viewPreviousRecords(); break;
                case 5: us[p]->viewProfile(); getch(); system("cls"); break;
                case 6: return;
                case 0: updateProgram();  exit(0);
                default: cout<<"\n\n\n\n\n\t\t\t~~~SoRry!!!  you have entered an invalid number~~~";
                getch();
                system("cls");
                  }

            }
        }
        }
	if(!flag){
        cout<<"\n\t\t\tEnter your user id and password correctly~~";
        getch();
        system("cls");
        userlogIn();
	}
 }

void User::MENU()
{
    introUser1();
    int ch=1;
     cin>>ch;
     system("cls");
    switch(ch){
    case 1: userlogIn(); break;
    case 2: userSignUP(); break;
    case 3: return;
    case 0: updateProgram(); exit(0);
    default: cout<<"\n\t\t\t~~~SoRry!!!  you have entered an invalid number~~~";
    getch();
    system("cls");
    }
    MENU();
}

void Admin::MENU(){
     cout<<"\n\t\t\t===============================\n";
	cout<<"\t\t\t=      DHAKA METRO RAIL       =\n";
	cout<<"\t\t\t===============================\n\n";
       cout<<"\n\t\t\tEnter Admin Password :";
     string str; cin>>str;
     if(ad->get_pass(str)) {
        cout<<"\n\t\t\t-----Login successfully-----";
                getch();
                     // viewTrainSchedule()
                     system("cls");
                  int choice=1;
                  while(1){
                                       cout<<"\n\t\t\t~~~~Welcome, Admin~~~~\n";
                        introAdmin();
                        cin>>choice;
                  system("cls");
            switch(choice){
                case 1: ad->viewTrainSchedule(); break;
                case 2: viewPassengerInfo(); break;
                case 3: ad->add_Train(); break;
                case 4: ad->delete_train(); break;
                case 5: ad->set_pass(); break;
                case 6: return;
                case 0: updateProgram();  exit(0);
                default: cout<<"\n\n\n\n\n\t\t\t~~~SoRry!!!  you have entered an invalid number~~~";
                 getch();
                  }
            }
        }

     else{
        cout<<"\n\t\t\t~~~Sorry!! Wrong Password~~~";
        getch();
        system("cls");
        MENU();
     }

}

 void first_intro(){
 time_t currentTime;
	time(&currentTime);
	printf("\n\t\t\t     %s\n",ctime(&currentTime));
     cout<<"\t\t\t===============================\n";
     cout<<"\t\t\t=          WELCOME TO         =\n";
	cout<<"\t\t\t=      DHAKA METRO-RAIL       =\n";
	cout<<"\t\t\t===============================\n\n";
	cout<<"\t\t\t[1] USER\n";
	cout<<"\n\t\t\t[2] ADMIN\n";
	cout<<"\n\t\t\t[0] EXIT\n";
	cout<<"\n\t\t\t********************************";
	cout<<"\n\t\t\t********************************";
	cout<<"\n\t\t\tENTER YOUR CHOICE: ";
 }

