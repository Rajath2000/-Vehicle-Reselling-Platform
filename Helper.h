#include<stdio.h>
#include<windows.h>
#include<string>
#include<bits/stdc++.h>

using namespace std;

string message;

VechileRecorder searchedVechile;

int searchFromVechileIndex(string);
//===================function to print output in required position================//
void position(int x,int y)
{
  COORD C;
  C.X=x; C.Y=y;
  SetConsoleCursorPosition(
  GetStdHandle(STD_OUTPUT_HANDLE), C);
}

//=======================Display User Message=======================//
void dispayMessage()
{
    if(message.length()>0){
    position(row-35+23,col-5);
    cout<<message;
    }
    message="";
}

//========Convert lower case to upper===================//
string toUpperCase(string str)
{
  transform(str.begin(), str.end(),str.begin(),::toupper);
  return str;
}

//=========================Table for Vechile list / single row==========================//
void dispayVechileTable()
{
  if(searchedVechile.vechileNumber.length()>0 && searchFromVechileIndex(searchedVechile.vechileNumber)>=0){
      VariadicTable<    string,         string,         int,          float,        string,        string,         int,             string,          int,             string,      float,      int,                int,         string,          int> 
      vt({          "VECHILENUMBER", "CARMODELNAME", "MODELYEAR", "KMS DRIVEN(km)","FUEL TYPE","TRANSMISSION","ENGINEPOWER(CC)","REGISTER MONTH","REGISTER YEAR","INSURENCE TYPE","MILAGE","SEATING CAOACITY","WHEELER TYPE","VECHILE TYPE","AMMOUNT ($)"}
      );

        // vt.setColumnFormat({VariadicTableColumnFormat::AUTO,
        //                 VariadicTableColumnFormat::SCIENTIFIC,
        //                 VariadicTableColumnFormat::FIXED,
        //                 VariadicTableColumnFormat::PERCENT});


    vt.addRow(searchedVechile.vechileNumber, 
                                    searchedVechile.carModelName,
                                                      searchedVechile.modelYear,
                                                                      searchedVechile.kmsDriven,
                                                                                    FUEL_TYPE[searchedVechile.fuelType],
                                                                                                 TRANSMISSION_TYPE[searchedVechile.transmission],
                                                                                                                searchedVechile.enginePower,
                                                                                                                                MONTHS[searchedVechile.registerYear.month],
                                                                                                                                searchedVechile.registerYear.year,
                                                                                                                                                      INSURENCE_TYPE[searchedVechile.insurenceType],
                                                                                                                                                            searchedVechile.milage,searchedVechile.seatingCapacity,WHEELER_TYPE[searchedVechile.wheelerType],WHEELER_VECHILES[WHEELER_TYPE[searchedVechile.wheelerType]],
                                                                                                                                                            searchedVechile.ammount       
    );

    position(2,1);
   vt.print(std::cout);
   searchedVechile.vechileNumber="";
  }
}


