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
#include "Score.h"

using namespace std;

void readFile(string , HashTable<string, HashRecord> &, int numberOfRecords);

int main() {
    
    /*  Dear grader, Here is the number of records in the hashmap to be printed out
        When you print out the first 50 records, the frequency will start counting at zero.
        For example if the word dog was in the hashmap once, it will print in the console
        dog, freq: 0
        So dog shows up exactly once in the hashmap, not zero times
     */
    
    int numberOfRecords = 50;
    HashTable<string, HashRecord> table0;
    HashTable<string, HashRecord> table1;
    HashTable<string, HashRecord> table2;
    HashTable<string, HashRecord> table3;
    HashTable<string, HashRecord> table4;
    
    readFile("Game0.txt", table0, numberOfRecords);
    table0.makeEmpty();
    readFile("Game1.txt", table1, numberOfRecords);
    table1.makeEmpty();
    readFile("Game2.txt", table2, numberOfRecords);
    table2.makeEmpty();
    readFile("Game3.txt", table3, numberOfRecords);
    table3.makeEmpty();
    readFile("Game4.txt", table4, numberOfRecords);
    table4.makeEmpty();
    

    
return 0;
}

void readFile(string fileName, HashTable<string ,HashRecord> &table, int records)
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
        //cout << "the information in the file is as follows: " << endl ;
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
            
           // cout << fileWord << endl;
            
            if (table.find(fileWord)) //if the word is there, just update the frequency
            {
                HashRecord * temp = table.find(fileWord);
                temp->ct++;
                table.totalScore +=score(fileWord, temp->ct);
                cout << "Score for " << fileWord << " is " << score(fileWord, temp->ct) << endl;
                cout << "Total Score is " << table.totalScore << endl;
            }
            else
            {
                HashRecord *wordFrequency = new HashRecord(fileWord,0);
                table.insert(fileWord, wordFrequency);
                table.totalScore +=score(fileWord, 0);
                cout << "Score for " << fileWord << " is " << score(fileWord, 0) << endl;
                cout << "Total Score is " << table.totalScore << endl;
            }
            
        }
        //Print out the hashTable
        cout << "\nthe information for the first " << records << " files in the hashmap are: " << endl;
        cout << table.toString(records);
        cout << "Enter 't' to continue" << endl;
        char c;
        cin >> c;
        
        
//        for (int i = 0; i<20; i++) {
//            cout << endl;
//        }
        fin.close() ; // close the file handler once the operations are done
    }
}



