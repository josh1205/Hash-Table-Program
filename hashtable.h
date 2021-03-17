using namespace std;

#ifndef hashtable_h
#define hashtable_h

class hash_table
{
public:
    hash_table();
    int Hash(string key);
    void addItem(string name, string drink);
    int NumberOfItemInIndex(int index);
    void PrintTable();
    void PrintIteminIndex(int index);
    void FindDrink(string name);
    void RemoveItem(string name);

private:
    static const int tableSize = 4;
    
    struct item
    {
        string name;
        string drink;
        item* next;
    };
    
    item* HashTable[tableSize];
};



#endif /* hashtable.h */
