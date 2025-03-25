#pragma once
using namespace std; 
#include <iostream>
#include <cstdlib>
#include <ctime>

class Alien_Monster;

class Monster_Array
{
private:
    Alien_Monster** monsters; // Array of pointers to Alien_Monster objects
    int count; // Current count of monsters in the array

public:
    // Constructor
    Monster_Array();


    // Destructor
    ~Monster_Array();

    // Function to add a new monster to the array
    void addMonster(Alien_Monster* monster);

    // Function to delete a monster from the array by ID
    Alien_Monster* removeMonster();

    // Function to get the current count of monsters in the array
    int getCount() const {
        return count;
    }

    // Function to get a monster from the array by index
    Alien_Monster* getMonster(int index) const;
    void print();
};

