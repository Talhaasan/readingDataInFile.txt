//Name : Ibrahim Talha ASAN
//Course:Programming for Engineers,64170019,Fall Semester,2020-2021.
//Purpose:The purpose of this problem is to define the Patient and Doctor structures
// and to read the values from the given data file (Data.txt) to two different files (Hasta.txt and Doctor.txt).
// In addition, to show the values in these files.

#include<iostream>
#include<fstream>
#include <sstream>
using namespace std;

//struct patient
struct patient{
    string name;
    int ID;
    int numberOfDoctors;
};

//struct doctor
struct doctor{
    string name;
    string specialty;
    int officeNumber;
    int age;
};

//show patient data.
void showPatient(patient p[3]){
    cout <<"\nDisplaying Patient Information: "<<endl;
    cout <<endl;
    for(int i=0;i<3;i++){
        cout << "Patient Name: "<<p[i].name<<endl;
        cout << "Patient ID: "<<p[i].ID<<endl;
        cout << "Number of doctors treating the patient: "<<p[i].numberOfDoctors<<endl;
        cout <<endl;
    }
}

//show doctor data.
void showDoctor(doctor p[7]){
    cout <<"\nDisplaying Doctor Information: "<<endl;
    cout <<endl;
    for(int i=0;i<7;i++){
        cout << "Doctor Name: "<<p[i].name<<endl;
        cout << "Doctor's Specialty: "<<p[i].specialty<<endl;
        cout << "Doctor's Office Number: "<<p[i].officeNumber<<endl;
        cout << "Doctor's Age: "<<p[i].age<<endl;
        cout <<endl;
    }
}

//Function that reads doctor information from the file Data.txt and writes reading data from Data.txt to the Doctors.txt file.
 int readDoctor(doctor p[7]){
    ifstream readingText1;
    readingText1.open("C:\\Users\\Talha Asan\\CLionProjects\\hw2_q2\\Data.txt");
    if (! readingText1) {
        cout << "Error, file couldn't be opened" << endl;
        return 1;
    }
    for(int i=0;i<7;i++){
      readingText1 >> p[i].name;
      readingText1>> p[i].specialty;
      readingText1 >> p[i].officeNumber;
      readingText1 >> p[i].age;
    }
    readingText1.close();
    
    ofstream writingText1;

    writingText1.open("C:\\Users\\Talha Asan\\CLionProjects\\hw2_q2\\Doctors.txt");
    writingText1<<"Doctors: \n"<<endl;
    for(int i =0;i<7;i++){
        writingText1 <<"Doctor Name: "<< p[i].name <<endl;
        writingText1<<"Doctor Specialty: "<< p[i].specialty<<endl;
        writingText1<<"Doctor OfficeNumber: "<<p[i].officeNumber<<endl;
        writingText1<<"Doctor Age: "<<p[i].age<<endl;
        writingText1<<endl;
    }
    writingText1.close();
}

//Function that reads patient information from the file Data.txt and writes reading data from Data.txt to the Patient.txt file.
int readPatient(patient p[3]){
    ifstream readingText2;
    string line;
    readingText2.open("C:\\Users\\Talha Asan\\CLionProjects\\hw2_q2\\Data.txt");
    if (! readingText2) {
        cout << "Error, file couldn't be opened" << endl;
        return 1;
    }
    for (int i = 0; i < 3; i++) {
        readingText2 >> p[i].name;
        readingText2 >> p[i].ID;
        readingText2 >> p[i].numberOfDoctors;
    }
    readingText2.close();
    ofstream writingText2;
    writingText2.open("C:\\Users\\Talha Asan\\CLionProjects\\hw2_q2\\Patients.txt");
    writingText2 << "Patients: \n" << endl;
    for (int i = 0; i < 3; i++) {
        writingText2 << "Patient Name: " << p[i].name << endl;
        writingText2 << "Patient ID: " << p[i].ID << endl;
        writingText2 << "Patient's attending doctor count: " << p[i].numberOfDoctors << endl;
        writingText2 << endl;
    }
}

//Function that shows if the two doctors are the same.
void AreDoctorsEqual(doctor p1,doctor p2){
    int equality=0;
    if(p1.officeNumber == p2.officeNumber){
        equality = (p1.name).compare(p2.name);
            if(equality==0) {
                cout << "Doctor's is equal." << endl;
            }
    }
}
        
//Function that controls the treatment sequence of patients.
 void patientCheck(patient p1,patient p2){
    if(p1.ID > p2.ID){
        if(p1.numberOfDoctors>p2.numberOfDoctors){
            cout <<"Patient Name "<<p1.name<<" 's treatment first." <<endl;
        }
        else{
            cout <<"any order treatment "<<endl;
        }
    }
    else if(p2.ID>p1.ID){
        if(p1.numberOfDoctors<p2.numberOfDoctors){
            cout <<"Patient Name "<<p2.name<<" s treatment first." <<endl;
        }
        else{
            cout <<"any order treatment"<<endl;
        }
    }
}

//main function
int main(){
    patient patientData[3];
    doctor doctorData[7];

    readDoctor(doctorData);
    readPatient(patientData);

    showPatient(patientData);
    showDoctor(doctorData);

}