#include <iostream>
#include <cstdlib>

using namespace std;

#define br cout << endl //* Macro for printing a newline

//* Template structure for a node in the Binary Search Tree
template <typename t>
struct Node {
    t data; //* Data stored in the node
    Node<t>* left, *right; //* Pointers to the left and right children

    //* Constructor to initialize a node with a value
    Node(t val) : data(val), left(nullptr), right(nullptr) {}
};

//* Template class for the Binary Search Tree
template <typename t>
class BST {
    private:
        Node<t>* root; //* Pointer to the root of the tree

        //* Helper function to find the minimum value node in a subtree
        Node<t>* findMin(Node<t>* temp) const {
            if (!temp) return nullptr; //* Return null if subtree is empty
            while (temp->left) temp = temp->left; //* Traverse to the leftmost node
            return temp; //* The leftmost node is the minimum
        }

    public:
        //* Constructor to initialize an empty tree
        BST() : root(nullptr) {}

        //* Destructor to delete all nodes and free memory
        ~BST() {
            while (root) {
                remove(root->data); //* Continuously remove the root until the tree is empty
            }
        }

        //* Function to insert a value into the BST
        void insert(t val) {
            Node<t>* temp = new Node<t>(val); //* Create a new node
            if (!root) {
                root = temp; //* If tree is empty, make the new node the root
                return;
            }

            Node<t>* current = root, *parent = nullptr;
            while (current) {
                parent = current;
                if (val < current->data) current = current->left; //* Move left if value is smaller
                else if (val > current->data) current = current->right; //* Move right if value is larger
                else {
                    cout << "already exists such value"; br;
                    delete temp; //* If value already exists, do nothing
                    return;
                }
            }

            //* Insert the new node as a left or right child of the parent
            if (val < parent->data) parent->left = temp;
            else parent->right = temp;
        }

        //* Function to search for a value in the BST
        bool search(t val) const {
            Node<t>* current = root;
            while (current) {
                if (val == current->data) return true; //* Value found
                if (val < current->data) current = current->left; //* Move left if value is smaller
                else current = current->right; //* Move right if value is larger
            }
            return false; //* Value not found
        }

        //* Function to remove a value from the BST
        void remove(t val) {
            Node<t>* current = root, *parent = nullptr;
            //* Find the node to be deleted and its parent
            while (current && current->data != val) {
                parent = current;
                if (val < current->data) current = current->left;
                else current = current->right;
            }

            if (!current) {
                cout << "NO SUCH ELEM" << endl; //* Node not found
                return;
            }

            //* Case 1: Node has no children (leaf node)
            if (!current->left && !current->right) {
                if (!parent) root = nullptr; //* If it's the root, make the tree empty
                else if (parent->left == current) parent->left = nullptr; //* Detach from the parent
                else parent->right = nullptr;
                delete current; //* Free the node's memory
            }
            //* Case 2: Node has one child
            else if (!current->left || !current->right) {
                Node<t>* child = current->left ? current->left : current->right;
                if (!parent) root = child; //* If it's the root, make the child the new root
                else if (parent->left == current) parent->left = child; //* Attach the child to the parent
                else parent->right = child;
                delete current; //* Free the node's memory
            }
            //* Case 3: Node has two children
            else {
                Node<t>* successor = findMin(current->right); //* Find the in-order successor
                t successorVal = successor->data;
                remove(successor->data); //* Recursively remove the successor node
                current->data = successorVal; //* Replace current node's data with the successor's data
            }
        }

        //* Function to perform in-order traversal of the BST
        void inorder() const {
            Node<t>* cur = root, *stack[2000];
            int top = -1;
            while (cur || top != -1) {
                while (cur) {
                    stack[++top] = cur; //* Push the current node onto the stack
                    cur = cur->left; //* Move to the left child
                }
                cur = stack[top--]; //* Pop the node from the stack
                cout << cur->data << " "; //* Visit the node
                cur = cur->right; //* Move to the right child
            }
            br; //* Print a newline
        }

        //* Function to count the number of nodes in the BST
        size_t size() const {
            size_t count = 0;
            Node<t>* cur = root, *stack[20000];
            int top = -1;
            while (cur || top != -1) {
                while (cur) {
                    stack[++top] = cur; //* Push the current node onto the stack
                    cur = cur->left; //* Move to the left child
                }
                cur = stack[top--]; //* Pop the node from the stack
                count++; //* Increment the count for each node
                cur = cur->right; //* Move to the right child
            }
            return count; //* Return the total number of nodes
        }

        //* Function to check if the tree is empty
        bool isEmpty() const {
            return !root; //* Returns true if root is null
        }
};

int main() {
    BST<int> tree;

    for (int i = 1; i <= 20; i++) tree.insert(rand() % 40 + 1); //* Insert random values into the tree
    
    tree.inorder(); //* Print in-order traversal
    tree.remove(20); //* Remove the node with value 20
    tree.inorder();
    tree.remove(1); //* Remove the node with value 1
    tree.inorder();
    tree.remove(40); //* Remove the node with value 40
    tree.inorder();
    tree.remove(5); //* Remove the node with value 5
    tree.inorder();
    tree.remove(30); //* Remove the node with value 30
    tree.inorder();

    cout << "size: " << tree.size() << endl; //* Print the number of nodes in the tree
    if (tree.isEmpty()) cout << "tree is empty" << endl; //* Check if the tree is empty
    else cout << "tree is not empty" << endl;

    //* Search for some values in the tree
    cout << "search 20: " << tree.search(20) << endl;
    cout << "search 1: " << tree.search(1) << endl;
    cout << "search 40: " << tree.search(40) << endl;
    cout << "search 5: " << tree.search(5) << endl;
    cout << "search 30: " << tree.search(30) << endl;

    return 0;
}
