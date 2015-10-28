//
//  Score.h
//  CS2420 Assignment 4
//
//  Created by Camron Blake Martinez on 10/27/15.
//  Copyright © 2015 Camron Blake Martinez. All rights reserved.
//

#ifndef Score_h
#define Score_h
#include <string>
using namespace std;

const int LETTER_VALUES[26]= {1,3,3,2,1,4,2,4,1,8,5,1,3,1,1,3,10,1,1,1,1,4,4,8,4,10};
int score(string , int);
int sumOfLetters(string);
int lengthValue(string);
int bonus(int);

#endif /* Score_h */
