/* 
 * File:   CSV.cpp
 * Author: Asus-pc
 * 
 * Created on May 21, 2017, 10:48 PM
 */

#include "CSV.h"

const char delimiter = ',';
char currentChar;
char pastChar;

int CSV::ct;
CSV::CSV() { ct++; cout << "\nCSV created "<<ct;}

CSV::CSV(string csv)
{
    ct++;cout << "\nCSV created "<<ct;
    
  
    populateKeyValuePair(csv);
}

CSV::CSV(const CSV& orig) {}

CSV::~CSV() {ct--; cout << "\nCSV destroyed "<<ct;}

//void CSV::SetChild(CSV child) { this->child = child; }
//CSV CSV::GetChild() const { return child; }



void CSV::pushToMap(){

        
        
    for(int i = 0; i < attribute.size(); i++){
        maps.insert(std::pair<string,string> (
                                              attribute.at(i),
                                              value.at(i)
                                             )
        );
    }
   
  
}


void CSV::populateKeyValuePair(string text)
{
    bool isKey=true,isPair=false;
    string temporary;
//    cout << "<" << text << ">";
    for(auto i=text.begin() ; i != text.end(); ++i) 
    {
        //cout << "<" << (*i) <<">";
        
       
        
        if((*i) != ',')
        {
            temporary += (*i);
        }
       
        
        
        if ((*i) == ',')
        {
             //cout << "\nSTRING<" << temporary << ">\n";
             value.push_back(temporary);
       
             
            temporary.clear();
        }
    }
    value.push_back(temporary);
    pushToMap();
}

void CSV::SetPair(string value,string temporary) { pair.insert(std::pair<string,string>(value,temporary)); }

void CSV::SetPair(map<string, string>::iterator b,map<string, string>::iterator e) { pair.insert(b,e); }

map<string, string> CSV::GetPair() const { return pair; }

void CSV::display()
{
    for(map<string,string>::iterator i=pair.begin() ; i !=pair.end() ; i++ )
    {
        cout <<endl << "Key: "<< (*i).first << " Value: " << (*i).second;
    }
}

void CSV::SetCSVName(string CSVName) { this->CSVName = CSVName; }

string CSV::GetCSVName() const { return CSVName; }

void CSV::createCSVFile()
{
    ofstream fout("patientOutput.csv",ios::app);
    string csv;

    for(map<string,string>::iterator i=pair.begin() ; i !=pair.end() ; i++ )
    {
         csv += (*i).second + ",";
         
    }    
       
        
    
    fout <<  csv.substr(0,csv.length()-1) + "\n";
    
    fout.close();
}