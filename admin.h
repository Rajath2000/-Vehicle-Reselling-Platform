#include<stdio.h>
#include<string>
#include<bits/stdc++.h>

using namespace std;


//========================All Global variables=========================//
string const FUEL_TYPE[]={"PETROL","DIESEL"};
string  const INSURENCE_TYPE[]={"THIRDPARTY","COMPREHENSIVE"};
int     const WHEELER_TYPE[]={2,3,4};
string  const WHEELER_TYPE2[]={"MOTERCYCLES"};
string  const WHEELER_TYPE3[]={"RICKSHAWS"};
string  const WHEELER_TYPE4[]={"CAR"};
string  const TRANSMISSION_TYPE[]={"MANUAL","AUTOMATIC"};
string  const MONTHS[]={"","JAN","FEB","MAR","APR","MAY","JUN","JUL","AUG","SEP","OCT","NOV","DEC"};
//========================All Global variables=========================//

//============================global User defind functions============================//
string toUpperCase(string str)
{
  transform(str.begin(), str.end(),str.begin(),::toupper);
  return str;
}
//============================global User defind functions============================//

//==================Contains The Strucre of the Record & memeber functions ============================//

class monYear{
    int month; //1 to 12
    int year; //1800 to today
};

class VechileRecorder {
   public:
   //Attributes
            string vechileNumber; // ^[A-Z]{2,2}[A-Z]+[0-9]+  
            string carModelName;  //MARUTHI800
            int modelYear; // 1800-today(2021)
            float kmsDriven; //kilometres
            short int fuelType;  //  0 for PETROL 1 for DIESEL
            int transmission;  // 0 for MANUAL 1 for AUTOMATIC
            int enginePower; //50CC to 1500CC (CC)
            monYear registerYear; //
            short int insurenceType;  // 0 for THIRDPARTY 1 for COMPREHENCIVE
            float milage; // km/liters
            int seatingCapacity; // 2,4,6,8
            int wheelerType; // 0 for 2 wheeler , 1 for 3 wheeler,2 for 4 wheeler
    //constructors
            VechileRecorder(){};
    //Member Functions
            void addVechileRecord();
            void removeVechileRecord();
            void modifyVechileRecord();
            void viewVechileList();
            void viewOrderList();


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


void runAdmin(Admin);
//=======================Admin login==================//
void loginAdmin() {
    system("cls");
    position(8,5);
    _cputs("++++++++++++++++++++ Vehicle Reselling Platform ++++++++++++++++++++");
    position(28,7);
    _cputs("+++++++++ Sign In +++++++++");


    string username,password;
    int loginSucessfull=1;//set this to 1 if login is loginSucessfull


    position(28,8);
    _cputs("Enter Username:");
    getline(cin,username);
    position(28,10);
    _cputs("Enter password:");
    getline(cin,password);


    Admin admin(toUpperCase(username),password);
    //============Perform validation with files=================s
    if(loginSucessfull)
    {
         runAdmin(admin);
    }
    else
    {
        //Return to Vehicle Reselling platform.c login Failed
        return;
    } 
}
//============================Admin Login====================



//===================================Run The Admin Main Function================================
void runAdmin(Admin admin)
{
    VechileRecorder vechileRecorder;
    //Creating the Main Admin Object Who has all permission to Access
    Admin mainAdmin(admin.username,admin.password);
    string choice;

    //===========================Admin Menu=========================//
    while(1)
    {
        system("cls");
        position(8,5);
        _cputs("++++++++++++++++++++ Vehicle Reselling Platform ++++++++++++++++++++");

        position(30,6);
        _cputs("+++++++++ Admin +++++++++");
        //dispaying username
        position(30,7);
        _cputs("Hello  ");position(38,7);cout<<mainAdmin.username;
        position(21,9);
        _cputs("1.Add Vechile Record");
        position(21,10);
        _cputs("2.Remove Vechile Record");
        position(21,11);
        _cputs("3.Modify Vechile Record");
        position(21,12);
        _cputs("4.View Vechile List");
        position(21,13);
        _cputs("5.View Order List");
        position(21,14);
        _cputs("6.Logout (Back to Main Menu)");
        position(11,17);
        cout<<"Enter Your Choice:\t";
        getline(cin,choice);
        switch(stoi(choice))
        {
           case 1:vechileRecorder.addVechileRecord();
           break;
           case 2:vechileRecorder.removeVechileRecord();
           break;
           case 3:vechileRecorder.modifyVechileRecord();
           break;
           case 4:vechileRecorder.viewVechileList();
           break;
           case 5:vechileRecorder.viewOrderList();
           break;
           case 6:return;
           break;
           default:
           position(11,14);
           _cputs("invalid option");
        }
    
    }
    //=====================End of Admin Menu================//


}
//===================================End of Run The Admin Main Function================================



//===========================Vechile Member Functions definitions============================================//
void VechileRecorder::addVechileRecord(){};

void VechileRecorder::removeVechileRecord(){};

void VechileRecorder::modifyVechileRecord(){};

void VechileRecorder::viewVechileList(){};

void VechileRecorder::viewOrderList(){};
//===========================End of Vechile Member Functions definitions=====================================//
