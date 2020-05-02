#include <iostream>
#include "RebelCircularDoublyLinkedList.hpp"

RebelCircularDoublyLinkedList::RebelCircularDoublyLinkedList()
{
    this->Head = nullptr;
}

RebelCircularDoublyLinkedList::RebelCircularDoublyLinkedList(int value)
{
    this->Head = new RebelNode(value);
    this->Head->nextNode = this->Head;
    this->Head->previousNode = this->Head;
}

int RebelCircularDoublyLinkedList::Lookup(int index)
{
    RebelNode *CurrentNode = this->Head;
    for (int i = 0; i < index; i++)
    {
        CurrentNode = CurrentNode->nextNode;
    }
    return CurrentNode->value;
}

void RebelCircularDoublyLinkedList::Append(int value)
{

    if (this->Head != nullptr)
    {
        RebelNode *NewNode = new RebelNode(value);

        NewNode->nextNode = this->Head->nextNode;
        NewNode->previousNode = this->Head;
        this->Head->nextNode->previousNode = NewNode;
        this->Head->nextNode = NewNode;
    }
    else
    {
        this->Head = new RebelNode(value);
        this->Head->nextNode = this->Head;
        this->Head->previousNode = this->Head;
    }
}

void RebelCircularDoublyLinkedList::Prepend(int value)
{
    if (this->Head != nullptr)
    {
        RebelNode *NewNode = new RebelNode(value);

        NewNode->nextNode = this->Head;
        NewNode->previousNode = this->Head->previousNode;
        this->Head->previousNode->nextNode = NewNode;
        this->Head->previousNode = NewNode;
        this->Head = NewNode;
    }
    else
    {
        this->Head = new RebelNode(value);
        this->Head->nextNode = this->Head;
        this->Head->previousNode = this->Head;
    }
}

void RebelCircularDoublyLinkedList::Insert(int value, int index)
{

    RebelNode *NewNode = new RebelNode(value);
    RebelNode *CurrentNode = this->Head;

    for (int i = 0; i < index - 1; i++)
    {
        CurrentNode = CurrentNode->nextNode;
    }

    NewNode->nextNode = CurrentNode->nextNode;
    NewNode->previousNode = CurrentNode;

    CurrentNode->nextNode->previousNode = NewNode;
    CurrentNode->nextNode = NewNode;
}

void RebelCircularDoublyLinkedList::Delete(int element)
{
    RebelNode *CurrentNode = this->Head;

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

void RebelCircularDoublyLinkedList::pop(int index)
{
    RebelNode *CurrentNode = this->Head;
    for (int i = 0; i < index - 1; i++)
    {
        CurrentNode = CurrentNode->nextNode;
    }
    CurrentNode->nextNode = CurrentNode->nextNode->nextNode;
    CurrentNode->nextNode->nextNode->previousNode = CurrentNode;
}

int RebelCircularDoublyLinkedList::count(int element)
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

int RebelCircularDoublyLinkedList::index(int element)
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

void RebelCircularDoublyLinkedList::print()
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
        std::cout << "[" << CurrentNode->value << "] <-> ";
        CurrentNode = CurrentNode->nextNode;
    }
    std::cout << "[HEAD]" << std::endl;
}

int main()
{
    RebelCircularDoublyLinkedList myList;
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