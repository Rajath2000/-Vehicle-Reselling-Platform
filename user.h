#include<stdio.h>
#include<string>
#include<bits/stdc++.h>
#include<conio.h>
using namespace std;





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

void runUser(User);


//============================User SignUp ==========================//
void signUpUser()
{

    system("cls");
    position(8,4);
    _cputs("++++++++++++++++++++ Vehicle Reselling Platform ++++++++++++++++++++");
    position(28,6);
    _cputs("+++++++++ Sign Up +++++++++");


    string username,password,phoneNumber;
    int signupSucessfull=1;//set this to 1 if sign up is loginSucessfull

    position(28,9);
    _cputs("Enter Username:");
    getline(cin,username);
    position(28,10);
    _cputs("Enter password:");
    getline(cin,password);
    position(28,11);
    _cputs("Enter phoneNumber:");
    getline(cin,phoneNumber);
    
    User user(toUpperCase(username),password,phoneNumber);
   //============Perform signup with files=================s
    if(signupSucessfull)
    {
        message="Sucessfully Created Account";
        runUser(user);
    }
    else
    {
        message="User Already Exsists";
        return;
    }

}
//============================User SignUp ==========================//


//============================User Login=========================//
void loginUser()
 {
    system("cls");
    position(8,4);
    _cputs("++++++++++++++++++++ Vehicle Reselling Platform ++++++++++++++++++++");
    position(28,6);
    _cputs("+++++++++ Sign In +++++++++");


    string username,password,phoneNumber;
    int loginSucessfull=1;//set this to 1 if login is loginSucessfull
    string newUser="N";

    position(20,7);
    _cputs("N e w  U S E R ? (Y or N) : ");
    getline(cin, newUser);


    if(newUser=="N")
    {
        position(28,9);
        _cputs("Enter Username:");
        getline(cin,username);
        position(28,10);
        _cputs("Enter password:");
        getline(cin,password);

        User user(toUpperCase(username),password,phoneNumber);
        //============Perform validation with files=================s
        if(loginSucessfull)
        {
            message="Login sucessfull";
            runUser(user);
        }
        else
        {
            //Return to Vehicle Reselling platform.c login Failed
            message="Login Failed";
            return;
        } 
    }
    else
    {
        signUpUser();
    }
    
}
//============================User Login====================


//===========================User Menu================================//
void runUser(User user){
    VechileRecorder vechileRecorder;
    //Creating the Main User Object Who has some permission to Access
    User mainUser(user.username,user.password,user.phoneNumber);
    string choice;

    //===========================Admin Menu=========================//
    while(1)
    {
        system("cls");
        dispayMessage();
        position(8,5);
        _cputs("++++++++++++++++++++ Vehicle Reselling Platform ++++++++++++++++++++");

        position(30,6);
        _cputs("+++++++++ User +++++++++");
        //dispaying username
        position(30,7);
        _cputs("Hello  ");position(38,7);cout<<mainUser.username;
        position(21,9);
        _cputs("1.Order");
        position(21,10);
        _cputs("2.Search");
        position(21,11);
        _cputs("3.Cart");
        position(21,12);
        _cputs("4.Logout (Back to Main Menu)");
         position(21,15);
        cout<<"Enter Your Choice:\t";
        getline(cin,choice);
        switch(stoi(choice))
        {
           case 1:vechileRecorder.orderVechile();
           break;
           case 2:vechileRecorder.searchVechile();
           break;
           case 3:vechileRecorder.viewCart();
           break;
           case 4:
           message="Thank you for Visiting ";
           return;
           break;
           default:
           position(11,14);
           _cputs("invalid option");
        }
    
    }
    //=====================End of Admin Menu================//

}
//===========================End of User Menu=========================//

////===========================Vechile Member Functions definitions for user============================================//
void VechileRecorder::orderVechile(){}

void VechileRecorder::searchVechile(){}

void VechileRecorder::viewCart(){}
////===========================Vechile Member Functions definitions for user============================================//
