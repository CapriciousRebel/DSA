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

class RebelSinglyLinkedList
{
private:
    RebelNode *Head;

public:
    /// Creates an Empty Rebel Singly Linked List
    RebelSinglyLinkedList();

    /// value: value of the head node
    RebelSinglyLinkedList(int value);

    /// returns the element at the given index
    /// O(N)
    int Lookup(int index);

    /// insert element at the end of the RebelSinglyLinkedList
    /// [O(N)]
    void Append(int element);

    /// insert element at the start of the RebelSinglyLinkedList
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

    /// prints the RebelSinglyLinkedList to the console
    /// O(N)
    void print();
};