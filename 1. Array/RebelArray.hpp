/// Lookup:  O(1)
/// Append:  O(N)
/// Prepend: O(N)
/// Insert:  O(N)
/// Delete:  O(N)

template <typename T>
class RebelArray
{
private:
    T *arr;
    int N;

public:
    /// Creates an empty Rebel Array
    RebelArray();

    /// returns the element at the given index
    /// O(1)
    T Lookup(int index);

    /// insert element at the end of the Rebelarray
    /// [O(N)]
    void Append(T element);

    /// insert element at the start of the Rebelarray
    /// [O(N)]
    void Prepend(T element);

    /// insert element at the given index
    /// [O(N)]
    void Insert(T element, int index);

    /// delete the first occurence of the given element
    /// [O(N)]
    void Delete(T element);

    /// delete element at the given index
    /// [O(N)]
    void pop(int index);

    /// returns the number of occurences of the given element
    /// [O(N)]
    int count(T element);

    /// returns the index of the first occurence of the given element
    /// [O(N)]
    int index(T element);

    /// prints the Rebelarray to the console
    /// O(N)
    void print();
};
