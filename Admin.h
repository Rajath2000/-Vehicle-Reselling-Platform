#include<stdio.h>
#include<string>
using namespace std;

string toUpperCase(string str)
{
  transform(str.begin(), str.end(),str.begin(),::toupper);
  return str;
}

//==================Contains The Strucre of the Record & memeber functions ============================//

struct monYear{
    string month;
    int year;
};

class VechileRecorder {
   public:
            string vechileNumber;
            string carModelName;
            int modelYear;
            int kmsDriven;
            string fuelType;
            string transmission;
            int enginePower;
            monYear registerYear;
            string insurenceType;
            int milage;
            int seatingCapacity;
            string vehicleType;




       
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
           case 1:
           break;
           case 2:
           break;
           case 3:
           break;
           case 4:
           break;
           case 5:
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
