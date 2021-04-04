/****************************************************************************
  FileName     [ p2Json.cpp ]
  PackageName  [ p2 ]
  Synopsis     [ Define member functions of class Json and JsonElem ]
  Author       [ Chung-Yang (Ric) Huang ]
  Copyright    [ Copyleft(c) 2018-present DVLab, GIEE, NTU, Taiwan ]
****************************************************************************/
#include <iostream>
#include <string>
#include "p2Json.h"
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

// Implement member functions of class Row and Table here
bool
Json::read(const string& jsonFile)
{  
   fstream file;
   file.open(jsonFile, ios :: in);
   if(file.is_open()){
      parse(file);
      return true; // TODO
   }else{
      return false;
   }
}
int JsonElem::getValue()
   {
      return _value;
   }
string JsonElem::getKey(){
      return _key;
   }
void Json::parse(fstream &file){
   while(file.good()){
      string line;
      string number("-1234567890.");
      getline(file, line, '\n');
      if(line.size() > 1){
         int pos1 = line.find("\"");
         if(pos1 >= 0){
            line.erase(pos1, 1);
            int pos2 = line.find("\"");
            line.erase(pos2, 1);
            string name = line.substr(pos1 , pos2-pos1);
            line.insert(pos1, "\"");
            line.insert(pos2, "\"");
            int first = line.find_first_of(number);
            int last = line.find_last_of(number);
            string str_number = line.substr(first, last-first+1);
            stringstream x(str_number);
            double number;
            x >> number;
            JsonElem member;
            member.setValue(number);
            member.setKey(name);
            _obj.push_back(member);
         }
      }
   }
}
void Json::sum(){
   int size = _obj.size();
   int total = 0;
   if(size == 0){
      cout << "no element found!!" << endl;
   }else{
      for(int i = 0;i < size; i++){
         total += _obj[i].getValue();
      }
      cout << "The summation of the values is: ";
      cout << total;
      cout << "." << endl;
   }
}
void Json::ave(){
   int size = _obj.size();
   int total;
   if(size == 0){
      cout << "no element found!!" << endl;
   }else{
      for(int i = 0;i < size; i++){
         total += _obj[i].getValue();
      }
      double average = total/size;
      cout << "The average of the values is: ";
      cout << fixed << setprecision(1) << average;
      cout << "." << endl;
   }
}
void Json::max(){
   int size = _obj.size();
   int order = 0;
   float Maxnum = 0;
   if(size == 0){
      cout << "no element found!!" << endl;
   }else{
      for(int i = 0; i < size; i++){
         if(_obj[i].getValue() > Maxnum){
            Maxnum = _obj[i].getValue();
            order = i;
         }
      }
      cout << "The maxmum element is: ";
      cout << "{"<<string(" ")<<string(" ")<<_obj[order].getKey()<<" "<<string(":")<<" ";
      cout << _obj[order].getValue();
      cout <<string(" ")<<"}"<<"." << endl;
   }
}
void Json::min(){
   int size = _obj.size();
   int order = 0;
   if(size == 0){
      cout << "no element found!!" << endl;
   }else{
      float minnum = _obj[0].getValue();
      for(int i = 1; i < size; i++){
         if(_obj[i].getValue() < minnum){
            minnum = _obj[i].getValue();
            order = i;
         }
      }
      cout << "The minimum element is: ";
      cout << "{"<<string(" ")<<string(" ")<<_obj[order].getKey()<<" "<<string(":")<<" ";
      cout << _obj[order].getValue();
      cout <<string(" ")<<"}"<<"." << endl;
   }
}
void Json::print(){
   int size = _obj.size();
   int i = 0;
   if(size == 0){
      cout << "{" << endl << "}" << endl;
   }else{
      cout << "{" << endl;
      while(i < size){
         if (i == size-1 ){
            cout << " "<<" " <<"\""<<_obj[i].getKey()<<"\""<<" "<<":"<<" "<<_obj[i].getValue()<< endl << "}"<<endl;
         }else{
            cout << " "<<" " <<"\""<<_obj[i].getKey()<<"\""<<" "<<":"<<" "<<_obj[i].getValue()<<"," << endl;
         }
         i++;
      }
   }
}
int Json::exit(){
   return 0;
}
void Json::add(string s1, string s2){
   stringstream x(s2);
   int number;
   x >> number;
   JsonElem member;
   member.setKey(s1);
   member.setValue(number);
   _obj.push_back(member);
}

void JsonElem::setValue(int _value)
   {
      this->_value = _value;
   }
void JsonElem::setKey(string _key){
   this->_key = _key;
}
ostream&
operator << (ostream& os, const JsonElem& j)
{
   return (os << "\"" << j._key << "\" : " << j._value);
}