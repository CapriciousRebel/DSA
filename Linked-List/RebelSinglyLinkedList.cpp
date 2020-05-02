#include <iostream>
#include "RebelSinglyLinkedList.hpp"

RebelSinglyLinkedList::RebelSinglyLinkedList()
{
    Head = nullptr;
}

RebelSinglyLinkedList::RebelSinglyLinkedList(int value)
{
    Head = new RebelNode(value);
}

int RebelSinglyLinkedList::Lookup(int index)
{
    RebelNode *CurrentNode = this->Head;
    for (int i = 0; i < index; i++)
    {
        CurrentNode = CurrentNode->nextNode;
    }
    return CurrentNode->value;
}

void RebelSinglyLinkedList::Append(int value)
{
    if (this->Head != nullptr)
    {
        RebelNode *CurrentNode = this->Head;
        while (CurrentNode->nextNode != nullptr)
        {
            CurrentNode = CurrentNode->nextNode;
        }
        CurrentNode->nextNode = new RebelNode(value);
    }
    else
    {
        this->Head = new RebelNode(value);
    }
}

void RebelSinglyLinkedList::Prepend(int value)
{
    RebelNode *secondNode = this->Head;
    this->Head = new RebelNode(value);
    this->Head->nextNode = secondNode;
}

void RebelSinglyLinkedList::Insert(int value, int index)
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

void RebelSinglyLinkedList::Delete(int element)
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

void RebelSinglyLinkedList::pop(int index)
{
    RebelNode *CurrentNode = this->Head;

    for (int i = 0; i < index - 1; i++)
    {
        CurrentNode = CurrentNode->nextNode;
    }

    CurrentNode->nextNode = CurrentNode->nextNode->nextNode;
}

int RebelSinglyLinkedList::count(int element)
{
    RebelNode *CurrentNode = this->Head;
    int i = 0;

    while (CurrentNode != nullptr)
    {
        if (CurrentNode->value == element)
        {
            i++;
        }
        CurrentNode = CurrentNode->nextNode;
    }
    return i;
}

int RebelSinglyLinkedList::index(int element)
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

void RebelSinglyLinkedList::print()
{
    RebelNode *CurrentNode = this->Head;

    while (CurrentNode != nullptr)
    {
        std::cout << "[" << CurrentNode->value << "] -> ";
        CurrentNode = CurrentNode->nextNode;
    }
    std::cout << "[NULL]" << std::endl;
}

int main()
{
    RebelSinglyLinkedList myList;
    myList.Append(1);
    myList.Append(3);
    myList.Append(7);
    myList.print();
    myList.Prepend(99);
    myList.print();
    myList.Insert(69, 2);
    myList.print();
    myList.Delete(1);
    myList.Insert(69, 4);
    myList.print();
    myList.pop(2);
    myList.print();
    std::cout << myList.Lookup(2) << std::endl;
    std::cout << myList.index(7) << std::endl;
    myList.print();
    std::cout << myList.count(69) << std::endl;

    RebelSinglyLinkedList myList2(100);
    myList2.print();

    return 0;
}