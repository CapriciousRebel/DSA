#include <iostream>
#include "RebelQueue.hpp"

template <typename T>
RebelQueue<T>::RebelQueue()
{
    this->FrontPlate = nullptr;
    this->BackPlate = nullptr;
}

template <typename T>
RebelQueue<T>::RebelQueue(T value)
{
    this->FrontPlate = new RebelElement<T>(value);
    this->BackPlate = this->FrontPlate;
    this->FrontPlate->previousPlate = this->BackPlate;
    this->BackPlate->nextPlate = this->FrontPlate;
}

template <typename T>
void RebelQueue<T>::EnQueue(T value)
{
    if (this->FrontPlate != nullptr)
    {
        RebelElement<T> *NewPlate = new RebelElement<T>(value);
        NewPlate->nextPlate = this->BackPlate;
        this->BackPlate->previousPlate = NewPlate;
        this->BackPlate = NewPlate;
    }
    else
    {
        this->FrontPlate = new RebelElement<T>(value);
        this->BackPlate = new RebelElement<T>(value);
        this->FrontPlate->previousPlate = this->BackPlate;
        this->BackPlate->nextPlate = this->FrontPlate;
    }
}

template <typename T>
void RebelQueue<T>::DeQueue()
{
    //std::cout << "{" << this->FrontPlate->previousPlate->value << "}";
    this->FrontPlate = this->FrontPlate->previousPlate;
    this->FrontPlate->nextPlate = nullptr;
}

template <typename T>
void RebelQueue<T>::print()
{
    RebelElement<T> *CurrentPlate = this->BackPlate;
    std::cout << "-> [Back] ->";
    while (CurrentPlate->nextPlate != nullptr)
    {
        std::cout << "[" << CurrentPlate->value << "] <-> ";
        CurrentPlate = CurrentPlate->nextPlate;
    }
    std::cout << "[Front] ->" << std::endl;
}

int main()
{
    RebelQueue<int> myStack;
    myStack.EnQueue(34);
    myStack.print();

    myStack.EnQueue(35);
    myStack.print();

    myStack.EnQueue(36);
    myStack.print();

    myStack.EnQueue(312);
    myStack.print();

    myStack.EnQueue(363);
    myStack.print();

    myStack.DeQueue();
    myStack.print();

    myStack.DeQueue();
    myStack.print();

    return 0;
}