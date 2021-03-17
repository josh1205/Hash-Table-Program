#include <iostream>
#include <cstdlib>
#include <string>
#include <stdio.h>

#include "hashtable.h"

using namespace std;

hash_table::hash_table()
{
    for(int i = 0; i < tableSize; i++)
    {
        HashTable[i] = new item;
        HashTable[i] -> name = "empty";
        HashTable[i] -> drink = "empty";
        HashTable[i] -> next = NULL;
    }
}

void hash_table::addItem(string name, string drink)
{
    int index = Hash(name);
    
    if(HashTable[index] -> name == "empty")
    {
        HashTable[index] -> name = name;
        HashTable[index] -> drink = drink;
    }
    else
    {
        item* Ptr = HashTable[index];
        item* n = new item;
        n -> name = name;
        n -> drink = drink;
        n -> next = NULL;
        while(Ptr -> next != NULL)
        {
            Ptr = Ptr -> next;
        }
        Ptr -> next = n;
    }
}

int hash_table::NumberOfItemInIndex(int index)
{
    int count = 0;
    
    if(HashTable[index] -> name == "empty")
    {
        return count;
    }
    else
    {
        count++;
        item* Ptr = HashTable[index];
        while(Ptr -> next != NULL)
        {
            count++;
            Ptr = Ptr -> next;
        }
    }
    return count;
}

void hash_table::PrintTable()
{
    
    int number;
    for(int i = 0; i < tableSize; i++)
    {
        number = NumberOfItemInIndex(i);
        cout << "----------------------" << endl;
        cout << "index = " << i << endl;
        cout << HashTable[i] -> name << endl;
        cout << HashTable[i] -> drink << endl;
        cout << "# number of items = " << number << endl;
        cout << "----------------------" << endl;
    }
    
    
}

void hash_table::PrintIteminIndex(int index)
{
    item* Ptr = HashTable[index];
    if(Ptr -> name == "empty")
    {
        cout << "index = " << index << " is empty" << endl;
    }
    else
    {
        cout << "index = " << index <<" contains the following items:" << endl;
        while(Ptr != NULL)
        {
            cout << "----------------" << endl;
            cout << Ptr -> name << endl;
            cout << Ptr -> drink << endl;
            cout << "----------------" << endl;
            
            Ptr = Ptr -> next;
        }
    }
}

void hash_table::FindDrink(string name)
{
    int index = Hash(name);
    bool foundName = false;
    string drink;
    
    item* Ptr = HashTable[index];
    while(Ptr != NULL)
    {
        if(Ptr -> name == name)
        {
            foundName = true;
            drink = Ptr -> drink;
        }
        Ptr = Ptr -> next;
    }
    if(foundName == true)
    {
        cout << "Favorite drink = " << drink << endl;
    }
    else
    {
        cout << name << "'s info was not found in the Hash Table" << endl;
    }
}

void hash_table::RemoveItem(string name)
{
    int index = Hash(name);
    
    item* delPtr;
    item* P1;
    item* P2;
    
    //Case 0 - bucket is empty
    if(HashTable[index] -> name == "empty")
    {
        cout << "Item is not in HashTable" << endl;
    }
    //Case 1 - Bucket has only one bucket and it is matching
    else if(HashTable[index] -> name == name && HashTable[index] -> next == NULL)
    {
        HashTable[index] -> name = "empty";
        HashTable[index] -> drink = "empty";
        
        cout << name << " was removed from the HashTable" << endl;
    }
    //Case 2 - match is located in first item but there are more items
    else if(HashTable[index] -> name == name)
    {
        delPtr = HashTable[index];
        HashTable[index] = HashTable[index] -> next;
        delete delPtr;
        
        cout << name << " was removed from the HashTable" << endl;
        
    }
    //Case 3 - bucket contains item but first item is not a match
    else
    {
        P1 = HashTable[index] -> next;
        P2 = HashTable[index];
        while(P1 != NULL && P1 -> name != name)
        {
            P2 = P1;
            P1 = P1 -> next;
        }
        //Case 3.1 - no match
        if(P1 == NULL)
        {
            cout << "Item is not in HashTable" << endl;
        }
        else
        {
            delPtr = P1;
            P1 = P1 -> next;
            P2 -> next = P1;
            delete P1;
            
             cout << name << " was removed from the HashTable" << endl;
        }
        
    }
    //Case 3.2 - match
}

int hash_table::Hash(string key)
{
    int hash = 0;
    int index;
    
    for (int i = 0; i < key.length(); i++)
    {
        hash = (hash + (int)key[i]) * 17;
        //cout << "hash = " << hash << endl;
        
    }
    index = hash % tableSize;
    
    return index;
    
    
    
}
