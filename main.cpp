/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Asus-pc
 *
 * Created on May 21, 2017, 9:14 PM
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <map>
#include "CSV.h"
using namespace std;

/*
 * 
 */
string csvtext = 
      "00000000,Alvaro,Booker,B.,0,Rizal,Manila,Metro Manila,1/1/1980,M,O+,50,150,00000001,00000001";

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

void readCSVFile();
void writeCSVFile();

int main() {
    //START: CSV TESTING FUNCS
    readCSVFile();
    //writeCSVFile();
    //END: CSV TESTING FUNCS
    
    
    return 0;
}








// FOR CSV TESTING
void writeCSVFile()
{
    CSV insert;
    map<string,string> CSV;
    CSV.clear();
    string id,fname,lname,mname,unit, street, city, province,gender,bday,bldtype;
    int wt,ht;
    insert.SetCSVName("patient");
    cout << "\nPlease enter patient details."; 
    id = "00000000";//cout << "\nPatient ID: "; 
    cout << "\nPatient Name [firstname middlename lastname]: "; cin >> fname >> mname >> lname;
    cout << "\nPatient address [unit# street city province]: "; cin >> unit >> street >> city >> province;
    cout << "\nPatient gender: "; cin >>gender;
    cout << "\nPatient birthdate [month/day/year]: "; cin >> bday;
    cout << "\nPatient blood type: "; cin >> bldtype;
    cout << "\nPatient weight: "; cin >> wt;
    cout << "\nPatient height: "; cin >> ht;
    
    CSV.insert(std::pair<string,string>("patient ID",id));//should be auto generated
    CSV.insert(std::pair<string,string>("first name",fname));
    CSV.insert(std::pair<string,string>("middle name",mname));
    CSV.insert(std::pair<string,string>("last name",lname));
    CSV.insert(std::pair<string,string>("house number",unit));
    CSV.insert(std::pair<string,string>("street",street));
    CSV.insert(std::pair<string,string>("city",city));
    CSV.insert(std::pair<string,string>("birthday",bday));
    CSV.insert(std::pair<string,string>("gender",gender));
    CSV.insert(std::pair<string,string>("blood type",bldtype));
    CSV.insert(std::pair<string,string>("weight",to_string(wt)));
    CSV.insert(std::pair<string,string>("height",to_string(ht)));
    CSV.insert(std::pair<string,string>("facility id","00000000"));
    CSV.insert(std::pair<string,string>("health worker id","00000000"));
    //cout << "\nPatient facility ID: ";
    //cout << "\nPatient health worker ID: ";
    if(CSV.size() > 0 )
    {
        for(map<string,string>::iterator i= CSV.begin() ; i != CSV.end() ; ++i)
        {
            
            cout << "\n--------\n" << " KEY: " << (*i).first << " VALUE: " << (*i).second;
        }
    }
    insert.SetPair(CSV.begin(),CSV.end());
    insert.display();
    insert.createCSVFile();
}
void readCSVFile()
{
    vector<CSV*> CSVs;
    bool isFirst = true;
    string csv;
    ifstream file("CS.CSV");
    if(file.is_open())
    {    
        while(!file.eof())
        {   
            if(isFirst)
            {
                isFirst = false;
                getline(file,csv);
            }
           
            getline(file,csv);
            //cout << csv;
            if(csv.length()>0) CSVs.push_back(new CSV(csv));
            
        }
        file.close();
    }
    if(CSVs.size() > 0 )
    {
        for(vector<CSV*>::iterator i= CSVs.begin() ; i != CSVs.end() ; ++i)
        {
            (*i)->display();
            cout << "\n--------\n";
        }
    }
    for(vector<CSV*>::iterator i= CSVs.begin() ; i != CSVs.end() ; ++i)
    {
        delete (*i);
    }
}
