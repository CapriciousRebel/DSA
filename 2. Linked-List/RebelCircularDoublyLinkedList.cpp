#include <iostream>
#include "RebelCircularDoublyLinkedList.hpp"

template <typename T>
RebelCircularDoublyLinkedList<T>::RebelCircularDoublyLinkedList()
{
    this->Head = nullptr;
}

template <typename T>
RebelCircularDoublyLinkedList<T>::RebelCircularDoublyLinkedList(T value)
{
    this->Head = new RebelNode<T>(value);
    this->Head->nextNode = this->Head;
    this->Head->previousNode = this->Head;
}

template <typename T>
T RebelCircularDoublyLinkedList<T>::Lookup(int index)
{
    RebelNode<T> *CurrentNode = this->Head;
    for (int i = 0; i < index; i++)
    {
        CurrentNode = CurrentNode->nextNode;
    }
    return CurrentNode->value;
}

template <typename T>
void RebelCircularDoublyLinkedList<T>::Append(T value)
{

    if (this->Head != nullptr)
    {
        RebelNode<T> *NewNode = new RebelNode<T>(value);

        NewNode->nextNode = this->Head->nextNode;
        NewNode->previousNode = this->Head;
        this->Head->nextNode->previousNode = NewNode;
        this->Head->nextNode = NewNode;
    }
    else
    {
        this->Head = new RebelNode<T>(value);
        this->Head->nextNode = this->Head;
        this->Head->previousNode = this->Head;
    }
}

template <typename T>
void RebelCircularDoublyLinkedList<T>::Prepend(T value)
{
    if (this->Head != nullptr)
    {
        RebelNode<T> *NewNode = new RebelNode<T>(value);

        NewNode->nextNode = this->Head;
        NewNode->previousNode = this->Head->previousNode;
        this->Head->previousNode->nextNode = NewNode;
        this->Head->previousNode = NewNode;
        this->Head = NewNode;
    }
    else
    {
        this->Head = new RebelNode<T>(value);
        this->Head->nextNode = this->Head;
        this->Head->previousNode = this->Head;
    }
}

template <typename T>
void RebelCircularDoublyLinkedList<T>::Insert(T value, int index)
{

    RebelNode<T> *NewNode = new RebelNode<T>(value);
    RebelNode<T> *CurrentNode = this->Head;

    for (int i = 0; i < index - 1; i++)
    {
        CurrentNode = CurrentNode->nextNode;
    }

    NewNode->nextNode = CurrentNode->nextNode;
    NewNode->previousNode = CurrentNode;

    CurrentNode->nextNode->previousNode = NewNode;
    CurrentNode->nextNode = NewNode;
}

template <typename T>
void RebelCircularDoublyLinkedList<T>::Delete(T element)
{
    RebelNode<T> *CurrentNode = this->Head;

    while (true)
    {
        if (CurrentNode->value == element)
        {
            CurrentNode->previousNode->nextNode = CurrentNode->nextNode;
            CurrentNode->nextNode->previousNode = CurrentNode->previousNode;
            break;
        }
        CurrentNode = CurrentNode->nextNode;
    }
}

template <typename T>
void RebelCircularDoublyLinkedList<T>::pop(int index)
{
    RebelNode<T> *CurrentNode = this->Head;
    for (int i = 0; i < index - 1; i++)
    {
        CurrentNode = CurrentNode->nextNode;
    }
    CurrentNode->nextNode = CurrentNode->nextNode->nextNode;
    CurrentNode->nextNode->nextNode->previousNode = CurrentNode;
}

template <typename T>
int RebelCircularDoublyLinkedList<T>::count(T element)
{
    RebelNode<T> *CurrentNode = this->Head;
    int i = 0;

    while (CurrentNode->nextNode != Head)
    {
        if (CurrentNode->value == element)
        {
            i++;
        }
        CurrentNode = CurrentNode->nextNode;
    }
    if (CurrentNode->value == element)
    {
        i++;
    }
    return i;
}

template <typename T>
int RebelCircularDoublyLinkedList<T>::index(T element)
{
    RebelNode<T> *CurrentNode = this->Head;
    int i = 0;

    while (true)
    {
        i++;
        if (CurrentNode->value == element)
        {
            return i - 1;
        }
        CurrentNode = CurrentNode->nextNode;
    }
}

template <typename T>
void RebelCircularDoublyLinkedList<T>::print()
{
    RebelNode<T> *CurrentNode = this->Head;
    int count = 0;

    while (true)
    {
        count++;
        if (CurrentNode->nextNode == Head)
        {
            std::cout << "[" << CurrentNode->value << "] <-> ";
            break;
        }
        std::cout << "[" << CurrentNode->value << "] <-> ";
        CurrentNode = CurrentNode->nextNode;
    }
    std::cout << "[HEAD]" << std::endl;
}

int main()
{
    RebelCircularDoublyLinkedList<int> myList;
    myList.Append(1);
    myList.print();

    myList.Append(3);
    myList.print();

    myList.Append(7);
    myList.print();

    myList.Prepend(99);
    myList.print();

    myList.Insert(69, 2);
    myList.print();

    myList.Insert(69, 4);
    myList.print();

    return 0;
}