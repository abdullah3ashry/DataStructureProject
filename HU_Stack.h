#pragma once
#include "1-Stacks/ArrayStack.h"
#include <iostream>

class HU;
class HU_Stack
{

  
    private:
        ArrayStack<HU*> Stack;
        int count;
    public:
        HU_Stack();

        ~HU_Stack();

        bool isEmpty() const;

        void push(HU* hu);

        HU* pop();

        HU* peek() const;
        void print();


        HU_Stack& operator=(const HU_Stack& other);
        bool operator==(HU_Stack& other) const;
   
};

