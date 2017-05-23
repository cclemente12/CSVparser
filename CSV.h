/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   XML.h
 * Author: Asus-pc
 *
 * Created on May 21, 2017, 10:48 PM
 */

#ifndef CSV_H
#define CSV_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <map>


using namespace std;

class CSV {
private:
    string CSVName;
    map<string,string> pair;
    static int ct;
  map<string, string> maps;
    
    vector<string> value;
    vector<string> attribute {"patient ID", "last name", "first name", "middle name", "house number",
                              "street", "city", "province", "birthday", "gender", "blood type", 
                              "weight", "height", " facility id", "health worker id"};
    //XML child;
public:
    CSV();
    CSV(string s);
    CSV(const CSV& orig);
    virtual ~CSV();
//    void SetChild(XML child);
//    XML GetChild() const;
    void SetPair(string key,string value);
    void SetPair(map<string, string>::iterator b,map<string, string>::iterator e);
    map<string, string> GetPair() const;
    void populateKeyValuePair(string text);
    string getAttributes(string csv);
    void createCSVFile();
    void display();
    void SetCSVName(string CSVName);
    string GetCSVName() const;
    void pushToMap();
};

#endif /* XML_H */

