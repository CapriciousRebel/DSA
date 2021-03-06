#include <iostream>
#include <stdarg.h>
#include "RebelArray.hpp"

template <typename T>
RebelArray<T>::RebelArray()
{
    T *newarr = new T[0];
    arr = newarr;
    N = 0;
}

template <typename T>
T RebelArray<T>::Lookup(int index)
{
    if (index > N - 1)
    {
        throw "Index Out of Bounds!";
    }
    if (index < 0)
    {
        return arr[N - index - 2];
    }
    return arr[index];
}

template <typename T>
void RebelArray<T>::Prepend(T element)
{
    RebelArray::Insert(element, 0);
}

template <typename T>
void RebelArray<T>::Append(T element)
{
    RebelArray::Insert(element, N);
}

template <typename T>
void RebelArray<T>::Insert(T element, int index)
{
    T *newarr = new T[N + 1];
    for (int i = 0; i < index; i++)
    {
        newarr[i] = arr[i];
    }
    newarr[index] = element;
    for (int i = index + 1; i < N + 1; i++)
    {
        newarr[i] = arr[i - 1];
    }
    arr = newarr;
    N++;
}

template <typename T>
void RebelArray<T>::pop(int index)
{

    T *newarr = new T[N - 1];
    for (int i = 0; i < index; i++)
    {
        newarr[i] = arr[i];
    }
    for (int j = index; j < N - 1; j++)
    {
        newarr[j] = arr[j + 1];
    }
    arr = newarr;
    N--;
}

template <typename T>
void RebelArray<T>::Delete(T element)
{
    T *newarr = new T[N - 1];
    int i;
    for (i = 0; i < N; i++)
    {
        if (arr[i] == element)
        {
            break;
        }
        else
        {
            newarr[i] = arr[i];
        }
    }
    for (int j = i; j < N - 1; j++)
    {
        newarr[j] = arr[j + 1];
    }
    arr = newarr;
    N--;
}

template <typename T>
int RebelArray<T>::count(T element)
{
    int element_count = 0;
    for (int i = 0; i < N; i++)
    {
        if (arr[i] == element)
        {
            element_count++;
        }
    }
    return element_count;
}

template <typename T>
int RebelArray<T>::index(T element)
{
    T *newarr = new T[N - 1];
    for (int i = 0; i < N; i++)
    {
        if (arr[i] == element)
        {
            return i;
        }
    }
    return -1;
}

template <typename T>
void RebelArray<T>::print()
{
    std::cout << "[";
    if (N == 0)
    {
        std::cout << " ";
    }
    else if (N == 1)
    {
        std::cout << arr[0];
    }
    else
    {
        for (int i = 0; i < N - 1; i++)
        {
            std::cout << arr[i] << ", ";
        }
        std::cout << arr[N - 1];
    }
    std::cout << "]" << std::endl;
}

int main()
{
    RebelArray<float> numbers1;
    numbers1.Append(1.2);
    numbers1.print();
    numbers1.Append(4.8);
    numbers1.print();
    numbers1.Append(5.1);
    numbers1.print();
    numbers1.Append(4);
    numbers1.print();
    numbers1.Insert(10, 2);
    numbers1.print();
    numbers1.pop(2);
    numbers1.Prepend(9);
    numbers1.print();
    std::cout << numbers1.index(5.1);
    std::cout << "\n"
              << numbers1.Lookup(-1) << "\n";

    return 0;
}
