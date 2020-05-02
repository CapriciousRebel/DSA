/// Lookup:  O(N)
/// Append:  O(N)
/// Prepend: O(1)
/// Insert:  O(N)
/// Delete:  O(N)
template <typename T>
class RebelNode
{
public:
    T value;
    RebelNode *nextNode;
    RebelNode *previousNode;

    RebelNode(T value)
    {
        this->value = value;
        nextNode = nullptr;
        previousNode = nullptr;
    }
};

template <typename T>
class RebelDoublyLinkedList
{
private:
    RebelNode<T> *Head;

public:
    /// Creates an Empty Rebel Singly Linked List
    RebelDoublyLinkedList();

    /// value: value of the head node
    RebelDoublyLinkedList(T value);

    /// returns the element at the given index
    /// O(N)
    T Lookup(int index);

    /// insert element at the end of the RebelDoublyLinkedList
    /// [O(N)]
    void Append(T element);

    /// insert element at the start of the RebelDoublyLinkedList
    /// [O(1)]
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

    /// prints the RebelDoublyLinkedList to the console
    /// O(N)
    void print();

    /// prints the RebelDoublyLinkedList to the console in forwards and the reverse order
    /// O(N)
    void print_reverse();
};