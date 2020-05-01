#include <iostream>
#include <stdarg.h>
#include "Array.hpp"

Array::Array()
{
    N = 0;
}

Array::Array(int num, ...)
{
    int *newarr = new int[num];
    va_list args;
    va_start(args, num);
    for (int i = 0; i < num; i++)
    {
        int value = va_arg(args, int);
        newarr[i] = value;
    }
    arr = newarr;
    N = num;
}

void Array::append(int element)
{

    int *newarr = new int[N + 1];
    for (int i = 0; i < N; i++)
    {
        newarr[i] = arr[i];
    }

    newarr[N] = element;
    arr = newarr;
    N++;
}

void Array::insert(int element, int index)
{

    int *newarr = new int[N + 1];
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

void Array::pop(int index)
{

    int *newarr = new int[N - 1];
    static int i;
    for (i = 0; i < index; i++)
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

void Array::remove(int element)
{
    int *newarr = new int[N - 1];
    static int i;
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

int Array::count(int element)
{
    static int element_count = 0;
    for (int i = 0; i < N; i++)
    {
        if (arr[i] == element)
        {
            element_count++;
        }
    }
    return element_count;
}

int Array::index(int element)
{
    int *newarr = new int[N - 1];
    for (int i = 0; i < N; i++)
    {
        if (arr[i] == element)
        {
            return i;
        }
    }
    return -1;
}

int Array::getElement(int index)
{
    return arr[index];
}

void Array::print()
{
    std::cout << "[";

    if (N == 1)
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
    Array numbers1;
    numbers1.append(1);
    numbers1.append(4);
    numbers1.append(5);
    numbers1.append(4);
    numbers1.insert(10, 2);
    numbers1.pop(2);
    numbers1.print();
    std::cout << "\n"
              << numbers1.index(4);
    std::cout << "\n"
              << numbers1.getElement(2) << "\n";

    Array numbers2(3, 1, 2, 3);
    numbers2.print();

    return 0;
}
