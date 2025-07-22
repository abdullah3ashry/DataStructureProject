#pragma once
#include "1-Stacks/ArrayStack.h"
#include <iostream>

class ETank;

class ET_stack
{
private:
	ArrayStack<ETank*> Stack;
    int count;
public:
    ET_stack();

    ~ET_stack();

    bool isEmpty() const;

    void push(ETank* tank);

    ETank* pop();

    ETank* peek() const;
    void print();


    ET_stack& operator=(const ET_stack& other);
    bool operator==(ET_stack& other) const;

    int getCount();
};

