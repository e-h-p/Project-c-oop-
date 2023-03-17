
#include"stops.h"

#include<conio.h>
class train;
vector<string> train_name;
train* tr[10];

class train{
protected:
    string name,start,destination,lefttime,date;
    int seat,train_no,totalstops,ticket,rent;
    vector<stops>stop;
    vector<int>availableseat;
public:
    void gettrain();
    void show();
    void load();
    void update();
    void setname(string str){
    name=str;
    }
    void showTrainStopsDetails();
    void viewTrainSchedule();
     friend class User;
};

void train::viewTrainSchedule()
{

        system("cls");
        cout<<"\n\n\n\t\t\t\t\t~~~~Train Schedule~~~~\n";
        cout<<"\n\tTrain no:  Train name\tstart place\tdestination place\tprice\tseat \ttime\t  Total Stops\n";
        cout<<"\t-----------------------------------------------------------------------------------------------------\n";
    for(int i=0;i<train_name.size();i++){
          tr[i]->show();
    }
    int tmp=1;
    cout<<"\n\tPress \'0\' to go back.\n\tOR, Press Train No. to see the train's stopage details : "; cin>>tmp;
    system("cls");
    if(tmp){
            cout<<"\n\n\n\tTrain no:  Train name\tstart place\tdestination place\tprice\tseat \ttime\t  Total Stops\n";
            cout<<"\t-----------------------------------------------------------------------------------------------------\n";
        if( tmp<=train_name.size()){
                tr[tmp-1]->show();
        cout<<endl;
             tr[tmp-1]->showTrainStopsDetails();
             cout<<"\t\t Press any key for go back.....";
        }
        else  cout<<"\n\t\t\t**********Invalid train Number***********"<<endl;
        getch();
        viewTrainSchedule();
    }


}
void train::load()
{
    ifstream ifile(name+"gInfo.txt",ios::in);
    ifile>>name;
    ifile>>train_no;
    ifile>>start;
    ifile>>destination;
    ifile>>seat;
    ifile>>totalstops;
    ifile>>lefttime;
    ifile>>date;
    ifile>>rent;
    ifile>>ticket;

     ifstream isfile(name+"Stop.txt",ios::in);
    isfile.seekg(0,ios::end);
  int   size_ = isfile.tellg();
    isfile.seekg(0);
    while(isfile.tellg()<size_-1)
    {
        string tmp1;
        isfile>>tmp1;
        string tmp2;
        isfile>>tmp2;
        int n;
        isfile>>n;
        stop.push_back(stops(tmp1,tmp2,n));
    }
     ifstream iavfile(name+"AvS.txt",ios::in);
    iavfile.seekg(0,ios::end);
     size_ = iavfile.tellg();
    iavfile.seekg(0);
    while(iavfile.tellg()<size_-1)
    {
        int n;
        iavfile>>n;
        availableseat.push_back(n);
    }
}

void train::update()
{
     ofstream ofile(name+"gInfo.txt",ios::out);
      ofile<<name<<'\n';
        ofile<<train_no<<'\n';
        ofile<<start<<'\n';
        ofile<<destination<<'\n';
        ofile<<seat<<'\n';
        ofile<<totalstops<<'\n';
        ofile<<lefttime<<'\n';
        ofile<<date<<'\n';
        ofile<<rent<<'\n';
        ofile<<ticket<<'\n';
    ofstream osfile(name+"Stop.txt",ios::out);
    for(auto p:stop)
    {
        osfile<<p.stopsName<<'\n';
        osfile<<p.time<<'\n';
        osfile<<p.rent<<'\n';
    }
    ofstream oasfile(name+"AvS.txt",ios::out);
    for(auto p:availableseat)
    {
        oasfile<<p<<'\n';
    }

}
void train::gettrain()
{
    cout<<"\n\n\t\t\t~~~~Train Input~~~~\n";
    cout<<"\t\t\t----------------------\n\n";
    cout<<"\t\t\tEnter train name : "; cin>>name;
    train_no=train_name.size()+1;
    //cout<<"\t\t\tEnter train no : "; cin>>train_no;
    cout<<"\t\t\tEnter start place : "; cin>>start;
    cout<<"\t\t\tEnter destination Place : "; cin>>destination;
    cout<<"\t\t\tEnter Total number of Seats : "; cin>>seat;
    cout<<"\t\t\tEnter Total number of Stops : "; cin>>totalstops;
    cout<<"\t\t\tEnter train lefting time : "; cin>>lefttime;
    cout<<"\t\t\tEnter starting Ticket id: "; cin>>ticket;
    cout<<"\t\t\tEnter date(dd-mm-yy): "; cin>>date;

    for(int i=0;i<totalstops;i++){
            cout<<"\t\t\t\tstops no : "<<i+1<<endl;
            stops s;
            s++;
        stop.push_back(s);
        availableseat.push_back(seat);
    }
    rent=stop[stop.size()-1].rent;
    train_name.push_back(name);
    cout<<"\t\t\t****Train Successfully Added****\n";
}
void train::show()
{
    	//cout<<"\n\n\n\tTrain no:  Train name\tstart place\tdestination place\tprice\tseat\ttime\tTotal Stops\n\n";

    cout<<"\t "<<setiosflags(ios::left)<<setw(10)<<train_no<<" "<<setw(12)<<name<<" "<<setw(15)<<start<<" "<<setw(23)<<destination<<" "<<setw(7)<<rent<<" "<<setw(6)<<seat<<" "<<setw(10)<<lefttime<<"  "<<totalstops<<"\n";

}
void train::showTrainStopsDetails()
{
    cout<<"\n\t\t\t\t\t\t Train Stop-Points\n";
       cout<<"\t\t\t\t\t    ---------------------------";
     cout<<"\n\t\t\tNo.\tName\t\t\tRent\tLefting time\tAvailable seat"<<endl;
    cout<<"\t\t\t--------------------------------------------------------------------"<<endl;
    for(int i=0;i<stop.size();i++){
            cout<<"\t\t\t"<<setiosflags(ios::left)<<setw(7)<<i+1;
        stop[i].show();
       cout<<availableseat[i]<<endl<<endl;
    }
}

void trainNameload(){
    ifstream ifile("trainName.txt",ios::in);
    ifile.seekg(0,ios::end);
  int   size_ = ifile.tellg();
    ifile.seekg(0);
    while(ifile.tellg()<size_-1)
    {
        string tmp;
        ifile>>tmp;
        train_name.push_back(tmp);
    }
     //ifile.seekg(0);
}
void trainNameUpdate(){
 ofstream osfile("trainName.txt",ios::out);
    for(auto p:train_name)
    {
        osfile<<p<<'\n';
    }
}
