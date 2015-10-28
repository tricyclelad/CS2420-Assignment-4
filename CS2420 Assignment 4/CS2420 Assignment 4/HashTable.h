//
//  HashTable.hpp
//  CS2420 Assignment 4
//
//  Created by Camron Blake Martinez on 10/24/15.
//  Copyright © 2015 Camron Blake Martinez. All rights reserved.
//

#ifndef QUADRATIC_PROBING_H
#define QUADRATIC_PROBING_H
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <functional>
#include <string>
#include <sstream>
using namespace std;

int nextPrime(int n);
bool isPrime(int n);

enum Status { ACTIVE, EMPTY, DELETED };

// We store two things.  The key itself and the record associated with the key.
// In our case, the HashKey will be the word.  The HashRecord will be a node containing the word (again) and the count.

// Note that you have to supply a toString for the HashRecord or you can't print the hash table.

template <typename HashKey, typename HashRecord>
class HashEntry
{
public:
    HashKey key;
    HashRecord * rec;
    Status info;
    
    HashEntry(HashRecord * hr = NULL, const HashKey & e = HashKey(), Status i = EMPTY)
    : key( e ), rec( hr ), info( i ) { }
    
};


template <typename HashKey, typename HashRecord>
class HashTable
{
public:
    bool remove(const HashKey & x);
    bool isEmpty() { return activeElements == 0; }
    HashRecord * insert(const HashKey x, HashRecord * h);
    HashTable(int size = 977) : hashTable(nextPrime(size))
    {
        makeEmpty();
    };
    HashRecord *find(const HashKey & x) const;
    void makeEmpty();
    string toString(int howMany = 50);
    
private:
    vector<HashEntry<HashKey, HashRecord>> hashTable;
    int activeElements;
    bool isActive(int currentPos) const;
    unsigned int myhash(const HashKey & x) const;
    //size_t myhash(const HashKey & x) const;
    int findPos(const HashKey & x) const;
    void rehash();
};

// Convert the Hash table to a string.  Since the hashtablel is large, HowMany indicates how many entries will be displayed.
template <typename HashKey, typename HashRecord>
string HashTable<HashKey, HashRecord>::toString(int howMany)
{
    int ct = 0;
    stringstream ss;
    ss << "Current size " << hashTable.size() << endl;
    for (int i = 0; i < (int) hashTable.size() && ct < howMany; i++)
        if (hashTable[i].info == ACTIVE){
            ss << hashTable[i].rec->toString();
            ct++;
        }
    return ss.str();
    
}

// return the subscript where x is located in the hash table.
// Quadratic probing is used.  Can you figure out why this implements quadratic probing?


template <typename HashKey, typename HashRecord>
int HashTable<HashKey, HashRecord>::findPos(const HashKey & x) const
{
    int offset = 1;
    int currentPos = myhash(x);
    
    while (hashTable[currentPos].info != EMPTY &&
           hashTable[currentPos].key != x)
    {
        currentPos += offset;  // Compute ith probe
        offset += 2;
        if (currentPos >= (int)hashTable.size())    // Cheaper than  mod
            currentPos -= hashTable.size();
    }
    
    return currentPos;
};

// Remove all elements of the table by setting status to empty.
// Have you seen the range based loop for accessing elements of a vector?
// for (auto &entry:hashTable) says, let a reference variable "entry" iterate through all entries of the hashTable vector
// The "auto" part says to figure out the type of the element automatically (based on what is passed in).
template <typename HashKey, typename HashRecord>
void HashTable<HashKey, HashRecord>::makeEmpty()
{
    activeElements = 0;
    for (auto & entry : hashTable)
        entry.info = EMPTY;
};

// Create a new hashtable which is at least twice as large as the current size.
// Actually, rehashing can make the table smaller (if entries have been removed), but this isn't considered here.
template <typename HashKey, typename HashRecord>
void HashTable<HashKey, HashRecord>::rehash()
{
    vector<HashEntry <HashKey, HashRecord>> oldhashTable = hashTable;
    
    // Create new double-sized, empty table
    hashTable.resize(nextPrime(2 * oldhashTable.size()));
    for (auto & entry : hashTable)
        entry.info = EMPTY;
    
    // Copy table over
    activeElements = 0;
    for (auto & entry : oldhashTable)
        if (entry.info == ACTIVE)
            insert(entry.key, entry.rec);
    
};

// Return true if given entry is active.
template <typename HashKey, typename HashRecord>
bool HashTable<HashKey, HashRecord>::isActive(int currentPos) const
{
    return hashTable[currentPos].info == ACTIVE;
};

// use built=in hash functions to find a location.


template<typename HashKey, typename HashRecord>
unsigned int HashTable<HashKey, HashRecord>::myhash(const HashKey & x) const
{
    unsigned int hash=0;
    for (int i =0; i < x.length(); i++) {
        hash = (hash << 5) ^ x[i] ^ hash;
    }
    return hash % hashTable.size();
};
//template<typename HashKey, typename HashRecord>
//size_t HashTable<HashKey, HashRecord>::myhash(const HashKey & x) const
//{
//    static hash<HashKey> hf;
//    return hf(x) % hashTable.size();
//};

// Use lazy deletion to remove an element
// Return boolean to indicate success of operation
template <typename HashKey, typename HashRecord>
bool HashTable<HashKey, HashRecord>::remove(const HashKey & x)
{
    int currentPos = findPos(x);
    if (!isActive(currentPos))
        return false;
    
    hashTable[currentPos].info = DELETED;
    return true;
};

// Insert item with key x and record pointer h into the hash table.
template<typename HashKey, typename HashRecord>
HashRecord * HashTable<HashKey, HashRecord>::insert(const HashKey x, HashRecord * h)
{
    // Insert x as active
    int currentPos = findPos(x);
    if (isActive(currentPos))
        return NULL;
    
    hashTable[currentPos].key = x;
    hashTable[currentPos].rec = h;
    hashTable[currentPos].info = ACTIVE;
    
    // Rehash; see Section 5.5
    if (++activeElements > (int)(hashTable.size() / 2))
        rehash();
    
    return h;
};

// Return record for item with key x.
template<typename HashKey, typename HashRecord>
HashRecord * HashTable<HashKey, HashRecord>::find(const HashKey & x) const
{
    int pos = findPos(x);
    if (isActive(pos))
        return hashTable[pos].rec;
    return NULL;
};

#endif /* HashTable_hpp */
