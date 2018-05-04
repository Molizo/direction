#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

using namespace std;

int map[15][15];
int main()
{
    int pozr=7,pozc=7,foodr,foodc,points=0;
    srand(time(NULL));
    map[pozr][pozc]=1;
    for(int i=0;i<15;i++)
    {
        foodr=rand()%15;
        foodc=rand()%15;
        map[foodr][foodc]=2;
    }
    for(int i=0;i<15;i++)
    {
        for(int j=0;j<15;j++)
        {
            char ch1=219,ch2=43;
            if(map[i][j]==0)
                cout<<" ";
            if(map[i][j]==1)
                cout<<ch1;
            if(map[i][j]==2)
                cout<<ch2;
        }
        cout<<"\n";
    }
    int start=clock();
    while(true)
    {
        if(kbhit()==0)
        {
            char key=getch();
            if(key=='d')
            {
                if(pozc+1!=15)
                    if(map[pozr][pozc+1]==2)
                        points+=100;
                map[pozr][pozc]=0;
                pozc++;
                if(pozc==15)
                    pozc=0;
                map[pozr][pozc]=1;
            }
            else if(key=='a')
            {
                if(pozc-1!=-1)
                    if(map[pozr][pozc-1]==2)
                        points+=100;
                map[pozr][pozc]=0;
                pozc--;
                if(pozc==-1)
                    pozc=14;
                map[pozr][pozc]=1;
            }
            else if(key=='w')
            {
                if(pozr-1!=-1)
                    if(map[pozr-1][pozc]==2)
                        points+=100;
                map[pozr][pozc]=0;
                pozr--;
                if(pozr==-1)
                    pozr=14;
                map[pozr][pozc]=1;
            }
            else if(key=='s')
            {
                if(pozr+1!=15)
                    if(map[pozr+1][pozc]==2)
                        points+=100;
                map[pozr][pozc]=0;
                pozr++;
                if(pozr==15)
                    pozr=0;
                map[pozr][pozc]=1;
            }
        }
        Sleep(50);
        system("cls");
        for(int i=0;i<15;i++)
        {
            for(int j=0;j<15;j++)
            {
                char ch1=219,ch2=43;
                if(map[i][j]==0)
                    cout<<" ";
                if(map[i][j]==1)
                    cout<<ch1;
                if(map[i][j]==2)
                    cout<<ch2;
            }
            cout<<"\n";
        }
        int end=clock();
        if(end-start>20000)
        {
            cout<<"Time limit!\n";
            cout<<"Points: "<<points;
            return 0;
        }
        int food=0;
        for(int i=0;i<15;i++)
        {
            for(int j=0;j<15;j++)
                if(map[i][j]==2)
                    food++;
        }
        if(food=0)
        {
            cout<<"Game Over!\n";
            cout<<"Points: "<<points;
            return 0;
        }
    }
    return 0;
}
