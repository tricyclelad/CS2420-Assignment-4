//
//  Score.cpp
//  CS2420 Assignment 4
//
//  Created by Camron Blake Martinez on 10/27/15.
//  Copyright © 2015 Camron Blake Martinez. All rights reserved.
//

#include "Score.h"

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
    } else if(freq >15){
        return 1;
    }
    
    return -1;
    
}