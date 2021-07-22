#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
#include<unordered_map>
#include<regex>
//#include<bits/stdc++.h>

using namespace std;


//=====================================Third Party Modules========================//
//For printing Table
#include "include/VariadicTable.h"
//================================================================================//

int row=84;
int col=10;
int tablespace=10;


//========================All Global variables=========================//
string const FUEL_TYPE[]={"PETROL","DIESEL"};
string  const INSURENCE_TYPE[]={"THIRDPARTY","COMPREHENSIVE"};
int     const WHEELER_TYPE[]={2,3,4};
string const WHEELER_VECHILES[]={"","","MOTERCYCLES","RICKSHAWS","CAR",""};
// string  const WHEELER_TYPE2[]={"MOTERCYCLES"};
// string  const WHEELER_TYPE3[]={"RICKSHAWS"};
// string  const WHEELER_TYPE4[]={"CAR"};
string  const TRANSMISSION_TYPE[]={"MANUAL","AUTOMATIC"};
string  const MONTHS[]={"","JAN","FEB","MAR","APR","MAY","JUN","JUL","AUG","SEP","OCT","NOV","DEC"};
//========================All Global variables=========================//
//=================================All Global Classes===================================================//
//==================Contains The Strucre of the Record & memeber functions ============================//

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
class monYear{
    public:
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
            int fuelType; //                  ||0 for PETROL 1 for DIESEL
            int transmission; //                    ||0 for MANUAL 1 for AUTOMATIC
            int enginePower; //                     ||50CC to 1500CC (CC)
             monYear registerYear; //
             int insurenceType; //             ||0 for THIRDPARTY 1 for COMPREHENCIVE
            float milage; //                        || km/liters
            int seatingCapacity; //                 || 2,4,6,8
            int wheelerType; //                     || 0 for 2 wheeler , 1 for 3 wheeler,2 for 4 wheeler
             int ammount;
    //constructors
            VechileRecorder(){};
    //Member Functions
            void addVechileRecord();
            void removeVechileRecord();
            void modifyVechileRecord();
            void viewVechileList();
            void viewOrderList();
          

            void orderVechile(User);
            void searchVechile();
            void viewCart(User);


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

class OrderRecorder{
        public:
        string vechileNumber;
        string username;
        string phoneNumber;
        int myAddress;
        OrderRecorder(){}

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
        system("cls");
        welcome_dance();
    
    string TypeUser;
    //===========================Home Menu=========================//
    while(1)
    {

        system("cls");
        dispayMessage();
        message="";
        position(row-35,col);
        _cputs("++++++++++++++++++++ Vehicle Reselling Platform ++++++++++++++++++++");
        position(row-35+10,col+3);
        _cputs("1.Admin");
        position(row-35+10,col+4);
        _cputs("2.User");
        position(row-35+10,col+5);
        _cputs("3.Exit");
        position(row-35+10,col+7);

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
           position(row-35+15,col+10);
           _cputs("invalid option");
        }
    
    }
    //=====================End of Home Menu================//
    return 0;
}

