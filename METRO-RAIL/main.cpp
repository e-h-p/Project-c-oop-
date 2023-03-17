
#include"assistant.h"

int main()
{
    loadProgram();

    int ch=1;
    while(ch){
        first_intro();
        cin>>ch;
        Random* r;
        system("cls");
        switch(ch){
        case 1: r=new User;break;
        case 2: r=new Admin; break;
        case 0: updateProgram(); exit(0);
        default:
            cout<<"\n\t\t\t~~~SoRry!!!  you have entered an invalid number~~~";
            getch(); system("cls");
            continue;
        }
        r->MENU();
    }

    updateProgram();
}
