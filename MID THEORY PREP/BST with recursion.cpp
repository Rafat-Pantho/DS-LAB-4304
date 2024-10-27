#include <iostream>

using namespace std;

#define br cout << endl; // Macro to print a newline

// Template for the BST Node
template <typename trex>
struct BSTNode {
    trex data;             // Data stored in the node
    BSTNode *left, *right; // Pointers to the left and right child nodes

    // Constructor to initialize a node with a value
    BSTNode(trex val) : data(val), left(nullptr), right(nullptr) {}

    // Destructor (currently empty, can be used for custom cleanup if needed)
    ~BSTNode() {}
};

// Template for the BST class
template <typename trex>
class BST {
    private:
        BSTNode<trex> *root; // Pointer to the root of the BST

        // Helper function to insert a value into the BST (recursive approach)
        BSTNode<trex>* insert(BSTNode<trex> *temp, trex val) {
            if (!temp) return new BSTNode<trex>(val); // If the node is null, create a new node
            if (val < temp->data) temp->left = insert(temp->left, val); // If the value is smaller, go left
            else if (val > temp->data) temp->right = insert(temp->right, val); // If the value is larger, go right
            return temp; // Return the unchanged node pointer
        }

        // Helper function to search for a value in the BST (recursive approach)
        bool search(BSTNode<trex> *temp, trex val) const {
            if (!temp) return false; // If node is null, value not found
            if (val == temp->data) return true; // If the value matches, return true
            if (val < temp->data) return search(temp->left, val); // If the value is smaller, search left
            return search(temp->right, val); // If the value is larger, search right
        }

        // Helper function to find the node with the minimum value in the BST
        BSTNode<trex>* findMin(BSTNode<trex> *temp) const {
            while (temp->left) temp = temp->left; // Keep going left until the leftmost node is reached
            return temp; // Return the leftmost node
        }

        // Helper function to remove a value from the BST (recursive approach)
        BSTNode<trex>* remove(BSTNode<trex> *temp, trex find) {
            if (!temp) return nullptr; // If node is null, nothing to remove
            if (find < temp->data) temp->left = remove(temp->left, find); // If the value is smaller, go left
            else if (find > temp->data) temp->right = remove(temp->right, find); // If the value is larger, go right
            else {
                // Node with the value found
                if (!temp->left) {
                    // Case 1: Node has no left child
                    BSTNode<trex> *temp2 = temp->right; // Store right child
                    delete temp; // Delete current node
                    return temp2; // Return right child
                }
                else if (!temp->right) {
                    // Case 2: Node has no right child
                    BSTNode<trex> *temp2 = temp->left; // Store left child
                    delete temp; // Delete current node
                    return temp2; // Return left child
                }
                // Case 3: Node has two children
                BSTNode<trex> *temp2 = findMin(temp->right); // Find the minimum node in the right subtree
                temp->data = temp2->data; // Replace the current node's data with the minimum node's data
                temp->right = remove(temp->right, temp2->data); // Remove the minimum node from the right subtree
            }
            return temp; // Return the modified node pointer
        }

        // Helper function for inorder traversal (left, root, right)
        void inorderTraversal(BSTNode<trex> *temp) const {
            if (temp) {
                inorderTraversal(temp->left); // Traverse left subtree
                cout << temp->data << " ";    // Visit the current node
                inorderTraversal(temp->right); // Traverse right subtree
            }
        }

        // Helper function to clear the BST and free memory (postorder traversal)
        void clear(BSTNode<trex> *temp) {
            if (temp) {
                clear(temp->left); // Clear left subtree
                clear(temp->right); // Clear right subtree
                delete temp; // Delete current node
            }
        }

    public:
        // Constructor to initialize an empty BST
        BST() : root(nullptr) {}

        // Destructor to clear the BST
        ~BST() {
            clear(root); // Free all memory used by the BST
        }

        // Public function to insert a value into the BST
        void Insert(trex val) {
            root = insert(root, val); // Call the helper function
        }

        // Public function to search for a value in the BST
        bool Search(trex v) const {
            return search(root, v); // Call the helper function
        }

        // Public function to remove a value from the BST
        void Remove(trex val) {
            root = remove(root, val); // Call the helper function
        }

        // Public function to perform inorder traversal of the BST
        void inorder() const {
            inorderTraversal(root); // Call the helper function
            br; // Print a newline
        }
};

int main() {
    BST<int> tree; // Create a BST for integers
    tree.Insert(5);
    tree.Insert(3);
    tree.Insert(4);
    tree.Insert(2);
    tree.Insert(1);

    tree.inorder(); // Print the BST in inorder

    tree.Remove(3); // Remove the value 3
    tree.inorder(); // Print the BST in inorder after removal

    cout << tree.Search(4) << endl; // Search for the value 4, should output 1 (true)
    cout << tree.Search(6) << endl; // Search for the value 6, should output 0 (false)

    tree.Remove(1); // Remove the value 1
    tree.inorder(); // Print the BST in inorder after removal

    return 0;
}
