#include "HU_Stack.h"
#include "HU.h"

HU_Stack::HU_Stack()
{
    count = 0;
}

HU_Stack::~HU_Stack()
{
    // Deallocate memory of all ETank objects in the stack
    HU* temp;
    while (!Stack.isEmpty()) {
        Stack.pop(temp);
        delete temp;
    }
    count = 0;
}

bool HU_Stack::isEmpty() const
{
    return Stack.isEmpty();
}

void HU_Stack::push(HU* hu)
{
    Stack.push(hu);
    count++;
}

HU* HU_Stack::pop()
{
    HU* hu = nullptr;
    Stack.pop(hu);
    count--;
    return hu;

}

HU* HU_Stack::peek() const
{
    HU* hu = nullptr;
    Stack.peek(hu);
    return hu;
}

void HU_Stack::print()
{
    HU* hu;
    HU_Stack temp;

    std::cout << "HU  " << count << "    " << "[ ";
    while (!Stack.isEmpty())
    {
        Stack.pop(hu);
        std::cout << hu->getID() << ", ";
        temp.push(hu);
    }
    while (!temp.isEmpty())
    {
        Stack.push(temp.pop());
        Stack.pop(hu);
        temp.push(hu);
        Stack.push(temp.pop());
    }
    std::cout << "]" << "\n";
}

HU_Stack& HU_Stack::operator=(const HU_Stack& other)
{
    if (this != &other) {
        // Clear current stack
        HU* temp;
        while (!Stack.isEmpty()) {
            Stack.pop(temp);
            delete temp;
        }

        // Copy elements from other stack
        ArrayStack<HU*> tempStack = other.Stack; // Assuming ArrayStack supports copy constructor
        while (!tempStack.isEmpty()) {
            tempStack.pop(temp);
            Stack.push(new HU(*temp));
        }
    }
    return *this;
}

bool HU_Stack::operator==(HU_Stack& other) const
{
    ArrayStack<HU*> tempStack = other.Stack;
    while (!Stack.isEmpty() && !tempStack.isEmpty()) {
        HU* hu1, * hu2;
        Stack.peek(hu1);
        tempStack.peek(hu2);
        if (!(*hu1 == *hu2))
            return false;
        other.Stack.pop(hu1);
        tempStack.pop(hu2);
    }
    // If both stacks are empty or if both became empty together, they are equal
    return Stack.isEmpty() && tempStack.isEmpty();
}
