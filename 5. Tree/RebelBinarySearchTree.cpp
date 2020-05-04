#include <iostream>
#include "RebelBinarySearchTree.hpp"
#include "../4. Queue/RebelQueue.cpp"

template <typename T>
RebelBinarySearchTree<T>::RebelBinarySearchTree()
{
    this->RootNode = nullptr;
}

template <typename T>
RebelBinarySearchTree<T>::RebelBinarySearchTree(T value)
{
    this->RootNode = new RebelNode<T>(value);
}

template <typename T>
void RebelBinarySearchTree<T>::Insert(T value)
{
    if (this->RootNode == nullptr)
    {
        this->RootNode = new RebelNode<T>(value);
    }
    else
    {
        RebelNode<T> *CurrentNode = this->RootNode;

        while (true)
        {
            if (value < CurrentNode->value)
            {
                if (CurrentNode->leftNode == nullptr)
                {
                    RebelNode<T> *NewNode = new RebelNode<T>(value);
                    CurrentNode->leftNode = NewNode;
                    break;
                }
                else
                {
                    CurrentNode = CurrentNode->leftNode;
                }
            }
            else
            {
                if (CurrentNode->rightNode == nullptr)
                {
                    RebelNode<T> *NewNode = new RebelNode<T>(value);
                    CurrentNode->rightNode = NewNode;
                    break;
                }
                else
                {
                    CurrentNode = CurrentNode->rightNode;
                }
            }
        }
    }
}

// [WIP]
template <typename T>
void RebelBinarySearchTree<T>::Delete(T value)
{
    RebelNode<T> *CurrentNode = this->RootNode;

    while (true)
    {
        if (value < CurrentNode->value)
        {
            if (CurrentNode->leftNode->value == value)
            {
                if (CurrentNode->leftNode->leftNode == nullptr && CurrentNode->leftNode->rightNode == nullptr)
                {
                    CurrentNode->leftNode = nullptr;
                }
                else if (CurrentNode->leftNode->leftNode != nullptr && CurrentNode->leftNode->rightNode == nullptr)
                {
                    CurrentNode->leftNode = CurrentNode->leftNode->leftNode;
                }
                else if (CurrentNode->leftNode->leftNode == nullptr && CurrentNode->leftNode->rightNode != nullptr)
                {
                    CurrentNode->rightNode = CurrentNode->leftNode->rightNode;
                }
                else if (CurrentNode->leftNode->leftNode != nullptr && CurrentNode->leftNode->rightNode != nullptr)
                {
                    RebelNode<T> *NewNode = CurrentNode->leftNode->rightNode;
                    // find min in the right subtree and replace
                    while (NewNode->leftNode != nullptr)
                    {
                        NewNode = NewNode->leftNode;
                    }

                    NewNode->leftNode = CurrentNode->leftNode->leftNode;
                    NewNode->rightNode = CurrentNode->leftNode->rightNode;
                    CurrentNode->leftNode = NewNode;
                }
                break;
            }
            else
            {
                CurrentNode = CurrentNode->leftNode;
            }
        }
        else if (value > CurrentNode->value)
        {
            CurrentNode = CurrentNode->rightNode;
        }
        else
        {
        }
    }
}

template <typename T>
void RebelBinarySearchTree<T>::printInorder(RebelNode<T> *CurrentNode)
{
    if (CurrentNode == nullptr)
    {
        return;
    }
    /* first recur on left child */
    printInorder(CurrentNode->leftNode);

    /* then print the data of node */
    std::cout << CurrentNode->value << " ";

    /* finally recur on right child */
    printInorder(CurrentNode->rightNode);
}

template <typename T>
void RebelBinarySearchTree<T>::printPreorder(RebelNode<T> *node)
{
    if (node == nullptr)
    {
        return;
    }

    /* first print the data of node */
    std::cout << node->value << " ";

    /* then recur on left child */
    printInorder(node->leftNode);

    /* finally recur on right child */
    printInorder(node->rightNode);
}

template <typename T>
void RebelBinarySearchTree<T>::printPostorder(RebelNode<T> *node)
{
    if (node == nullptr)
    {
        return;
    }

    /* first recur on left child */
    printInorder(node->leftNode);

    /* then recur on right child */
    printInorder(node->rightNode);

    /* finally print the data of node */
    std::cout << node->value << " ";
}

template <typename T>
void RebelBinarySearchTree<T>::printLevelorder()
{
    RebelNode<T> *CurrentNode = this->RootNode;
    /*** Error on this line:  RebelQueue<RebelNode> myQueue; ***/

    while (CurrentNode != nullptr)
    {
        std::cout << CurrentNode->value << " ";
        myQueue.EnQueue(CurrentNode->leftNode);
        myQueue.EnQueue(CurrentNode->rightNode);
        CurrentNode = myQueue.DeQueue();
    }
}

template <typename T>
void RebelBinarySearchTree<T>::print(std::string transversal_type)
{
    if (transversal_type == "inorder")
    {
        printInorder(this->RootNode);
    }
    else if (transversal_type == "preorder")
    {
        printPreorder(this->RootNode);
    }
    else if (transversal_type == "postorder")
    {
        printPostorder(this->RootNode);
    }
    else if (transversal_type == "levelorder")
    {
        printLevelorder();
    }

    std::cout << std::endl;
}

int main()
{
    RebelBinarySearchTree<int> myTree;
    myTree.Insert(20);

    myTree.Insert(10);

    myTree.Insert(30);

    myTree.Insert(5);

    myTree.Insert(15);

    myTree.Insert(25);

    myTree.Insert(35);

    myTree.Insert(2);

    myTree.Insert(7);

    myTree.Insert(8);

    myTree.Insert(12);

    myTree.Insert(13);

    myTree.Insert(11);

    myTree.Insert(16);
    myTree.print("inorder");
    myTree.print("preorder");
    myTree.print("postorder");
    myTree.print("levelorder");

    return 0;
}