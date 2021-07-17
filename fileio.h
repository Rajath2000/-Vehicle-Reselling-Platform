#include<fstream>
#include <unordered_map>
using namespace std;

//=====================Which stores in a Hash Table(username,password) pair ========================//
unordered_map<string, string> adminDetails;
// unordered_map<string, User> userDetails;

//====================Unpack for admin object===========================//
void unpackAdminData(string data)
{
    string username,password;
    int charIndex=0;

    //Username
    while(data[charIndex]!='|')
        username += data[charIndex++];

    charIndex++;

    //password
    while(data[charIndex]!='$')
        password += data[charIndex++];

   

    //Creates a (Username,password) pair
    adminDetails[username] = password;

}
//======================================================================//



//====================Creates a file if not Exits=======================//
void create(string filename){
   fstream fileobj;
   fileobj.open(filename,ios::in|ios::out|ios::app);
   fileobj.close();
}
//====================================================================//

//============================Read from File from specified postition line by line=========================//
void readFromAdminFile(string filename,int pos=ios::beg){
    create(filename);
    string data;
    ifstream file(filename);
    if(file.is_open())
    {
        file.seekg(pos);
        while(file.good())
        {
           getline(file,data);
           unpackAdminData(data);
        }
    }
    file.close();
}
//====================================================================//


//====================Unpack for User object===========================//
void unpackUserData(string data)
{
    string username,password,phoneNumber;
    int charIndex=0;
    User user;
    if(data.length()>0)
    {
        //Username
        while(data[charIndex]!='|')
            username += data[charIndex++];

        charIndex++;

        //password
        while(data[charIndex]!='|')
            password += data[charIndex++];

        
        charIndex++;

        //phoneNumber
        while(data[charIndex]!='$')
            phoneNumber += data[charIndex++];

        
        user.username = username;
        user.password = password;
        user.phoneNumber = phoneNumber;

        
        //Creates a (Username,User) pair
        userDetails[username] = user;
    }

}
//======================================================================//
//============================Read from File from specified postition line by line=========================//
void readFromUserFile(string filename,int pos=ios::beg){
    create(filename);
    string data;
    ifstream file(filename);
    if(file.is_open())
    {
        file.seekg(pos);
        while(file.good())
        {
           getline(file,data);
           unpackUserData(data);
        }
    }
    file.close();
}
//====================================================================//

string packUserData(string username,string password,string phoneNumber)
{
    string unionData;
    unionData=toUpperCase(username)+"|"+password+"|"+phoneNumber+"$";
    return unionData;
     
}

//=========================Function to Write to User file=============================//
bool writeToUserFile(string filename,string username,string password,string phoneNumber)
{
    create(filename);
    readFromUserFile(filename);
    if(userDetails.find(username)==userDetails.end())
    {
        string data;
        ofstream file(filename,ios::app);
        if(file.is_open())
        {
            file.seekp(ios::end);
            data=packUserData(username,password,phoneNumber);
            file<<"\n"+data;

        }
        file.close();
        return true;
      
    }
   return false;
      
}
//==================================================================================//



























//=================================Test Function===============================//
// void test()
// {

// }