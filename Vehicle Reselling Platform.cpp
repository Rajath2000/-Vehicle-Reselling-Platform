#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
#include<unordered_map>
// #include<bits/stdc++.h>

using namespace std;

//=================================All Global Classes===================================================//
//==================Contains The Strucre of the Record & memeber functions ============================//

class monYear{
    int month; //1 to 12
    int year; //1800 to today
};

class VechileRecorder {
   public:
   //Attributes
            string vechileNumber;  //               ||^[A-Z]{2,2}[A-Z]+[0-9]+  
            string carModelName; //                 ||MARUTHI800
            int modelYear;//                        || 1800-today(2021)
            float kmsDriven; //                     ||kilometres
            short int fuelType; //                  ||0 for PETROL 1 for DIESEL
            int transmission; //                    ||0 for MANUAL 1 for AUTOMATIC
            int enginePower; //                     ||50CC to 1500CC (CC)
            monYear registerYear; //
            short int insurenceType; //             ||0 for THIRDPARTY 1 for COMPREHENCIVE
            float milage; //                        || km/liters
            int seatingCapacity; //                 || 2,4,6,8
            int wheelerType; //                     || 0 for 2 wheeler , 1 for 3 wheeler,2 for 4 wheeler
    //constructors
            VechileRecorder(){};
    //Member Functions
            void addVechileRecord();
            void removeVechileRecord();
            void modifyVechileRecord();
            void viewVechileList();
            void viewOrderList();

            void orderVechile();
            void searchVechile();
            void viewCart();


};

//Admin Class
 class Admin{
    public:
        string username;
        string password;
        Admin(){}
        Admin(string userName, string Password)
        {
            username = userName;
            password = Password;

        }
        //Public Member Functions of Admin
};


//Ueser Class
 class User{
    public:
        string username;
        string password;
        string phoneNumber;
        User(){}
        User(string userName, string Password,string phonenumber="")
        {
            username = userName;
            password = Password;
            phoneNumber = phonenumber;
        }
 };

 //===========================================================================================//


//==================User defind Header Files======================//
#include "Helper.h"
#include "user.h"
#include "fileio.h"
#include "admin.h"
//==================User defind Header Files======================//

int main()
{
   
    string TypeUser;
    //===========================Home Menu=========================//
    while(1)
    {
        system("cls");
        dispayMessage();
        message="";
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
          case 2:loginUser();
           break;
           case 3:
           exit(0);
           break;
           default:
           position(11,14);
           _cputs("invalid option");
        }
    
    }
    //=====================End of Home Menu================//
    return 0;
}