class RebelArray
{
private:
    int *arr;
    int N;

public:
    RebelArray();
    /// num: number of elements in the Rebelarray
    RebelArray(int num, ...);
    /// insert element at the end of the Rebelarray
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
    /// prints the Rebelarray to the console
    /// O(N)
    void print();
};
