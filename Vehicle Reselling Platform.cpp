#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
// #include<bits/stdc++.h>

//==================User defind Header Files======================//
#include "Helper.h"
#include "classes.h"
//==================User defind Header Files======================//
using namespace std;
int main()
{
   
    string TypeUser;
    //===========================Home Menu=========================//
    while(1)
    {
        system("cls");
        position(8,5);
        _cputs("++++++++++++++++++++ Vehicle Reselling Platform ++++++++++++++++++++");
        position(21,8);
        _cputs("1.Admin");
        position(21,9);
        _cputs("2.User");
        position(21,10);
        _cputs("3.Exit");
        position(11,12);

        cout<<"Enter Your Choice:\t";
        getline(cin,TypeUser);
        switch(stoi(TypeUser))
        {
           case 1:loginAdmin();
           break;
           case 2:
           break;
           case 3:exit(0);
           break;
           default:
           position(11,14);
           _cputs("invalid option");
        }
    
    }
    //=====================End of Home Menu================//
    return 0;
}