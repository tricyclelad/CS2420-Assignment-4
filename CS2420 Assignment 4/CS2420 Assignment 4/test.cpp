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

void readFile(string , HashTable<string, HashRecord> &);
int score(string , int);
int sumOfLetters(string);
int lengthValue(string);
int bonus(int);
const int LETTER_VALUES[26]= {1,3,3,2,1,4,2,4,1,8,5,1,3,1,1,3,10,1,1,1,1,4,4,8,4,10};

int main() {

    string phrase = "abcdefghijklmnopqrstuvwxyz";
    for (int i = 0; i < 21; i++) {
        cout << score(phrase, i)<< endl;

    }
    
//    HashTable<string, HashRecord> tableInMain;
////    cout << "Here is what the empty hashTable looks like: " << tableInMain.toString() << endl;
//    readFile("Game0.txt", tableInMain);
////    HashRecord *temp = tableInMain.find("zion");
//    tableInMain.makeEmpty();
//    readFile("Game1.txt", tableInMain);
//    tableInMain.makeEmpty();
//    readFile("Game2.txt", tableInMain);
//    tableInMain.makeEmpty();
//    readFile("Game3.txt", tableInMain);
//    tableInMain.makeEmpty();
//    readFile("Game4.txt", tableInMain);
//    tableInMain.makeEmpty();
//    

    
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
            
//            cout << fileWord << endl;
//            
//            if (table.find(fileWord))
//            {
//                HashRecord * temp = table.find(fileWord);
//                temp->ct++;
//            }
//            else
//            {
//                HashRecord *wordFrequency = new HashRecord(fileWord,1);
//                table.insert(fileWord, wordFrequency);
//            }
           
            
           /*
            Pair *wordFrequency = new Pair(word,0);
            hashTab.insert(word, wordFreqency)
            */
        }
        cout << table.toString(1000);
        
        char c;
        cin >> c;
        
        
//        for (int i = 0; i<20; i++) {
//            cout << endl;
//        }
        fin.close() ; // close the file handler once the operations are done
    }
}

int score(string word, int freq)
{
    int wordScore = (sumOfLetters(word))*(lengthValue(word))*bonus(freq);
    return wordScore;
}

int sumOfLetters(string word)
{
    int sum = 0;
    int index = 0;
    char letter = ' ';
    
    for(int i = 0; i < word.size(); i++)
    {
        letter = word[i];
        index = letter - 'a';
        sum += LETTER_VALUES[index];
    }
    return sum;
}
int lengthValue(string word)
{
    unsigned long lenVal = word.size();
    int ans = int(lenVal);
    if (lenVal <= 2)
    {
        return 0;
    }
    if (lenVal >= 8)
    {
        return 6;
    }
    return ans-2;
}
int bonus(int freq)
{
    if (freq == 0) {
        return 5;
    } else if(freq >=1 && freq<=5) {
        return 4;
    } else if(freq >=6 && freq<=10) {
        return 3;
    } else if(freq >=11 && freq<=15) {
        return 2;
    }
    
    return 1;
    
}


