//
//  HashRecord.cpp
//  CS2420 Assignment 4
//
//  Created by Camron Blake Martinez on 10/26/15.
//  Copyright © 2015 Camron Blake Martinez. All rights reserved.
//

#include "HashRecord.h"

HashRecord::HashRecord()
{
    word = " ";
    ct  = 0;
}

HashRecord::HashRecord(string iWord, int iCt)
{
    word = iWord;
    ct = iCt;
}

HashRecord::HashRecord(const HashRecord &rhs)//copy Constructor
{
    this->word = rhs.word;
    this->ct = rhs.ct;
    
}



string HashRecord::toString() const
{
    stringstream ss;
    ss << word << " " << ct << endl;
    return ss.str();
}
