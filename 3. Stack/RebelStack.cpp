#include <iostream>
#include "RebelStack.hpp"

template <typename T>
RebelStack<T>::RebelStack()
{
    this->TopPlate = nullptr;
}

template <typename T>
RebelStack<T>::RebelStack(T value)
{
    this->TopPlate = new RebelPlate<T>(value);
}

template <typename T>
void RebelStack<T>::push(T value)
{
    if (this->TopPlate != nullptr)
    {
        RebelPlate<T> *NewPlate = new RebelPlate<T>(value);
        NewPlate->nextPlate = this->TopPlate;
        this->TopPlate = NewPlate;
    }
    else
    {
        this->TopPlate = new RebelPlate<T>(value);
    }
}

template <typename T>
void RebelStack<T>::pop()
{
    if (this->TopPlate->nextPlate != nullptr)
    {
        this->TopPlate = this->TopPlate->nextPlate;
    }
    else
    {
    }
}

template <typename T>
void RebelStack<T>::print()
{
    RebelPlate<T> *CurrentPlate = this->TopPlate;
    RebelStack<T> reverseStack;
    while (CurrentPlate->nextPlate != nullptr)
    {
        reverseStack.push(CurrentPlate->value);
        CurrentPlate = CurrentPlate->nextPlate;
    }
    reverseStack.push(CurrentPlate->value);

    CurrentPlate = reverseStack.TopPlate;
    std::cout << "[Bottom] ->";
    while (CurrentPlate->nextPlate != nullptr)
    {
        std::cout << "[" << CurrentPlate->value << "] ->";
        CurrentPlate = CurrentPlate->nextPlate;
    }
    std::cout << "[" << CurrentPlate->value << "]";
    std::cout << std::endl;
}

int main()
{
    RebelStack<int> myStack;
    myStack.push(34);
    myStack.print();
    myStack.push(35);
    myStack.print();
    myStack.push(36);
    myStack.print();
    myStack.push(37);
    myStack.print();
    myStack.pop();
    myStack.print();

    return 0;
}