#include<stdio.h>
#include<string>
#include<bits/stdc++.h>
#include<conio.h>
using namespace std;

//========================All Global variables=========================//
unordered_map<string, User> userDetails;
//========================All Global variables=========================//




//============================global User defind functions=============(This is becase these function will be called before their definition)===============//
void runUser(User);
bool writeToUserFile(string,string,string,string);
void readFromUserFile(string,int);
//============================End of global User defind functions============================//



//============================User SignUp ==========================//
void signUpUser()
{

    system("cls");
     position(row-35,col);
    _cputs("++++++++++++++++++++ Vehicle Reselling Platform ++++++++++++++++++++");
    position(row-35+20,col+2);
    _cputs("+++++++++ Sign Up +++++++++");


    string username,password,phoneNumber;
    int signupSucessfull=0;//set this to 1 if sign up is loginSucessfull

     position(row-35+20,col+4);
    _cputs("Enter Username:");
    getline(cin,username);
     position(row-35+20,col+5);
    _cputs("Enter password:");
    getline(cin,password);
     position(row-35+20,col+6);
    _cputs("Enter phoneNumber:");
    getline(cin,phoneNumber);
    
    User user((toUpperCase(username)),password,phoneNumber);
    if(username.length()>0 && password.length()>0 && phoneNumber.length()>0 && phoneNumber.length()==10)
    {
        //========================Write to the user.txt file if the user is new ============================//
        if(writeToUserFile("user.txt",(toUpperCase(username)),password,phoneNumber))
                    signupSucessfull=1;
        //==================================================================================================//
        if(signupSucessfull)
        {
            message="Sucessfully Created Account";
            //Automatic Login
            runUser(user);
        }
        else
        {
            message="User Already Exsists";
            return;
        }
    }
    else
    {
        message="All Faileds are required";
    }

}
//============================User SignUp ==========================//


//============================User Login=========================//
void loginUser()
 {
    system("cls");
    position(row-35,col);
    _cputs("++++++++++++++++++++ Vehicle Reselling Platform ++++++++++++++++++++");
    position(row-35+20,col+2);
    _cputs("+++++++++ Sign In +++++++++");


    string username,password,phoneNumber;
    int loginSucessfull=0;//set this to 1 if login is loginSucessfull
    string newUser="N";

    position(row-35+20+1,col+4);
    _cputs("New  USER ? (Y or N) : ");
    getline(cin, newUser);


    if(newUser=="N")
    {
        position(row-35+20,col+6);
        _cputs("Enter Username:");
        getline(cin,username);
        position(row-35+20,col+7);
        _cputs("Enter password:");
        getline(cin,password);

        User user(toUpperCase(username),password,phoneNumber);
         //============Perform validation with files=================//
        //Read all user from file
        readFromUserFile("user.txt",0);
        
        //check user exists 
        if(userDetails.find(user.username)==userDetails.end())
               loginSucessfull=0;
        else
        {
            //if  exists compare the password
            if(userDetails.at(user.username).password == password)
                loginSucessfull=1;
        }
       //============================================================//
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
        position(row-35,col);
        _cputs("++++++++++++++++++++ Vehicle Reselling Platform ++++++++++++++++++++");

        position(row-35+20,col+2);
        _cputs("+++++++++ User +++++++++");
        //dispaying username
        position(row-35+23,col+4);
        _cputs("Hello  ");position(row-35+23+8,col+4);cout<<mainUser.username;
        position(row-35+20,col+6);
        _cputs("1.Order");
        position(row-35+20,col+7);
        _cputs("2.Search");
        position(row-35+20,col+8);
        _cputs("3.Cart");
        position(row-35+20,col+9);
        _cputs("4.Logout (Back to Main Menu)");
         position(row-35+20,col+11);
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
                    position(row-35+20,col+15);
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
