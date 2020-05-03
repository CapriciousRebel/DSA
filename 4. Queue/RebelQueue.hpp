/// EnQueue: O(1)
/// DeQueue: O(1)
/// -> [Back] -> [element1] -> [element2] -> [element3] -> [Front] ->

template <typename T>
class RebelElement
{
public:
    T value;
    RebelElement *nextPlate;
    RebelElement *previousPlate;

    RebelElement(T value)
    {
        this->value = value;
        nextPlate = nullptr;
        previousPlate = nullptr;
    }
};

template <typename T>
class RebelQueue
{
private:
    RebelElement<T> *FrontPlate;
    RebelElement<T> *BackPlate;

public:
    /// Create an Empty RebelQueue
    RebelQueue();

    /// value: first entry in the RebelQueue
    RebelQueue(T value);

    /// EnQueue a value onto the Back of the RebelQueue
    void EnQueue(T value);

    /// DeQueue the value from the Front of the RebelQueue
    void DeQueue();

    /// Print's the current RebelQueue
    void print();
};