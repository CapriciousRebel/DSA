#include <iostream>
#include "RebelDoublyLinkedList.hpp"

template <typename T>
RebelDoublyLinkedList<T>::RebelDoublyLinkedList()
{
    this->Head = nullptr;
}

template <typename T>
RebelDoublyLinkedList<T>::RebelDoublyLinkedList(T value)
{
    this->Head = new RebelNode<T>(value);
}

template <typename T>
T RebelDoublyLinkedList<T>::Lookup(int index)
{
    RebelNode<T> *CurrentNode = this->Head;
    for (int i = 0; i < index; i++)
    {
        CurrentNode = CurrentNode->nextNode;
    }
    return CurrentNode->value;
}

template <typename T>
void RebelDoublyLinkedList<T>::Append(T value)
{
    if (this->Head != nullptr)
    {
        RebelNode<T> *CurrentNode = this->Head;
        while (CurrentNode->nextNode != nullptr)
        {
            CurrentNode = CurrentNode->nextNode;
        }
        CurrentNode->nextNode = new RebelNode<T>(value);
        CurrentNode->nextNode->previousNode = CurrentNode;
    }
    else
    {
        this->Head = new RebelNode<T>(value);
    }
}

template <typename T>
void RebelDoublyLinkedList<T>::Prepend(T value)
{
    RebelNode<T> *secondNode = this->Head;
    this->Head = new RebelNode<T>(value);
    this->Head->nextNode = secondNode;
    this->Head->nextNode->previousNode = this->Head;
}

template <typename T>
void RebelDoublyLinkedList<T>::Insert(T value, int index)
{
    RebelNode<T> *NewNode = new RebelNode<T>(value);
    RebelNode<T> *CurrentNode = this->Head;

    for (int i = 0; i < index - 1; i++)
    {
        CurrentNode = CurrentNode->nextNode;
    }
    CurrentNode->nextNode->previousNode = NewNode;
    NewNode->nextNode = CurrentNode->nextNode;
    NewNode->previousNode = CurrentNode;
    CurrentNode->nextNode = NewNode;
}

template <typename T>
void RebelDoublyLinkedList<T>::Delete(T element)
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
void RebelDoublyLinkedList<T>::pop(int index)
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
int RebelDoublyLinkedList<T>::count(T element)
{
    RebelNode<T> *CurrentNode = this->Head;
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

template <typename T>
int RebelDoublyLinkedList<T>::index(T element)
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
void RebelDoublyLinkedList<T>::print()
{
    RebelNode<T> *CurrentNode = this->Head;

    std::cout << "[NULL] <-> ";
    while (CurrentNode != nullptr)
    {
        std::cout << "[" << CurrentNode->value << "] <-> ";
        CurrentNode = CurrentNode->nextNode;
    }
    std::cout << "[NULL]" << std::endl;
}

template <typename T>
void RebelDoublyLinkedList<T>::print_reverse()
{
    RebelNode<T> *CurrentNode = this->Head;

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
    RebelDoublyLinkedList<int> myList;
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