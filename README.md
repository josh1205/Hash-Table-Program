# Hash Table with Separate Chaining

A C++ implementation of a hash table using separate chaining for collision resolution, demonstrating key hashing algorithms and linked list collision management.

## Overview

This project implements a hash table that stores name-drink pairs using a custom hash function. Collisions are handled through separate chaining with linked lists, allowing multiple items to exist at the same index.

## Features

- **Custom Hash Function**: String-based hashing using ASCII values and multiplication
- **Collision Handling**: Separate chaining with linked lists
- **CRUD Operations**: Add, search, remove items from the table
- **Statistics**: Track number of items per index
- **Visualization**: Print entire table or specific buckets

## File Structure

```
├── hashtable.h       # Header with class declaration
├── hashtable.cpp     # Implementation of hash table methods
└── main.cpp          # Test driver program
```

## Class Architecture

### Item Structure
```cpp
struct item {
    string name;
    string drink;
    item* next;  // For chaining
};
```

### Hash Table Methods

**Core Operations**
- `hash_table()` - Initialize empty table
- `void addItem(string name, string drink)` - Insert key-value pair
- `void RemoveItem(string name)` - Delete item by name
- `void FindDrink(string name)` - Search for item
- `int Hash(string key)` - Hash function

**Utility Functions**
- `void PrintTable()` - Display entire table
- `void PrintIteminIndex(int index)` - Show items in specific bucket
- `int NumberOfItemInIndex(int index)` - Count items at index

## Hash Function

**Algorithm**:
```cpp
hash = 0
for each character in key:
    hash = (hash + ASCII_value) * 17
index = hash % tableSize
```

Uses multiplication by prime (17) to distribute keys across table.

## Collision Resolution

**Separate Chaining**: Each bucket is a linked list
- Empty buckets marked with "empty" sentinel values
- New collisions appended to end of chain
- Maintains O(1) average insertion

## Remove Operation Cases

Handles four scenarios:
1. **Empty bucket** - Item not found
2. **Single item match** - Mark bucket as empty
3. **First item match with chain** - Update head pointer
4. **Middle/end of chain** - Traverse and remove

## Technical Skills

- **Hash Functions**: String-based hashing algorithms
- **Collision Resolution**: Separate chaining implementation
- **Linked Lists**: Chaining within array buckets
- **Search Algorithms**: Key-based lookup in chains
- **Memory Management**: Dynamic node allocation

## Compilation & Usage

```bash
g++ -std=c++11 main.cpp hashtable.cpp -o hashtable
./hashtable
```

## Configuration

```cpp
static const int tableSize = 4;  // Adjustable table size
```

## Performance

- **Average Insert**: O(1)
- **Average Search**: O(1 + α) where α = load factor
- **Worst Case**: O(n) if all items hash to same index

## Learning Outcomes

- Understanding hash table mechanics and collision handling
- Implementing custom hash functions
- Managing hybrid data structures (array + linked lists)
- Handling multiple edge cases in removal operations
- Trade-offs between different collision resolution strategies

---

*Data Structures coursework project*
