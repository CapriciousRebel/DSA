/// N = Number of elements, h = height of tree
/// Lookup: O(N)
/// Insert: O(h) = O(N)
/// Delete: O(N)
// The tree here is not balanced in any way, so the maximum possible height of the tree is N

template <typename T>
class RebelNode
{
public:
    T value;
    RebelNode *leftNode;
    RebelNode *rightNode;

    RebelNode(T value)
    {
        this->value = value;
        leftNode = nullptr;
        rightNode = nullptr;
    }
};

template <typename T>
class RebelBinarySearchTree
{
private:
    RebelNode<T> *RootNode;

public:
    /// Create an Empty RebelBinarySearchTree
    RebelBinarySearchTree();

    /// value: root of the RebelBinarySearchTree
    RebelBinarySearchTree(T value);

    /// Insert a node in the RebelBinarySearchTree
    ///
    void Insert(T value);

    /// Delete a node in the RebelBinarySearchTree
    void Delete(T value);

    /// Prints the tree onto the console
    void print(std::string transversal_type);

    /// Prints the tree Inorder(left->root->right)
    void printInorder(RebelNode<T> *CurrentNode);

    /// Prints the tree Preorder(root->left->right)
    void printPreorder(RebelNode<T> *CurrentNode);

    /// Prints the tree Postorder(left->right->root)
    void printPostorder(RebelNode<T> *CurrentNode);

    /// Prints the tree Levelorder(index-wise)
    void printLevelorder();
};