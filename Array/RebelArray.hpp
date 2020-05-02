/// Lookup:  O(1)
/// Append:  O(N)
/// Prepend: O(N)
/// Insert:  O(N)
/// Delete:  O(N)
class RebelArray

{
private:
    int *arr;
    int N;

public:
    /// Creates an empty Rebel Array
    RebelArray();

    /// num: number of elements in the Rebelarray
    RebelArray(int num, ...);

    /// returns the element at the given index
    /// O(1)
    int Lookup(int index);

    /// insert element at the end of the Rebelarray
    /// [O(N)]
    void Append(int element);

    /// insert element at the start of the Rebelarray
    /// [O(N)]
    void Prepend(int element);

    /// insert element at the given index
    /// [O(N)]
    void Insert(int element, int index);

    /// delete the first occurence of the given element
    /// [O(N)]
    void Delete(int element);

    /// delete element at the given index
    /// [O(N)]
    void pop(int index);

    /// returns the number of occurences of the given element
    /// [O(N)]
    int count(int element);

    /// returns the index of the first occurence of the given element
    /// [O(N)]
    int index(int element);

    /// prints the Rebelarray to the console
    /// O(N)
    void print();
};
