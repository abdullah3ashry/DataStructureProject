#include "Monster_Array.h"
#include "Alien_Monster.h"

Monster_Array::Monster_Array()
{
    count = 0;
    monsters = nullptr;
}

Monster_Array::~Monster_Array()
{
    // Delete all monsters
    for (int i = 0; i < count; ++i) {
        delete monsters[i];
    }
    delete[] monsters;
}

void Monster_Array::addMonster(Alien_Monster* monster)
{
    // Resize the array to accommodate the new monster
    Alien_Monster** newMonsters = new Alien_Monster * [count + 1];
    for (int i = 0; i < count; ++i) {
        newMonsters[i] = monsters[i];
    }
    newMonsters[count++] = monster;
    delete[] monsters;
    monsters = newMonsters;
}

Alien_Monster* Monster_Array::removeMonster()
{
    srand((time(0)));
    int A = rand() % count;
    Alien_Monster* AM;
    AM = monsters[A];
    for (int i = A; i < count - 1; ++i) {
        monsters[i] = monsters[i + 1];
    }
    count--;
    Alien_Monster** temp = new Alien_Monster * [count];
    for (int i = 0; i < count; ++i) {
        temp[i] = monsters[i];
    }
    delete[] monsters;
    monsters = temp;
    return AM;
}

Alien_Monster* Monster_Array::getMonster(int index) const
{
    if (index >= 0 && index < count) {
        return monsters[index];
    }
    else {
        return nullptr; // Invalid index
    }
}

void Monster_Array::print()
{
    cout << "AM  " << count << "    " << "[ ";
    for (int i = 0; i < count; i++)
    {
        cout << monsters[i]->getID() << ", ";
    }
    cout << "]" << "\n";
    cout << endl << endl;
}
