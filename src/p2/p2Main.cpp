/****************************************************************************
  FileName     [ p2Main.cpp ]
  PackageName  [ p2 ]
  Synopsis     [ Define main() function ]
  Author       [ Chung-Yang (Ric) Huang ]
  Copyright    [ Copyleft(c) 2016-present DVLab, GIEE, NTU, Taiwan ]
****************************************************************************/
#include <iostream>
#include <string>
#include "p2Json.h"
#include <fstream>
#include <iomanip>

using namespace std;

int main()
{
   Json json;

   // Read in the csv file. Do NOT change this part of code.
   string jsonFile ;
   cout << "Please enter the file name: ";
    cin >> jsonFile;
   if (json.read(jsonFile))
      cout << "File \"" << jsonFile << "\" was read in successfully." << endl;
      
   else {
      cerr << "Failed to read in file \"" << jsonFile << "\"!" << endl;
      exit(-1); // jsonFile does not exist.
   }
   
   // TODO read and execute commands
   // cout << "Enter command: ";
   string command;
   string s1, s2, addcom("ADD");
   string com = addcom + string(" ") + s1 + string(" ") + s2;
   while (true) {
      // cout << "Enter command: ";
      cout << "Enter command: " ;
      cin >> command;
      if(command == "PRINT"){
         json.print();
      }else if(command == "SUM"){
         json.sum();
      }else if(command == "AVE"){
         json.ave();
      }else if(command == "MAX"){
         json.max();
      }else if(command == "MIN"){
         json.min();
      }else if(command == "EXIT"){
         json.exit();
         break;
      }else{
         if(command == addcom){
            cin >> s1;
            cin >> s2;
            json.add(s1, s2);
         }
      }
   }
   return 0;
}
