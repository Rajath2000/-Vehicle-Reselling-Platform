#include<fstream>
#include <unordered_map>
using namespace std;

//=====================Which stores in a Hash Table(username,password) pair ========================//
unordered_map<string, string> adminDetails;
unordered_map<string, int> vechileIndexDetails;
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

void unpackVechileIndexData(string data)
{
    string vechilenumber,position;
    int charIndex=0;
    if(data.length()>0 && data[0]!='*')
    {
        while(data[charIndex]!='|')
        vechilenumber += data[charIndex++];

        charIndex++;

        //password
        while(data[charIndex]!='$')
        position += data[charIndex++];

        vechileIndexDetails[vechilenumber]=stoi(position);
    }
}



void intiAdmin()
{
    string filename="VechileIndex.txt";
    string data;
    create(filename);
    ifstream file(filename);
    if(file.is_open())
    {
        file.seekg(ios::beg);
        while(file.good())
        {
           getline(file,data);
           unpackVechileIndexData(data);
        }
    }

    file.close();

}

string packVechileIndexData(string vechilenumber,int position)
{
    string unionData;
    unionData=vechilenumber+"|"+to_string(position)+"$";
    vechileIndexDetails[vechilenumber]=position;
    return unionData;    
}


void updateVechileIndex(string vechilenumber,int postition)
{
    string filename="VechileIndex.txt";
    create(filename);
    string data;
    ofstream file(filename,ios::app);
    if(file.is_open())
    {
        file.seekp(ios::end);
        data=packVechileIndexData(vechilenumber,postition);
        file<<data+"\n";


    }
    file.close();


}

string packVechileListData(VechileRecorder data,int position)
{
    string unionData;
    unionData=data.vechileNumber+"|"+data.carModelName+"|"+to_string(data.modelYear)+"|"+to_string(data.kmsDriven)+"|"+to_string(data.fuelType)+"|"+to_string(data.transmission)+"|"+to_string(data.enginePower)+"|"+to_string(data.registerYear.month)+"|"+to_string(data.registerYear.year)+"|"+to_string(data.insurenceType)+"|"+to_string(data.milage)+"|"+to_string(data.seatingCapacity)+"|"+to_string(data.wheelerType)+"$"+"\n";
    
    updateVechileIndex(data.vechileNumber,position);

    return unionData;
}

bool writeToVechileList(VechileRecorder vechilerecorder,string filename)
{
    create(filename);
    if(vechileIndexDetails.find(vechilerecorder.vechileNumber)==vechileIndexDetails.end())
    {
        string data;
        ofstream file(filename,ios::ate|ios::app);
        if(file.is_open())
        {
            // file.seekp(ios::end);
            data=packVechileListData(vechilerecorder,file.tellp());
            file<<data;

        }
        file.close();
        return true;
    }
    return false;

}

int searchFromVechileIndex(string key)
{
    if(vechileIndexDetails.find(key)==vechileIndexDetails.end())
    {
        return -1;
    }
    else
    {
        return vechileIndexDetails.at(key);
    }
}

VechileRecorder UnpackVechileDataFrom(int position=0)
{
    VechileRecorder vechilerecorder;
    int charIndex=0;
    string data;
    string temp;
    ifstream file("Vechilelist.txt");
    if(file.is_open())
    {
         file.seekg(position);
         getline(file, data);

    if( data.length()>0 && data[0]!='*' )
    {

        //vechile Number
        while(data[charIndex]!='|')
            vechilerecorder.vechileNumber += data[charIndex++];

        charIndex++;

        //carModelName
        while(data[charIndex]!='|')
            vechilerecorder.carModelName += data[charIndex++];

        charIndex++;

        //modelYear
        temp.erase();
        while(data[charIndex]!='|')
            temp += data[charIndex++];
        vechilerecorder.modelYear= stoi(temp);

        charIndex++;

        //kmsDriven
        temp.erase();
        while(data[charIndex]!='|')
            temp += data[charIndex++];
            vechilerecorder.kmsDriven = stof(temp);

        charIndex++;

        //fuelType
        temp.erase();
        while(data[charIndex]!='|')
            temp += data[charIndex++];
            vechilerecorder.fuelType =stoi(temp);

        charIndex++;

        //transmission
        temp.erase();
        while(data[charIndex]!='|')
            temp += data[charIndex++];
            vechilerecorder.transmission =stoi(temp);

        charIndex++;

        //enginePower
        temp.erase();
        while(data[charIndex]!='|')
            temp += data[charIndex++];
            vechilerecorder.enginePower =stoi(temp);

        charIndex++;

        //month
        temp.erase();
        while(data[charIndex]!='|')
            temp += data[charIndex++];
            vechilerecorder.registerYear.month =stoi(temp);

        charIndex++;

        //year
        temp.erase();
        while(data[charIndex]!='|')
            temp += data[charIndex++];
            vechilerecorder.registerYear.year = stoi(temp);

        charIndex++;

        //insurenceType
        temp.erase();
        while(data[charIndex]!='|')
            temp += data[charIndex++];
            vechilerecorder.insurenceType =stoi(temp);

        charIndex++;

        //milage
        temp.erase();
        while(data[charIndex]!='|')
            temp += data[charIndex++];
            vechilerecorder.milage =stof(temp);

        charIndex++;

        //seatingCapacity
        temp.erase();
        while(data[charIndex]!='|')
            temp += data[charIndex++];
            vechilerecorder.seatingCapacity =stoi(temp);

        charIndex++;

        //wheelerType
        temp.erase();
        while(data[charIndex]!='$')
            temp += data[charIndex++];
            vechilerecorder.wheelerType =stoi(temp);



    
    file.close();
    }
    }


    return vechilerecorder;

       
}


void deleteRowFromVechileListat(int position,string key)
{
    fstream file("Vechilelist.txt",ios::out|ios::in);
    if(file.is_open())
    {
         file.seekp(position,ios::beg);
         file.put('*');
    }
    if(vechileIndexDetails.find(key)==vechileIndexDetails.end())
    {
        
    }
    else
    {
        vechileIndexDetails.erase(key);
    }
}




















//=================================Test Function===============================//
// void test()
// {

// }