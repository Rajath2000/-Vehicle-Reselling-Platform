#include<stdio.h>
#include<string>
#include<bits/stdc++.h>

using namespace std;




//============================global User defind functions=============(This is becase these function will be called before their definition)===============//

//============================End of global User defind functions============================//



void runAdmin(Admin);
bool formValidator(VechileRecorder);
//=======================Admin login==================//
void loginAdmin() {
    system("cls");
    position(row-35,col);
    _cputs("++++++++++++++++++++ Vehicle Reselling Platform ++++++++++++++++++++");
    position(row-35+20,col+2);
    _cputs("+++++++++ Sign In +++++++++");


    string username,password;
    int loginSucessfull=0;//set this to 1 if login is loginSucessfull


    position(row-35+20,col+4);
    _cputs("Enter Username:");
    getline(cin,username);
    position(row-35+20,col+5);
    _cputs("Enter password:");
    getline(cin,password);

    if(username.length()>0 && password.length()>0)
    {
        Admin admin((toUpperCase(username)),password);
        //============Perform validation with files=================//
        readFromAdminFile("admin.txt");
        //Check for User Exsistence
        if(adminDetails.find(admin.username)==adminDetails.end())
                 loginSucessfull=0;
        else
        {
            //if user exists,the compare password
            if(adminDetails.at(admin.username)==password)
                loginSucessfull=1;
        }        
        //===========================================================//
        if(loginSucessfull)
        {
            message="Login Sucessfull";
            runAdmin(admin);
            
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
        message="Username or Password required";
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

    intiAdmin();

    //===========================Admin Menu=========================//
    while(1)
    {
        system("cls");
        dispayMessage();
        position(row-35,col);
        _cputs("++++++++++++++++++++ Vehicle Reselling Platform ++++++++++++++++++++");
        position(row-35+20,col+2);
        _cputs("+++++++++ Admin +++++++++");
        //dispaying username
        position(row-35+23,col+4);
        _cputs("Hello  ");position(row-35+23+8,col+4);cout<<mainAdmin.username;
        position(row-35+20,col+6);
        _cputs("1.Add Vechile Record");
        position(row-35+20,col+7);
        _cputs("2.Remove Vechile Record");
       position(row-35+20,col+8);
        _cputs("3.Modify Vechile Record");
        position(row-35+20,col+9);
        _cputs("4.View Vechile List");
        position(row-35+20,col+10);
        _cputs("5.View Order List");
        position(row-35+20,col+11);
        _cputs("6.Search Vechile");
        position(row-35+20,col+13);
        _cputs("7.Logout (Back to Main Menu)");
        position(row-35+20,col+15);
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
           case 6:vechileRecorder.searchVechile();
           break;
           case 7:
            message="Thank you for Visiting";
           return;
           break;
           default:
           position(row-35+20,col+19);
           _cputs("invalid option");
        }
    
    }
    //=====================End of Admin Menu================//


}
//===================================End of Run The Admin Main Function================================



//===========================Vechile Member Functions definitions============================================//
void VechileRecorder::addVechileRecord(){
        string choice="N";
        string temp;
        while(1)
        {
            system("cls");
            dispayMessage();
            position(row-35,col);
            _cputs("++++++++++++++++++++ Vehicle Reselling Platform ++++++++++++++++++++");
            position(row-35+20,col+2);
            _cputs("+++++++++ Enter Vechile Details  +++++++++");

            position(row-35+20+1,col+4);
            _cputs("Back to Main Menu ? (Y or N) : ");
            getline(cin,choice);
            if(toUpperCase(choice) == "Y")
            {
               return;
            }
         
         try{
            vechileNumber.erase();
            position(row-35+10,col+6);
            _cputs("Enter vechileNumber ( ex:KA18A0001):");
            getline(cin,vechileNumber);
            vechileNumber=toUpperCase(vechileNumber);

            
            carModelName.erase();
            position(row-35+10,col+8);
            _cputs("Enter Car Model Name (ex: MARUTHI800):");
            getline(cin,carModelName);
            carModelName=toUpperCase(carModelName);

            modelYear=0;
            temp.erase();
            position(row-35+10,col+10);
            _cputs("Enter Car Model Year (1800->today):");
            getline(cin,temp);
            modelYear=stoi(temp);


            kmsDriven=0;
            temp.erase();
            position(row-35+10,col+12);
            _cputs("Enter Kilometer Driven (KM):");
            getline(cin,temp);
            kmsDriven=stof(temp);


            fuelType=0;
            temp.erase();
            position(row-35+10,col+14);
            _cputs("Enter Fuel Type (0 for PETROL 1 for DIESEL):");
            getline(cin,temp);
            fuelType=stoi(temp);


            transmission=0;
            temp.erase();
            position(row-35+10,col+16);
            _cputs("Enter Transmission Type (0 for MANUAL 1 for AUTOMATIC):");
            getline(cin,temp);
            transmission=stoi(temp);


            enginePower=0;
            temp.erase();
            position(row-35+10,col+18);
            _cputs("Enter Engine Power (50CC to 2300CC (CC)):");
            getline(cin,temp);
            enginePower=stoi(temp);


            position(row-35+10,col+20);
            _cputs("Enter Register Month and Year:");
                registerYear.month=0;
                registerYear.year=0;
                temp.erase();
                position(row-35+15,col+21);
                _cputs("Enter Register Month(1->12):");
                getline(cin,temp);
                registerYear.month=stoi(temp);

                position(row-35+15,col+22);
                _cputs("Enter Register Year:(1800-today)");
                getline(cin,temp);
                registerYear.year=stoi(temp);

            
            insurenceType=0;
            temp.erase();
            position(row-35+10,col+24);
            _cputs("Enter Insurence Type (0 for THIRDPARTY 1 for COMPREHENCIVE):");
            getline(cin,temp);
            insurenceType=stoi(temp);


            milage=0;
            temp.erase();
            position(row-35+10,col+26);
            _cputs("Enter Milage (km/liters):");
            getline(cin,temp);
            milage=stof(temp);

            seatingCapacity=0;
            temp.erase();
            position(row-35+10,col+28);
            _cputs("Enter Seating Capacity (2,4,6,8):");
            getline(cin,temp);
            seatingCapacity=stoi(temp);


            wheelerType=0;
            temp.erase();
            position(row-35+10,col+30);
            _cputs("Enter Wheeler Type (0 for 2 wheeler , 1 for 3 wheeler,2 for 4 wheeler):");
            getline(cin,temp);
            wheelerType=stoi(temp);

            ammount=0;
            temp.erase();
            position(row-35+10,col+32);
            _cputs("Enter Vechile Ammount:");
            getline(cin,temp);
            ammount=stoi(temp);


            //Validate form
            if(formValidator(*this))
            {
                //Logic for file insert
                if(writeToVechileList(*this,"Vechilelist.txt"))
                {
                    message="Record "+ vechileNumber +" Inserted Sucessfully";
                 
                }
                else
                {
                    message="Record "+ vechileNumber+" Already Exsists";
                }
            }

         }catch(std::exception)
         {
             message = "Enter The Valid Details";
         }
        
        }
        
}

void VechileRecorder::searchVechile()
{
        
        string choice="N";
        string temp;
        int pos;
        while(1)
        {
            system("cls");
            dispayMessage();
            dispayVechileTable();
            position(row-35,col);
            _cputs("++++++++++++++++++++ Vehicle Reselling Platform ++++++++++++++++++++");
            position(row-35+20,col+2);
            _cputs("+++++++++ Search Vechile  +++++++++");

            position(row-35+20+1,col+4);
            _cputs("Back to Main Menu ? (Y or N) : ");
            getline(cin,choice);
            if(toUpperCase(choice) == "Y")
            {
               return;
            }


        try{
            vechileNumber.erase();
            position(row-35+10,col+6);
            _cputs("Enter vechileNumber to Search ( ex:KA18A0001):");
            getline(cin,vechileNumber);
            vechileNumber=toUpperCase(vechileNumber);

            regex vechileRegex("^[A-Z]{2,2}[0-9]{2,2}[A-Z]+[0-9]{4,4}$");

            if(regex_match(vechileNumber,vechileRegex))
            {
                    //Logic to search from filename
                   pos = searchFromVechileIndex(vechileNumber);
                   if(pos>=0)
                   {
                       //need a update
                       searchedVechile = UnpackVechileDataFrom(pos);
                       if(searchedVechile.vechileNumber.length()==0){
                          message="No Records on "+vechileNumber+" Found in Vechile list";
                       }
                   }
                   else
                   {
                       message="No Records on "+vechileNumber+" Found in Vechile list";
                   }
            }
            else
            {
                message="Invalid Vechile Number";
            }

        }catch(std::exception)
        {
            message="Enter Valid Details";
        }


}
}

void VechileRecorder::removeVechileRecord(){
        string choice="N";
        string temp;
        int pos;
        while(1)
        {
            system("cls");
            dispayMessage();
            position(row-35,col);
            _cputs("++++++++++++++++++++ Vehicle Reselling Platform ++++++++++++++++++++");
            position(row-35+20,col+2);
            _cputs("+++++++++ Remove Vechile  +++++++++");

            position(row-35+20+1,col+4);
            _cputs("Back to Main Menu ? (Y or N) : ");
            getline(cin,choice);
            if(toUpperCase(choice) == "Y")
            {
               return;
            }

            

        try{
            vechileNumber.erase();
            position(row-35+10,col+6);
            _cputs("Enter vechileNumber to Remove ( ex:KA18A0001):");
            getline(cin,vechileNumber);
            vechileNumber=toUpperCase(vechileNumber);

            regex vechileRegex("^[A-Z]{2,2}[0-9]{2,2}[A-Z]+[0-9]{4,4}$");

            if(regex_match(vechileNumber,vechileRegex))
            {
                    //Logic to search from filename
                   pos = searchFromVechileIndex(vechileNumber);
                   if(pos>=0)
                   {

                        //need a update
                       searchedVechile = UnpackVechileDataFrom(pos);
                       if(searchedVechile.vechileNumber.length()==0){
                          message="No Records on "+vechileNumber+" Found in Vechile list";
                       }
                       else
                       {
                        deleteRowFromVechileListat(pos,vechileNumber);
                         message="Record "+vechileNumber+" Deleted from Vechile list";
                       }
                      
                   }
                   else
                   {
                       message="No Records on "+vechileNumber+" Found in Vechile list";
                   }
            }
            else
            {
                message="Invalid Vechile Number";
            }

        }catch(std::exception)
        {
            message="Enter Valid Details";
        }
        }

}

void VechileRecorder::modifyVechileRecord(){

}

void VechileRecorder::viewVechileList(){}

void VechileRecorder::viewOrderList(){}
//===========================End of Vechile Member Functions definitions=====================================//


bool formValidator(VechileRecorder Vechilerecorder)
{
    regex vechileRegex("^[A-Z]{2,2}[0-9]{2,2}[A-Z]+[0-9]{4,4}$");

    if(!(regex_match(Vechilerecorder.vechileNumber,vechileRegex) ))
    {
        message="Invalid Vechile Number";
        return false;
    }
    if( Vechilerecorder.carModelName.length() < 0)
    {
        message="Invalid car Model Name";
        return false;
    }
    if( Vechilerecorder.modelYear < 1800 || Vechilerecorder.modelYear > 2021 )
    {
        message="Enter Model Year In range";
        return false;
    }
    if( Vechilerecorder.kmsDriven < 0)
    {
        message="Enter KMS Driven in Range";
        return false;
    }
    if( !(Vechilerecorder.fuelType  >= 0 && Vechilerecorder.fuelType<=1) )
    {
        message="Enter KMS Driven in Range";
        return false;
    }
    if( !(Vechilerecorder.transmission  >= 0 && Vechilerecorder.transmission<=1) )
    {
        message="Enter valid trabsmissione";
        return false;
    }
    if( !(Vechilerecorder.enginePower  >= 50 && Vechilerecorder.enginePower<=2300) )
    {
        message="Enter Valid Engine Power";
        return false;
    }
    if( !(Vechilerecorder.registerYear.year >= 1800 && Vechilerecorder.registerYear.year<=2021) )
    {
        message="Enter Register Year In range";
        return false;
    }
    if( !(Vechilerecorder.registerYear.month >= 1 && Vechilerecorder.registerYear.month <=12) )
    {
        message="Enter Register Month In range";
        return false;
    }
    if( !(Vechilerecorder.insurenceType >= 0 && Vechilerecorder.insurenceType <=1) )
    {
        message="Enter Valid Insurence Type";
        return false;
    }
    if(Vechilerecorder.milage < 0)
    {
        message="Enter Valid Milage Type";
        return false;
    }
    if( !(Vechilerecorder.seatingCapacity >= 2 && Vechilerecorder.seatingCapacity <=8) )
    {
        message="Enter Valid seatingCapacity";
        return false;
    }
     if( !(Vechilerecorder.wheelerType >= 0 && Vechilerecorder.wheelerType <=2) )
    {
        message="Enter Valid seatingCapacity";
        return false;
    }
    if(Vechilerecorder.ammount<=0)
    {
        message="Enter Valid Ammount";
       return false;
    }
    return true;
}