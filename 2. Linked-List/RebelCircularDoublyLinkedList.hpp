/// Lookup:  O(N)
/// Append:  O(N)
/// Prepend: O(1)
/// Insert:  O(N)
/// Delete:  O(N)
/// [element1] <-> [element2] <-> [element3] <-> [HEAD]

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
    }
};

template <typename T>
class RebelCircularDoublyLinkedList
{
private:
    RebelNode<T> *Head;

public:
    /// Creates an Empty RebelCircularDoublyLinkedList
    RebelCircularDoublyLinkedList();

    /// value: value of the head node
    RebelCircularDoublyLinkedList(T value);

    /// returns the element at the given index
    /// O(N)
    T Lookup(int index);

    /// Insert a node just after the head
    /// [O(1)]
    void Append(T element);

    /// Insert Element before head, and make it the head
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

    /// prints the RebelCircularDoublyLinkedList to the console
    /// O(N)
    void print();
};