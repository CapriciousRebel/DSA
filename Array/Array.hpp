#ifndef Bug_H
#define Bug_H

class Array
{
private:
    int *arr;
    int N;

public:
    Array();
    /// insert element at the end of the array
    /// [O(N)]
    void append(int element);
    /// insert element at the given index
    /// [O(N)]
    void insert(int element, int index);
    /// delete element at the given index
    /// [O(N)]
    void pop(int index);
    /// delete the first occurence of the given element
    /// [O(N)]
    void remove(int element);
    /// returns the number of occurences of the given element
    /// [O(N)]
    int count(int element);
    /// returns the index of the first occurence of the given element
    /// [O(N)]
    int index(int element);
    /// returns the element at the given index
    /// O(1)
    int getElement(int index);
    /// prints the array to the console
    /// O(N)
    void print();
};

#endif
