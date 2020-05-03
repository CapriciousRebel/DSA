/// Push: O(1)
/// Pop: O(1)
/// [Bottom] -> [element1] -> [element2 ] -> [element3] 

template <typename T>
class RebelPlate
{
public:
    T value;
    RebelPlate *nextPlate;

    RebelPlate(T value)
    {
        this->value = value;
        nextPlate = nullptr;
    }
};

template <typename T>
class RebelStack
{
private:
    RebelPlate<T> *TopPlate;

public:
    /// Create an Empty RebelStack
    RebelStack();

    /// value: first entry in the RebelStack
    RebelStack(T value);

    /// Push a value onto the RebelStack
    void push(T value);

    /// Pop the top value from the RebelStack
    void pop();

    /// Print's the current stack
    void print();
};