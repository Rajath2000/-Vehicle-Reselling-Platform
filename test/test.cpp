#include<fstream>
#include <unordered_map>

#include<iostream>
using namespace std;

//=====================Which stores in a Hash Table(username,password) pair ========================//
unordered_map<string, string> adminDetails;

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








int main()
{
    string username="RAJATHMR";

    readFromAdminFile("admin.txt");
    
    if (adminDetails.find(username) == adminDetails.end())
        cout << username << " not found\n";
    else
        cout << "Found " << username << endl;
    return 0;
}














//=================================Test Function===============================//
// void test()
// {

// }