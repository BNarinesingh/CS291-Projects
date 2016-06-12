//  main.cpp
//  e-voting program Copyright (c) Barindra Narinesingh. All rights reserved.
//

#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <fstream>

using namespace std;
int voterholder[1001];          //holds original voter list
int votedAlready[1001]={1};     //holds 1 for for every voter
int adminC;
int can1T=0,can2T=0;

int search(int voterholer[1001], int voterid)
{
    int index=0;
    int position= -1;
    bool found= false;
    while (index< 1001 &&!found){
        if (voterholer[index]==voterid)
        {
            found= true;
            position=index;
        }
        index++;
    }
    return position;
}

void printvoters()
{   fstream dataFile("valid_ids.txt", ios::in);  // left file alone to prevent voter changing.
    char input[10000];
    dataFile.getline(input,10000,'$');
    cout<<"\n";
    cout<<input<<endl;
    dataFile.getline(input,10000,'$');
    dataFile.close();
}

void voters_holder()
{
    for(int x=1000;x<2001;x++)
        voterholder[x-1000]=x;
    
}


void selectScreen()
{
    cout<<"\nSelect candidate to vote for: "<<endl;
    cout<<"1) To Vote for bill will help Hillary hit 1 "<<endl;
    cout<<"2) To Vote for buying the election Romney hit 2 "<<endl<<endl;
}


int main() {


ofstream votesSaved("Voted_ids.txt",ios::app);
ofstream voteAccess("VoteA_history.txt",ios::app);
ofstream votedIds("Democracy_works.txt",ios::app);
    
int voterid,who;

do{
cout<<"Enter 4 digit voter id number : ";
cin>>voterid;

    voters_holder();  //populates voters, used instead to avoid constant file referencing.

    int onlist;
    onlist=search(voterholder,voterid);
    
    cout<<onlist<<" ";  //for debugg purposes
    
    if(votedAlready[onlist]==-2 )            //checks list for double voters
    {cout<<" voter id has voted already";
     voteAccess<<voterid<<" Attempted to vote again "<<endl;
    }
    
    else if (onlist!=-1){
     cout<<"valid voter id";

    selectScreen();
    
    cin>>who;
    cout<< string(50,'\n');


    votesSaved<<who<<" "<<endl;
    votedIds<<voterid<<" "<<endl;
    voteAccess<<voterid<< " voted "<<endl; //need to fix
    
        votedAlready[onlist]=-2;    //changes list of 1s to -2s to prevent double voting
    
    cout<<"Your vote has been tallied, thank you for voting "<<endl<<endl<<endl;
    }
    
    else if (onlist==-1 && voterid!=7777)
    {cout<<"invalid voter id, please enter an valid voter id"<<endl<<endl;
     voteAccess<<voterid<< " invalid access "<<endl;
    }
        
}while(voterid!=7777);

do{
    
cout<<"Welcome to admininistraion options "<<endl
    <<"Current administration options are as follows: "<<endl
    <<"1) Print tallys"<<endl
    <<"2) Print list of valid voter ids"<<endl
    <<"3) Print list of ids who have voted"<<endl
    <<"4) Print paper trail "<<endl
    <<"5) Quit program"<<endl;
    cin>>adminC;
    
    if(adminC==1)
    {
        cout<<"Current voted tallys are as follows:"<<endl;
        cout<<"Candidate 1 has "<<can1T<<" votes"<<endl
            <<"Candidate 2 has "<<can2T<<" votes"<<endl;
        
        cout<<"To see voters on file, please verify you are not a bot by "<<endl;
        
        
        { fstream file;
            char can1='1',can2='2';
            char fileName[50],ch;
            
            
            cout<<"Entering Voted_ids.txt "; // trys to reuse a old function
            cin>>fileName;
            file.open(fileName,ios::in);
            if(!file)
            {cout<<fileName<<" could not be opened. /n";
            }
            file.get(ch);
            while(!file.eof())
            {cout<<ch;
             if(ch==can1)
                 can1T++;
             if(ch==can2)
                 can2T++;
                
                file.get(ch);
            }
            file.close();
        cout<<"Candidate 1 has "<<can1T<<" votes"<<endl
            <<"Candidate 2 has "<<can2T<<" votes"<<endl;
        
        char evil;
        cout<<"Would you like to adjust voter values? ";
        cin>>evil;
        
        if(evil=='y'||evil=='Y')
        {cout<<"How many votes would you like Candidate 1 to have ? ";
            cin>>can1T;
        cout<<"How many votes would you like Candidate 2 to have ? ";
            cin>>can2T;
        }
            
        cout<< string(10,'\n');
        }
        

        
    }
    
    else if(adminC==2)
    {    cout<<"Current voter id list are as follows: "<<endl;
        printvoters();
        cout<< string(10,'\n');
    }
    
    else if(adminC==3)
    {
        cout<<"ids that have voted thus far : "<<endl;
        
        fstream dataFile("Democracy_works.txt", ios::in);
        char input[10000];
        dataFile.getline(input,10000,'$');
        cout<<"\n";
        cout<<input<<endl;
        dataFile.getline(input,10000,'$');
        dataFile.close();
        cout<< string(10,'\n');
    }
    
    else if(adminC==4)
    {
        cout<<"Current history (paper trail) is as follows: "<<endl;
        
        fstream dataFile("VoteA_history.txt", ios::in);
        char input[10000];
        dataFile.getline(input,10000,'$');
        cout<<"\n";
        cout<<input<<endl;
        dataFile.getline(input,10000,'$');
        dataFile.close();
        cout<< string(10,'\n');
    }
    
    else if(adminC==5)
    {   cout<< string(10,'\n');
        cout<<"Thank you and have a nice day"<<endl;
        break;
    }
}while(adminC!=5);
    
votesSaved.close();
voteAccess.close();
votedIds.close();

    system("pause");
    return 0;
}
