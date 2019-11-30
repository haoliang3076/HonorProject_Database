//
//  main.cpp
//  HonorProject_Database
//
//  Created by Haoliang Zhang on 11/20/19.
//  Copyright © 2019 Haoliang Zhang. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>

using namespace std;
void input();
void serach();
void edit();
void displayAll();

int main() {
   // system("cls");
   // system("title HaoliangZhang Database Program");
   // system("colr of");
    
    cout<<"Please enter choice"<<endl;
    cout<<"1.Input new student"<<endl;
    cout<<"2.Search for an students by ID number"<<endl;
    cout<<"3.Edit and existing student's information"<<endl;
    cout<<"4.Display all Students"<<endl;
    cout<<"5.Exit"<<endl;
    
    int choice;
    cin>> choice;
    
    switch(choice){
        case 1:
            input();
            break;
        case 2:
            serach();
            break;
        case 3:
            edit();
        case 4:
            displayAll();
            break;
    }
}
void input()
{
    //system("cls");
    string fname;
    string lname;
    string fileName;
    string major;
    int id;
    double gpa;
    
    cout<<"Input first name:";
    cin>>fname;
    cout<<"Input last name:";
    cin>>lname;
    cout<<"Input student I.D:";
    cin>>id;
    cout<<"Input student major:";
    cin>>major;
    cout<<"Input student G.P.A:";
    cin>>gpa;
    string id2 = to_string(id);
    id2.append(".txt");
    
    ofstream newstudent(id2);
    newstudent << fname << ' ' << lname << ' '<< id << ' ' << major << ' ' << gpa <<endl;
    newstudent.close();
    ofstream dir("directory.txt", ios::app);
    dir<< fname << ' ' << lname << ' '<< id << ' ' << major << ' ' << gpa <<endl;
    dir.close();
    main();
}
void serach()
{
    //system("cls");
    string fname;
    string lname;
    string fileName;
    string major;
    int id;
    int thrw;
    double gpa;
    cout<<"Enter stuents ID number:";
    cin>> id;
    string id2 = to_string(id);
    id2.append(".txt");
    
    ifstream student(id2);
    while (student>> fname>> lname>> thrw>> major>> gpa){
        int fnameLength = fname.size();
        int lnameLength = lname.size();
        int lengthTotal = fnameLength + lnameLength;
        
        string answer;
        cout<<"Is this the correct students? [y/n]"<<endl;
        cout<<fname<< ' ' <<lname<< ' '<<endl;
        cin>> answer;
        
        if(answer=="y"){
           // system("cls");
            cout<<"Name";
            for(int y= 1; y < lengthTotal; y++){
                cout<< " ";
            }
            cout<<"ID#"<<" ";
            
            cout<<"major"<<" ";
            for (int z = 1; z< 2; z++);
            cout << " ";
        }
        cout<<"G.P.A"<<" ";
       
        for(int x= 1; x < lengthTotal; x++){
            cout<< "-";
        }
        cout<<' '<<endl;
        cout<< fname << ' ' << lname << ' '<< id << ' ' << major << ' ' << gpa <<endl;
    }
        system("pause");
        main();

}
    
void edit()
{
    //system("cls");
    string fname;
    string lname;
    string newfname;
    string newlname;
    string decision;
    string major;
    string newmajor;
    int id;
    int newid;
    int thrw;
    double gpa;
    double newgpa;
    cout<<"Enter the students ID of the student whose data you wish to edit:"<<endl;
    cin>>id;
    string id2= to_string(id);
    id2.append(".txt");
    
    ifstream student(id2);
    
    while(student>> fname>> lname>> thrw>> major>> gpa){
        int fnameLength = fname.size();
        int lnameLength = lname.size();
        int lengthTotal = fnameLength + lnameLength;
    if(decision=="y"){
        system("cls");
        cout<<"Current Information:"<<endl;
        
        system("cls");
            cout<<"Name";
            for(int y= 1; y < lengthTotal; y++){
                cout<< " ";
            }
            cout<<"major";
            for (int z = 1; z< 2; z++);
            cout << " ";
        }
        cout<<"G.P.A";
        cout<<"ID#"<<endl;

        for(int x = 1; x < lengthTotal; x++){
            cout<< "-";
        }
        cout<<' '<<endl;
        cout<< fname << ' ' << lname << ' '<< id << ' ' << major << ' ' << gpa <<endl;
    cout<<"Enter new first name:";
    cin>>newfname;
    cout<<"Enter new last name:";
    cin>>newlname;
    cout<<"Enter new I.D:";
    cin>>newid;
    cout<<"Enter new major:";
    cin>>newmajor;
    cout<<"Enter new G.P.A";
    cin>>newgpa;
    if(decision == "n"){
        main();
}
}
student.close();
ofstream student2(id2);
student2 <<newfname << newlname << newid << newmajor << newgpa <<endl;
system("pause");
student2.close();
}

void displayAll(){
//ystem("cls");
string fname;
string lname;
string major;
double gpa;
int id;

cout<<"Entire Students database"<<endl;
cout<<"------------------------"<<endl;
ifstream dir("directory.txt");
while(dir >> fname >> lname >> major >> id >> gpa){
cout<< fname << ' '<< lname<< ' ' << major <<' '<< gpa << ' ' << id << ' '<<endl;

}
system("pause");
    main();
}
