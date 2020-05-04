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
RebelElement<T> *RebelQueue<T>::DeQueue()
{
    RebelElement<T> *Temp = this->FrontPlate;
    this->FrontPlate = this->FrontPlate->previousPlate;
    this->FrontPlate->nextPlate = nullptr;
    return Temp;
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

int main1()
{
    RebelQueue<int> myQueue;
    myQueue.EnQueue(34);
    myQueue.print();

    myQueue.EnQueue(35);
    myQueue.print();

    myQueue.EnQueue(36);
    myQueue.print();

    myQueue.EnQueue(312);
    myQueue.print();

    myQueue.EnQueue(363);
    myQueue.print();

    RebelElement<int> *dequed;

    dequed = myQueue.DeQueue();
    myQueue.print();

    myQueue.DeQueue();
    myQueue.print();

    std::cout << "\n\n"
              << dequed->value;

    return 0;
}