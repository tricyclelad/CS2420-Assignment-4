//
//  HashRecord.h
//  CS2420 Assignment 4
//
//  Created by Camron Blake Martinez on 10/26/15.
//  Copyright © 2015 Camron Blake Martinez. All rights reserved.
//

#ifndef HashRecord_h
#define HashRecord_h

#include <stdio.h>
#include <string>
#include <sstream>

#endif /* HashRecord_h */

using namespace std;

class HashRecord
{
public:
    HashRecord();
    
    HashRecord(string word = " ", int ct = 0);
    
    HashRecord(const HashRecord &rhs);//copy Constructor
    
    string word;
    int ct;
    
    string toString() const;
    
    friend ostream & operator<<(ostream & ss, const HashRecord & rhs)
    {
        ss << rhs.toString();
        return ss;
    }
};