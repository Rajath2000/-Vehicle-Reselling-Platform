
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

class Student {
    public:
    string usn;
    string name;
    string branch;
    string semester;
    string buffer;

    int count;
    int rrn_list[100];
    void read_data();
    void pack();
    void write_to_file();
    void create_rrn();
    void search_by_rrn(int);
};
void Student::read_data() {
    cout << "Usn:";
    cin >> usn;
    cout << "Name:";
    cin >> name;
    cout << "Branch:";
    cin >> branch;
    cout << "Semester:";
    cin >> semester;
}
void Student::pack() {
    buffer.erase();
    buffer = usn + '|' + name + '|' + branch + '|' + semester + '$' + '\n';
}
void Student::write_to_file() {
    fstream file;
    file.open("4.txt", ios::out | ios::app);
    file << buffer;
    file.close();
}

void Student::create_rrn() {
    ifstream file;
    int pos;
    count = -1;
    file.open("4.txt", ios:: in );
    while (!file.eof()) {
        pos = file.tellg();
        buffer.erase();
        getline(file, buffer);
        rrn_list[++count] = pos;
    }
    file.close();
}

void Student::search_by_rrn(int rrn) {
    int pos;
    fstream file;
    if (rrn >= count)
        cout << "\nNot Found!";
    else {
        buffer.erase();
        pos = rrn_list[rrn];
        file.open("4.txt");
        file.seekg(pos, ios::beg);
        getline(file, buffer);
        cout << "\n" << buffer << "\n";
        file.close();
    }
}

int main() {
    int choice, rrn, count, i;
    Student s1;
    s1.create_rrn();
    while (1) {
        cout << "\nMain Menu\n1.Add  2.Search   3.Exit\nEnter T0he Choice:";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "\nHow Many Records To Be Inserted :\n";
            cin >> count;
            for (i = 0; i < count; i++) {
                cout << "Data\n";
                s1.read_data();
                s1.pack();
                s1.write_to_file();
            }
            s1.create_rrn();
            break;
        case 2:
            cout << "Enter The RRN :";
            cin >> rrn;
            s1.search_by_rrn(rrn);
            break;

        case 3:
            return 0;

        default:
            cout << "\nWrong Choice!";
            break;
        }
    }
}
