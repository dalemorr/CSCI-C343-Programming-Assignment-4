// author Dr.H on 10/25/2019
// compiled with g++ -std=c++1z driver.cpp
// This code read EmployeeRecords from a text file into a Sequence, then output the data.

#include <fstream>
#include<iostream>
#include "../../../Downloads/Sequence.hpp"
#include "EmployeeRecord.h"

using namespace std;

typedef Sequence<EmployeeRecord> EmployeeSequence;

void doInputPersonDataFromFile(EmployeeSequence& personData)
{
   string filename = "Employee.dat";
   ifstream infile(filename);
   bool successful;
   EmployeeRecord r;
   int dataSize;

    if (!infile) {
        cout << "Unable to open file";
        exit(1); // terminate with error
    }
   //input.openFile(filename, File::openForRead, successful);
   if (infile.is_open()) {
       // The first item in the data file is an integer
       // it represents how many records are in the data file.
       infile>>dataSize;
       cout<<"Number of Records :"<< dataSize;
       for (int j = 0; j < dataSize; j++) {
           infile>>r.name;
           infile>>r.address;

           infile>>r.state;
           infile>>r.zip;

           personData.add(r,0);
       } // end for
       infile.close();
        
   } // end if

 } // doInputPersonDataFromFile>
 


int main(int argc, char* argv[])
{

    EmployeeSequence eSequence;

    cout << "Reading EmployeeRecords from file" << endl;
    doInputPersonDataFromFile(eSequence);
    cout << "\nCompleted Reading, File contains following Employee Records" << endl;
    eSequence.outputSequence();
    cout<< endl;

    return 0;
}

