//
//  main.cpp
//  CS2420 Assignment 4
//
//  Created by Camron Blake Martinez on 10/24/15.
//  Copyright © 2015 Camron Blake Martinez. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "HashTable.h"
#include "HashRecord.h"
using namespace std;

void readFile(string fileName, HashTable<string, HashRecord> &table);

int main() {
    HashTable<string, HashRecord> tableInMain;
    cout << "Here is what the empty hashTable looks like: " << tableInMain.toString() << endl;
    readFile("Game0.txt", tableInMain);
    
//    readFile("Game1.txt");
//    readFile("Game2.txt");
//    readFile("Game3.txt");
//    readFile("Game4.txt");
    
    
    
return 0;
}

void readFile(string fileName, HashTable<string ,HashRecord> &table )
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
        cout << "the information in the file is as follows: " << endl ;
        char fileWord[80] ;
        //string fileWord = " ";
        
        /*
         while(!fin.eof())
         {
         fin.getline(info, 80);
         cout << info << endl ;
         }
         */
        
        while (fin.getline(fileWord, 80))
        {
            cout << fileWord << endl;
            
            HashRecord *wordFrequency = new HashRecord(fileWord,0);
            
            table.insert(fileWord, wordFrequency);
            
           /*
            Pair *wordFrequency = new Pair(word,0);
            hashTab.insert(word, wordFreqency)
            */
        }
        cout << table.toString();
        
        char c;
        cin >> c;
        
        
//        for (int i = 0; i<20; i++) {
//            cout << endl;
//        }
        fin.close() ; // close the file handler once the operations are done
    }
}
