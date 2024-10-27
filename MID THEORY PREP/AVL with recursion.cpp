#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

#define br cout<<endl; // Macro to print a newline

// Node structure for the AVL Tree
template <typename t>
struct AVLNode {
    t data; // Data stored in the node
    AVLNode<t>* l, *r; // Left and right child pointers
    int hight; // Height of the node for balancing

    // Constructor to initialize a node with a value
    AVLNode(t val) : data(val), l(nullptr), r(nullptr), hight(1) {}
};

// AVL Tree class template
template <typename t>
class AVLTree {
    private:
        AVLNode<t>* root; // Root node of the AVL Tree

        // Function to get the height of a node
        int getHeight(AVLNode<t>* temp) const {
            return temp ? temp->hight : 0;
        }

        // Function to get the balance factor of a node
        int getBalanceFactor(AVLNode<t>* temp) const {
            return temp ? getHeight(temp->l) - getHeight(temp->r) : 0;
        }

        // Function to update the height of a node
        void updateHight(AVLNode<t>* temp) {
            temp->hight = max(getHeight(temp->l), getHeight(temp->r)) + 1;
        }

        // Right rotation to balance the tree
        AVLNode<t>* rightRotate(AVLNode<t>* y) {
            AVLNode<t>* x = y->l;
            AVLNode<t>* t2 = x->r;

            // Perform rotation
            x->r = y;
            y->l = t2;

            // Update heights
            updateHight(y);
            updateHight(x);

            // Return new root
            return x;
        }

        // Left rotation to balance the tree
        AVLNode<t>* leftRotate(AVLNode<t>* x) {
            AVLNode<t>* y = x->r;
            AVLNode<t>* t2 = y->l;

            // Perform rotation
            y->l = x;
            x->r = t2;

            // Update heights
            updateHight(x);
            updateHight(y);

            // Return new root
            return y;
        }

        // Balances a node if needed based on its balance factor
        AVLNode<t>* balance(AVLNode<t>* temp) {
            int balFac = getBalanceFactor(temp);

            // Left heavy
            if (balFac > 1) {
                // Left-Right case
                if (getBalanceFactor(temp->l) < 0)temp->l = leftRotate(temp->l);
                // Left-Left case
                return rightRotate(temp);
            }
            // Right heavy
            else if (balFac < -1) {
                // Right-Left case
                if (getBalanceFactor(temp->r) > 0)temp->r = rightRotate(temp->r);
                // Right-Right case
                return leftRotate(temp);
            }
            // Node is balanced
            return temp;
        }

        // Function to insert a node into the AVL Tree
        AVLNode<t>* insertNode(AVLNode<t>* temp, t val) {
            // Perform regular BST insertion
            if (!temp) return new AVLNode<t>(val);

            if (val < temp->data)temp->l = insertNode(temp->l, val);
            else if (val > temp->data) temp->r = insertNode(temp->r, val);
            else {
                cerr << "Duplicate value in AVL tree" << endl;
                return temp; // No duplicate values are allowed
            }

            // Update the height of the current node
            updateHight(temp);

            // Balance the tree
            return balance(temp);
        }

        // Function to find the node with the minimum value
        AVLNode<t>* findMin(AVLNode<t>* temp) const {
            while (temp->l) temp = temp->l;
            return temp;
        }

        // Function to delete a node from the AVL Tree
        AVLNode<t>* deleteNode(AVLNode<t>* temp, t val) {
            if (!temp) return temp;

            // Perform regular BST delete
            if (val < temp->data)temp->l = deleteNode(temp->l, val);
            else if (val > temp->data)temp->r = deleteNode(temp->r, val);
            else {
                // Node with only one child or no child
                if (!temp->l || !temp->r) {
                    AVLNode<t>* temp2 = temp->l ? temp->l : temp->r;
                    delete temp;
                    return temp2;
                }
                // Node with two children: get the inorder successor
                AVLNode<t>* temp2 = findMin(temp->r);
                temp->data = temp2->data;
                temp->r = deleteNode(temp->r, temp2->data);
            }

            // Update height of the current node
            updateHight(temp);

            // Balance the tree
            return balance(temp);
        }

        // Function to search for a value in the AVL Tree
        bool searchNode(AVLNode<t>* temp, t val) const {
            if (!temp) return false;
            if (val == temp->data) return true;
            if (val < temp->data) return searchNode(temp->l, val);
            return searchNode(temp->r, val);
        }

        // Function for in-order traversal of the tree
        void inorderTraversal(AVLNode<t>* temp) const {
            if (temp) {
                inorderTraversal(temp->l);
                cout << temp->data << " ";
                inorderTraversal(temp->r);
            }
        }

        // Function to clear the tree
        void clear(AVLNode<t>* temp) {
            if (temp) {
                clear(temp->l);
                clear(temp->r);
                delete temp;
            }
        }

    public:
        AVLTree() : root(nullptr) {} // Constructor
        ~AVLTree() {
            clear(root); // Destructor to delete all nodes
        }

        // Public function to insert a value
        void insert(t val) {
            root = insertNode(root, val);
        }

        // Public function to remove a value
        void remove(t val) {
            root = deleteNode(root, val);
        }

        // Public function to search for a value
        bool search(t val) const {
            return searchNode(root, val);
        }

        // Public function to perform in-order traversal
        void inorder() const {
            inorderTraversal(root);br;
        }

        // Public function to check if the tree is empty
        bool isEmpty() const {
            return root == nullptr;
        }
};

int main() {
    srand(time(0));
    AVLTree<int> tree;
    // Insert random values into the AVL Tree
    for (int i = 0; i < 30; i++) tree.insert(rand() % 200 + 1);
    tree.inorder();

    // Insert specific values
    tree.insert(100);
    tree.insert(50);
    tree.insert(150);
    tree.insert(25);
    tree.insert(75);

    // In-order traversal after insertions
    tree.inorder();

    // Remove values from the AVL Tree
    tree.remove(100);
    tree.inorder();
    cout << "Search 100: " << tree.search(100) << endl;
    cout << "Search 150: " << tree.search(150) << endl;
    cout << "Is Empty: " << tree.isEmpty() << endl;

    return 0;
}