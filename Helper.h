#include<stdio.h>
#include<windows.h>
#include<string>
#include<bits/stdc++.h>

using namespace std;

string message;

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
    position(8,4);
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


