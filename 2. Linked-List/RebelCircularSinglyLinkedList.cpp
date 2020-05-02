#include <iostream>
#include "RebelCircularSinglyLinkedList.hpp"

template <typename T>
RebelCircularSinglyLinkedList<T>::RebelCircularSinglyLinkedList()
{
    this->Head = nullptr;
}

template <typename T>
RebelCircularSinglyLinkedList<T>::RebelCircularSinglyLinkedList(T value)
{
    this->Head = new RebelNode<T>(value);
    this->Head->nextNode = this->Head;
}

template <typename T>
T RebelCircularSinglyLinkedList<T>::Lookup(int index)
{
    RebelNode<T> *CurrentNode = this->Head;
    for (int i = 0; i < index; i++)
    {
        CurrentNode = CurrentNode->nextNode;
    }
    return CurrentNode->value;
}

template <typename T>
void RebelCircularSinglyLinkedList<T>::Append(T value)
{

    if (this->Head != nullptr)
    {
        RebelNode<T> *NewNode = new RebelNode<T>(value);
        NewNode->nextNode = this->Head->nextNode;
        this->Head->nextNode = NewNode;
    }
    else
    {
        this->Head = new RebelNode<T>(value);
        this->Head->nextNode = this->Head;
    }
}

template <typename T>
void RebelCircularSinglyLinkedList<T>::Prepend(T value)
{
    if (this->Head != nullptr)
    {
        RebelNode<T> *CurrentNode = this->Head;
        while (CurrentNode->nextNode != Head)
        {
            CurrentNode = CurrentNode->nextNode;
        }
        RebelNode<T> *NewNode = new RebelNode<T>(value);
        CurrentNode->nextNode = NewNode;
        NewNode->nextNode = Head;
        this->Head = NewNode;
    }
    else
    {
        this->Head = new RebelNode<T>(value);
        this->Head->nextNode = this->Head;
    }
}

template <typename T>
void RebelCircularSinglyLinkedList<T>::Insert(T value, int index)
{

    RebelNode<T> *NewNode = new RebelNode<T>(value);
    RebelNode<T> *CurrentNode = this->Head;

    for (int i = 0; i < index - 1; i++)
    {
        CurrentNode = CurrentNode->nextNode;
    }

    NewNode->nextNode = CurrentNode->nextNode;
    CurrentNode->nextNode = NewNode;
}

template <typename T>
void RebelCircularSinglyLinkedList<T>::Delete(T element)
{
    RebelNode<T> *CurrentNode = this->Head;
    RebelNode<T> *PreviousNode;

    while (true)
    {
        if (CurrentNode->value == element)
        {
            PreviousNode->nextNode = CurrentNode->nextNode;
            break;
        }
        PreviousNode = CurrentNode;
        CurrentNode = CurrentNode->nextNode;
    }
}

template <typename T>
void RebelCircularSinglyLinkedList<T>::pop(int index)
{
    RebelNode<T> *CurrentNode = this->Head;

    for (int i = 0; i < index - 1; i++)
    {
        CurrentNode = CurrentNode->nextNode;
    }

    CurrentNode->nextNode = CurrentNode->nextNode->nextNode;
}

template <typename T>
int RebelCircularSinglyLinkedList<T>::count(T element)
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
int RebelCircularSinglyLinkedList<T>::index(T element)
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
void RebelCircularSinglyLinkedList<T>::print()
{
    RebelNode<T> *CurrentNode = this->Head;
    int count = 0;

    while (true)
    {
        count++;
        if (CurrentNode->nextNode == Head)
        {
            std::cout << "[" << CurrentNode->value << "] -> ";
            break;
        }
        std::cout << "[" << CurrentNode->value << "] -> ";
        CurrentNode = CurrentNode->nextNode;
    }
    std::cout << "[HEAD]" << std::endl;
}

int main()
{
    RebelCircularSinglyLinkedList<int> myList;
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