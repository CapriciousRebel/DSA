#include <iostream>
#include "RebelDoublyLinkedList.hpp"

RebelDoublyLinkedList::RebelDoublyLinkedList()
{
    this->Head = nullptr;
}

RebelDoublyLinkedList::RebelDoublyLinkedList(int value)
{
    this->Head = new RebelNode(value);
}

int RebelDoublyLinkedList::Lookup(int index)
{
    RebelNode *CurrentNode = this->Head;
    for (int i = 0; i < index; i++)
    {
        CurrentNode = CurrentNode->nextNode;
    }
    return CurrentNode->value;
}

void RebelDoublyLinkedList::Append(int value)
{
    if (this->Head != nullptr)
    {
        RebelNode *CurrentNode = this->Head;
        while (CurrentNode->nextNode != nullptr)
        {
            CurrentNode = CurrentNode->nextNode;
        }
        CurrentNode->nextNode = new RebelNode(value);
        CurrentNode->nextNode->previousNode = CurrentNode;
    }
    else
    {
        this->Head = new RebelNode(value);
    }
}

void RebelDoublyLinkedList::Prepend(int value)
{
    RebelNode *secondNode = this->Head;
    this->Head = new RebelNode(value);
    this->Head->nextNode = secondNode;
    this->Head->nextNode->previousNode = this->Head;
}

void RebelDoublyLinkedList::Insert(int value, int index)
{
    RebelNode *NewNode = new RebelNode(value);
    RebelNode *CurrentNode = this->Head;

    for (int i = 0; i < index - 1; i++)
    {
        CurrentNode = CurrentNode->nextNode;
    }
    CurrentNode->nextNode->previousNode = NewNode;
    NewNode->nextNode = CurrentNode->nextNode;
    NewNode->previousNode = CurrentNode;
    CurrentNode->nextNode = NewNode;
}

void RebelDoublyLinkedList::Delete(int element)
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

void RebelDoublyLinkedList::pop(int index)
{
    RebelNode *CurrentNode = this->Head;

    for (int i = 0; i < index - 1; i++)
    {
        CurrentNode = CurrentNode->nextNode;
    }

    CurrentNode->nextNode = CurrentNode->nextNode->nextNode;
    CurrentNode->nextNode->nextNode->previousNode = CurrentNode;
}

int RebelDoublyLinkedList::count(int element)
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

int RebelDoublyLinkedList::index(int element)
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

void RebelDoublyLinkedList::print()
{
    RebelNode *CurrentNode = this->Head;

    std::cout << "[NULL] <-> ";
    while (CurrentNode != nullptr)
    {
        std::cout << "[" << CurrentNode->value << "] <-> ";
        CurrentNode = CurrentNode->nextNode;
    }
    std::cout << "[NULL]" << std::endl;
}

void RebelDoublyLinkedList::print_reverse()
{
    RebelNode *CurrentNode = this->Head;

    std::cout << "(forward)[NULL] <-> ";
    while (CurrentNode->nextNode != nullptr)
    {
        std::cout << "[" << CurrentNode->value << "] <-> ";
        CurrentNode = CurrentNode->nextNode;
    }
    std::cout << "[" << CurrentNode->value << "] <-> ";

    //CurrentNode = CurrentNode->previousNode->previousNode;
    std::cout << "[NULL]\n(reverse) [NULL] <-> ";

    while (CurrentNode != nullptr)
    {
        std::cout << "[" << CurrentNode->value << "] <-> ";
        CurrentNode = CurrentNode->previousNode;
    }
    std::cout << "[NULL]" << std::endl;
}

int main()
{
    RebelDoublyLinkedList myList;
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

    myList.Delete(69);
    myList.print();

    myList.Insert(69, 2);
    myList.print();

    myList.Insert(62, 2);
    myList.print();

    myList.Insert(23, 4);
    myList.print();

    myList.Insert(23, 4);
    myList.print();

    myList.Insert(23, 4);
    myList.print();

    myList.Insert(23, 4);
    myList.print();

    myList.pop(1);
    myList.print();

    std::cout << myList.count(23) << std::endl;

    std::cout << "\n";
    myList.print();
    myList.print_reverse();

    return 0;
}