//
//  main.cpp
//  CS2420 Assignment 4
//
//  Created by Camron Blake Martinez on 10/24/15.
//  Copyright © 2015 Camron Blake Martinez. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;

void readFile(string fileName);

int main() {
    
    readFile("Game0.txt");
    readFile("Game1.txt");
    readFile("Game2.txt");
    readFile("Game3.txt");
    readFile("Game4.txt");
    
    
return 0;
}

void readFile(string fileName)
{
    ifstream fin;
    
    fin.open(fileName);
    
    
    if (fin.fail())   // callling the member function to verify
    {
        cout << "the file " << fileName << " was not found" << endl ;
        fin.close() ;
    }
    else
    {
        cout << "the file " << fileName << " was found" << endl ;
        cout << "the information in the file as follows: " << endl ;
        char info[80] ;
        
        /*
         while(!fin.eof())
         {
         fin.getline(info, 80);
         cout << info << endl ;
         }
         */
        
        while (fin.getline(info, 80))
        {
            cout << info << endl ;
        }
        char c;
        cin >> c;
        
        for (int i = 0; i<20; i++) {
            cout << endl;
        }
        fin.close() ; // close the file handler once the operations are done
    }
}
