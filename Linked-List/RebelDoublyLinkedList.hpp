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
    RebelNode *previousNode;

    RebelNode(int value)
    {
        this->value = value;
        nextNode = nullptr;
        previousNode = nullptr;
    }
};

class RebelDoublyLinkedList
{
private:
    RebelNode *Head;

public:
    /// Creates an Empty Rebel Singly Linked List
    RebelDoublyLinkedList();

    /// value: value of the head node
    RebelDoublyLinkedList(int value);

    /// returns the element at the given index
    /// O(N)
    int Lookup(int index);

    /// insert element at the end of the RebelDoublyLinkedList
    /// [O(N)]
    void Append(int element);

    /// insert element at the start of the RebelDoublyLinkedList
    /// [O(1)]
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

    /// prints the RebelDoublyLinkedList to the console
    /// O(N)
    void print();

    /// prints the RebelDoublyLinkedList to the console in forwards and the reverse order
    /// O(N)
    void print_reverse();
};