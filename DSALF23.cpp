#include <iostream>
#include <fstream>
using namespace std;

class student {
public:
    char name[50], div, address[50];
    int roll;
};
class studentDatabase {
    string fileName = "student_data.dat";
public:
    studentDatabase() {
        fstream fileObj(fileName);
        if (fileObj.fail()) {
            fileObj.open(fileName, ios::out);
            cout << "File opened successsfuly" << endl;
        }
        else {
            cout << "File already exists" << endl;
        }
    }
    void addStudent() {
        student s;
        cout << "Enter Roll no.: ";
        cin >> s.roll;
        cout << "Enter name: ";
        cin.ignore();
        cin.getline(s.name, 50);
        cout << "Enter division: ";
        cin >> s.div;
        cout << "Enter address: ";
        cin.ignore();
        cin.getline(s.address, 50);
        ofstream file(fileName, ios::out | ios::binary | ios::app);
        file.write((char*)&s, sizeof(student)) << flush;
        if (file.fail()) {
            cout << "Failed to add student record";
        }
        else {
            cout << "Student record added successfully";
        }
        file.close();
    }
    void searchStudent() {
        student s;
        int roll;
        bool status = false;
        cout << "Enter roll no. to find: ";
        cin >> roll;
        ifstream file(fileName, ios::in | ios::binary);
        while (file.read((char*)&s, sizeof(student))) {
            if (s.roll == roll) {
                status = true;
                break;
            }
        }
        file.close();
        if (status == true) {
            cout << "--- RECORD FOUND ---" << endl;
            cout << "Roll number: " << s.roll << endl;
            cout << "Name: " << s.name << endl;
            cout << "Division: " << s.div << endl;
            cout << "Address: " << s.address << endl;
            cout << "--- END OF RECORD ---" << endl;
        }
        else {
            cout << "Record not found";
        }
    }
    void displayAll() {
        student s;
        int count = 0;
        ifstream file(fileName, ios::in | ios::binary);
        while (file.read((char*)&s, sizeof(student))) {
            count++;
            cout << count << ") ";
            cout << s.roll << "|";
            cout << s.name << "|";
            cout << s.div << "|";
            cout << s.address << endl;
        }
        if (count == 0) {
            cout << "No records found." << endl;
        }
        file.close();
    }
};
int main() {
    studentDatabase obj;
    obj.addStudent();
    obj.searchStudent();
    obj.displayAll();
    return 0;
}