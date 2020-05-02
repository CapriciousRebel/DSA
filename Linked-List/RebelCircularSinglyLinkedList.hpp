/// Lookup:  O(N)
/// Append:  O(N)
/// Prepend: O(1)
/// Insert:  O(N)
/// Delete:  O(N)
class RebelNode
{
public:
    int value;
    RebelNode *nextNode;

    RebelNode(int value)
    {
        this->value = value;
        nextNode = nullptr;
    }
};

class RebelCircularSinglyLinkedList
{
private:
    RebelNode *Head;

public:
    /// Creates an Empty RebelCircularSinglyLinkedList
    RebelCircularSinglyLinkedList();

    /// value: value of the head node
    RebelCircularSinglyLinkedList(int value);

    /// returns the element at the given index
    /// O(N)
    int Lookup(int index);

    /// Insert a node just after the head
    /// [O(1)]
    void Append(int element);

    /// Insert Element before head, and make it the head
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

    /// prints the RebelCircularSinglyLinkedList to the console
    /// O(N)
    void print();
};