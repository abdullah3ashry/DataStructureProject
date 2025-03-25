#include "ET_stack.h"
#include "ET.h"

ET_stack::ET_stack()
{
	count = 0;
}

ET_stack::~ET_stack()
{
    // Deallocate memory of all ETank objects in the stack
    ETank* temp;
    while (!Stack.isEmpty()) {
        Stack.pop(temp);
        delete temp;
    }
    count = 0;
}

bool ET_stack::isEmpty() const
{
    return Stack.isEmpty();
}

void ET_stack::push(ETank* tank)
{
    Stack.push(tank);
    count++;
}

ETank* ET_stack::pop()
{
    ETank* tank = nullptr;
    Stack.pop(tank);
    count--;
    return tank;

}

ETank* ET_stack::peek() const
{
    ETank* tank = nullptr;
    Stack.peek(tank);
    return tank;
}

void ET_stack::print()
{
    ETank* ET;
    ET_stack temp;

    std::cout << "ET  " << count << "    " << "[ ";
    while (!Stack.isEmpty())
    {
        Stack.pop(ET);
        std::cout << ET->getID() << ", ";
        temp.push(ET);
    }
    while (!temp.isEmpty())
    {
        Stack.push(temp.pop());
        Stack.pop(ET);
        temp.push(ET);
        Stack.push(temp.pop());
    }
    std::cout << "]" << "\n";
    cout << endl;

}

ET_stack& ET_stack::operator=(const ET_stack& other)
{
    if (this != &other) {
        // Clear current stack
        ETank* temp;
        while (!Stack.isEmpty()) {
            Stack.pop(temp);
            delete temp;
        }

        // Copy elements from other stack
        ArrayStack<ETank*> tempStack = other.Stack; // Assuming ArrayStack supports copy constructor
        while (!tempStack.isEmpty()) {
            tempStack.pop(temp);
            Stack.push(new ETank(*temp));
        }
    }
    return *this;
}

bool ET_stack::operator==(ET_stack& other) const
{
    ArrayStack<ETank*> tempStack = other.Stack;
    while (!Stack.isEmpty() && !tempStack.isEmpty()) {
        ETank* tank1, * tank2;
        Stack.peek(tank1);
        tempStack.peek(tank2);
        if (!(*tank1 == *tank2))
            return false;
        other.Stack.pop(tank1);
        tempStack.pop(tank2);
    }
    // If both stacks are empty or if both became empty together, they are equal
    return Stack.isEmpty() && tempStack.isEmpty();
}

int ET_stack::getCount()
{
    return count;
}
