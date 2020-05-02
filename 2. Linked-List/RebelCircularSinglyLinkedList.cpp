#include <iostream>
#include "RebelCircularSinglyLinkedList.hpp"

RebelCircularSinglyLinkedList::RebelCircularSinglyLinkedList()
{
    this->Head = nullptr;
}

RebelCircularSinglyLinkedList::RebelCircularSinglyLinkedList(int value)
{
    this->Head = new RebelNode(value);
    this->Head->nextNode = this->Head;
}

int RebelCircularSinglyLinkedList::Lookup(int index)
{
    RebelNode *CurrentNode = this->Head;
    for (int i = 0; i < index; i++)
    {
        CurrentNode = CurrentNode->nextNode;
    }
    return CurrentNode->value;
}

void RebelCircularSinglyLinkedList::Append(int value)
{

    if (this->Head != nullptr)
    {
        RebelNode *NewNode = new RebelNode(value);
        NewNode->nextNode = this->Head->nextNode;
        this->Head->nextNode = NewNode;
    }
    else
    {
        this->Head = new RebelNode(value);
        this->Head->nextNode = this->Head;
    }
}

void RebelCircularSinglyLinkedList::Prepend(int value)
{
    if (this->Head != nullptr)
    {
        RebelNode *CurrentNode = this->Head;
        while (CurrentNode->nextNode != Head)
        {
            CurrentNode = CurrentNode->nextNode;
        }
        RebelNode *NewNode = new RebelNode(value);
        CurrentNode->nextNode = NewNode;
        NewNode->nextNode = Head;
        this->Head = NewNode;
    }
    else
    {
        this->Head = new RebelNode(value);
        this->Head->nextNode = this->Head;
    }
}

void RebelCircularSinglyLinkedList::Insert(int value, int index)
{

    RebelNode *NewNode = new RebelNode(value);
    RebelNode *CurrentNode = this->Head;

    for (int i = 0; i < index - 1; i++)
    {
        CurrentNode = CurrentNode->nextNode;
    }

    NewNode->nextNode = CurrentNode->nextNode;
    CurrentNode->nextNode = NewNode;
}

void RebelCircularSinglyLinkedList::Delete(int element)
{
    RebelNode *CurrentNode = this->Head;
    RebelNode *PreviousNode;

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

void RebelCircularSinglyLinkedList::pop(int index)
{
    RebelNode *CurrentNode = this->Head;

    for (int i = 0; i < index - 1; i++)
    {
        CurrentNode = CurrentNode->nextNode;
    }

    CurrentNode->nextNode = CurrentNode->nextNode->nextNode;
}

int RebelCircularSinglyLinkedList::count(int element)
{
    RebelNode *CurrentNode = this->Head;
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

int RebelCircularSinglyLinkedList::index(int element)
{
    RebelNode *CurrentNode = this->Head;
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

void RebelCircularSinglyLinkedList::print()
{
    RebelNode *CurrentNode = this->Head;
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
    RebelCircularSinglyLinkedList myList;
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