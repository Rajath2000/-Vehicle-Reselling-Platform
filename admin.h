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
        //Check for User Existence
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
            message="Login Successful";
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
    initUser();

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
        _cputs("1.Add Vehicle Record");
        position(row-35+20,col+7);
        _cputs("2.Remove Vehicle Record");
       position(row-35+20,col+8);
        _cputs("3.Modify Vehicle Record");
        position(row-35+20,col+9);
        _cputs("4.View Vehicle List");
        position(row-35+20,col+10);
        _cputs("5.View Order List");
        position(row-35+20,col+11);
        _cputs("6.Search Vehicle");
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
            _cputs("Enter Insurance Type (0 for THIRDPARTY 1 for COMPREHENSIVE ):");
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
            _cputs("Enter Vechile Amount:");
            getline(cin,temp);
            ammount=stoi(temp);


            //Validate form
            if(formValidator(*this))
            {
                //Logic for file insert
                if(writeToVechileList(*this,"Vechilelist.txt"))
                {
                    message="Record "+ vechileNumber +" Inserted Successfully";
                 
                }
                else
                {
                    message="Record "+ vechileNumber+" Already Exists";
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

            displayFullVechileTable();

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
                message="Invalid Vechile Number" ;
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
            displayFullVechileTable();

           
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
                message="Invalid Vechile Number " + vechileNumber ;
            }

        }catch(std::exception)
        {
            message="Enter Valid Details";
        }
        }

}

void VechileRecorder::modifyVechileRecord(){
        string choice="N",modify="N",modifyChoice;
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
            _cputs("+++++++++ Modify Vechile Record  +++++++++");

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
            _cputs("Enter vechileNumber to Modify ( ex:KA18A0001):");
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
                          
                           //Logic To modify
                           while(1)
                           {
                               system("cls");
                               position(row-35+20,col);
                               _cputs("++++++++++++++Enter What to modify ++++++++++++++");
                               position(2,col+1);
                               _cputs("1.Car Model Name - 2.Model Year - 3.KiloMeters Driven - 4.Fuel Type - 5.Transmission - 6.Engine Power - 7.Register (year/month) - 8.Insurance Type - 9.Milage - 10.seatingCapacity - 11.wheelerType - 12.amount");
                               position(row-35+20,col+2);
                                cout<<"Enter Your Choice:\t";
                                getline(cin,modifyChoice);

                                switch(stoi(modifyChoice))
                                {
                                    case 1:
                                    carModelName.erase();
                                    position(row-35+10,col+6);
                                    _cputs("Enter Car Model Name (ex: MARUTHI800):");
                                    getline(cin,carModelName);
                                    searchedVechile.carModelName=toUpperCase(carModelName);
                                    break;

                                    case 2:
                                    modelYear=0;
                                    temp.erase();
                                    position(row-35+10,col+6);
                                    _cputs("Enter Car Model Year (1800->today):");
                                    getline(cin,temp);
                                    searchedVechile.modelYear=stoi(temp);
                                    break;

                                    case 3:
                                    kmsDriven=0;
                                    temp.erase();
                                    position(row-35+10,col+6);
                                    _cputs("Enter Kilometer Driven (KM):");
                                    getline(cin,temp);
                                    searchedVechile.kmsDriven=stof(temp);
                                    break; 

                                    case 4:
                                    fuelType=0;
                                    temp.erase();
                                    position(row-35+10,col+6);
                                    _cputs("Enter Fuel Type (0 for PETROL 1 for DIESEL):");
                                    getline(cin,temp);
                                   searchedVechile.fuelType=stoi(temp);
                                    break;

                                    case 5:
                                    transmission=0;
                                    temp.erase();
                                    position(row-35+10,col+6);
                                    _cputs("Enter Transmission Type (0 for MANUAL 1 for AUTOMATIC):");
                                    getline(cin,temp);
                                    searchedVechile.transmission=stoi(temp);
                                    break;

                                    case 6:     
                                    enginePower=0;
                                    temp.erase();
                                    position(row-35+10,col+6);
                                    _cputs("Enter Engine Power (50CC to 2300CC (CC)):");
                                    getline(cin,temp);
                                    searchedVechile.enginePower=stoi(temp);
                                    break; 

                                    case 7:
                                    position(row-35+10,col+6);
                                    _cputs("Enter Register Month and Year:");
                                        registerYear.month=0;
                                        registerYear.year=0;
                                        temp.erase();
                                        position(row-35+15,col+8);
                                        _cputs("Enter Register Month(1->12):");
                                        getline(cin,temp);
                                        searchedVechile.registerYear.month=stoi(temp);

                                        position(row-35+15,col+10);
                                        _cputs("Enter Register Year:(1800-today)");
                                        getline(cin,temp);
                                        searchedVechile.registerYear.year=stoi(temp);
                                    break;

                                    case 8:
                                    insurenceType=0;
                                    temp.erase();
                                    position(row-35+10,col+6);
                                    _cputs("Enter Insurance Type (0 for THIRDPARTY 1 for COMPREHENSIVE):");
                                    getline(cin,temp);
                                    searchedVechile.insurenceType=stoi(temp);
                                    break;

                                    case 9:
                                               milage=0;
                                    temp.erase();
                                    position(row-35+10,col+6);
                                    _cputs("Enter Milage (km/liters):");
                                    getline(cin,temp);
                                    searchedVechile.milage=stof(temp);
                                    break; 
                                    
                                    case 10:
                                                seatingCapacity=0;
                                    temp.erase();
                                    position(row-35+10,col+6);
                                    _cputs("Enter Seating Capacity (2,4,6,8):");
                                    getline(cin,temp);
                                    searchedVechile.seatingCapacity=stoi(temp);
                                    break;

                                    case 11:
                                    wheelerType=0;
                                    temp.erase();
                                    position(row-35+10,col+6);
                                    _cputs("Enter Wheeler Type (0 for 2 wheeler , 1 for 3 wheeler,2 for 4 wheeler):");
                                    getline(cin,temp);
                                    searchedVechile.wheelerType=stoi(temp);
                                    break;

                                    case 12:
                                    ammount=0;
                                    temp.erase();
                                    position(row-35+10,col+6);
                                    _cputs("Enter Vechile Amount:");
                                    getline(cin,temp);
                                    searchedVechile.ammount=stoi(temp);
                                    break; 

                                }

                                bool val=formValidator(searchedVechile);

                                position(row-35+20+1,col+12);
                                _cputs(" Done With Modifying ? (Y or N) : ");
                                getline(cin,modify);
                                if(toUpperCase(modify) == "Y")
                                {
                                break;
                                }
                           }

                                //Validate form
                                if(formValidator(searchedVechile))
                                {
                                    //Logic for file insert
                                    deleteRowFromVechileListat(pos,searchedVechile.vechileNumber);
                                    if(writeToVechileList(searchedVechile,"Vechilelist.txt"))
                                    {
                                        message="Record "+ vechileNumber +" Modified Successfully ";
                                    
                                    }
                                    else
                                    {
                                        message="Error in "+ vechileNumber+" Already Exists";
                                    }
                                }
                       }
                   }
                   else
                   {
                       message="No Records on "+vechileNumber+" Found in Vechile list";
                   }
            }
            else
            {
                message="Invalid Vechile Number1" +vechileNumber;
            }

        }catch(std::exception)
        {
            message="Enter Valid Details";
        }
    }

}

void VechileRecorder::viewVechileList(){
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
            _cputs("+++++++++  Vechile List  +++++++++");



            displayFullVechileTable();


            position(row-35+20+1,col+4);
            _cputs("Back to Main Menu ? (Y or N) : ");
            getline(cin,choice);
            if(toUpperCase(choice) == "Y")
            {
               return;
            }
    

        }
}

void VechileRecorder::viewOrderList(){
        string choice="N";
        string temp;
        while(1)
        {
            system("cls");
            dispayMessage();
            position(row-35,col);
            _cputs("++++++++++++++++++++ Vehicle Reselling Platform ++++++++++++++++++++");
            position(row-35+20,col+2);
            _cputs("+++++++++ Place Your Order  +++++++++");


            // position(10,col+10);
             orderLists();



            position(row-35+20+1,col+4);
            _cputs("Back to Main Menu ? (Y or N) : ");
            getline(cin,choice);

            



            if(toUpperCase(choice) == "Y")
            {
               return;
            }



        }
}
//===========================End of Vechile Member Functions definitions=====================================//


bool formValidator(VechileRecorder Vechilerecorder)
{
    regex vechileRegex("^[A-Z]{2,2}[0-9]{2,2}[A-Z]+[0-9]{4,4}$");

    if(!(regex_match(Vechilerecorder.vechileNumber,vechileRegex) ))
    {
        message="Invalid Vechile Number2" +Vechilerecorder.vechileNumber ;
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
        message="Enter valid transmissions";
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
        message="Enter Valid Insurance Type";
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
        message="Enter Valid Amount";
       return false;
    }
    return true;
}