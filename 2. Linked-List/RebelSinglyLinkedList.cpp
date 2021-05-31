#define RebelPrint(x, y) std::cout << x << "  " << y << std::endl;

#include <iostream>
#include "RebelSinglyLinkedList.hpp"

template <typename T>
RebelSinglyLinkedList<T>::RebelSinglyLinkedList()
{
    this->Head = nullptr;
}

template <typename T>
RebelSinglyLinkedList<T>::RebelSinglyLinkedList(T value)
{
    this->Head = new RebelNode<T>(value);
}

template <typename T>
T RebelSinglyLinkedList<T>::Lookup(int index)
{
    RebelNode<T> *CurrentNode = this->Head;
    for (int i = 0; i < index; i++)
    {
        CurrentNode = CurrentNode->nextNode;
    }
    return CurrentNode->value;
}

template <typename T>
void RebelSinglyLinkedList<T>::Append(T value)
{
    if (this->Head != nullptr)
    {
        RebelNode<T> *CurrentNode = this->Head;
        while (CurrentNode->nextNode != nullptr)
        {
            CurrentNode = CurrentNode->nextNode;
        }
        CurrentNode->nextNode = new RebelNode<T>(value);
    }
    else
    {
        this->Head = new RebelNode<T>(value);
    }
}

template <typename T>
void RebelSinglyLinkedList<T>::Prepend(T value)
{
    RebelNode<T> *secondNode = this->Head;
    this->Head = new RebelNode<T>(value);
    this->Head->nextNode = secondNode;
}

template <typename T>
void RebelSinglyLinkedList<T>::Insert(T value, int index)
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
void RebelSinglyLinkedList<T>::Delete(T element)
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
void RebelSinglyLinkedList<T>::pop(int index)
{
    RebelNode<T> *CurrentNode = this->Head;

    for (int i = 0; i < index - 1; i++)
    {
        CurrentNode = CurrentNode->nextNode;
    }

    CurrentNode->nextNode = CurrentNode->nextNode->nextNode;
}

template <typename T>
int RebelSinglyLinkedList<T>::count(T element)
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
int RebelSinglyLinkedList<T>::index(T element)
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
void RebelSinglyLinkedList<T>::reverse()
{
    if (this->Head != nullptr) // handle empty linked list edge case (do nothing if empty)
    {
        RebelNode<T> *CurrentNode, *NextNode, *PreviousNode;

        CurrentNode = this->Head;
        NextNode = CurrentNode->nextNode;
        PreviousNode = nullptr;

        while (CurrentNode != nullptr)
        {
            // Save the next node
            NextNode = CurrentNode->nextNode;
            // link the next node of current node to the previous node (reverse the node)
            CurrentNode->nextNode = PreviousNode;
            // now the current node is the previous node for the next node
            PreviousNode = CurrentNode;
            // Update the currentnode to the next node in the linkedlist that we saved earlier
            CurrentNode = NextNode;
        }
        // assign head to the last node
        this->Head = PreviousNode;
    }
}

template <typename T>
void RebelSinglyLinkedList<T>::print()
{
    RebelNode<T> *CurrentNode = this->Head;

    while (CurrentNode != nullptr)
    {
        std::cout << "[" << CurrentNode->value << "] -> ";
        CurrentNode = CurrentNode->nextNode;
    }
    std::cout << "[NULL]" << std::endl;
}

int main()
{
    RebelSinglyLinkedList<float> myList;
    RebelPrint("Create a linked list!", "");
    myList.print();
    RebelPrint("Test Append!", "");
    myList.Append(1.4);
    myList.print();

    myList.Append(3.1);
    myList.print();

    myList.Append(7);
    myList.print();

    myList.Append(100);
    myList.print();

    myList.Append(120);
    myList.print();

    RebelPrint("Test Prepend!", "");
    myList.Prepend(99);
    myList.print();

    RebelPrint("Test Insert!", "");
    myList.Insert(69, 2);
    myList.print();

    RebelPrint("Test Delete!", "");
    myList.Delete(1.4);
    myList.print();

    myList.Insert(69, 4);
    myList.print();

    RebelPrint("Test pop!", "");
    myList.pop(2);
    myList.print();

    RebelPrint("Test Reverse a linked list!", "");
    myList.reverse();
    myList.print();

    std::cout << myList.Lookup(2) << std::endl;
    std::cout << myList.index(7) << std::endl;
    std::cout << myList.count(69) << std::endl;

    return 0;
}