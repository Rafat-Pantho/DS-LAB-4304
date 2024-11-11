class Node:
    def __init__(self, data):
        self.data = data
        self.height = 0
        self.left = None
        self.right = None
        self.parent = None

class AVLTree:
    def __init__(self):
        self.root = None

    def get_height(self, node):
        return node.height if node else 0

    def balance_factor(self, node):
        return self.get_height(node.left) - self.get_height(node.right)

    def update_height(self, node):
        while node:
            node.height = max(self.get_height(node.left), self.get_height(node.right)) + 1
            node = node.parent

    def left_rotate(self, x):
        y = x.right
        x.right = y.left
        if y.left:y.left.parent = x
        y.parent = x.parent
        if not y.parent:self.root = y
        elif x == x.parent.left:x.parent.left = y
        else:x.parent.right = y
        y.left = x
        x.parent = y
        self.update_height(x)
        self.update_height(y)

    def right_rotate(self, y):
        x = y.left
        y.left = x.right
        if x.right:x.right.parent = y
        x.parent = y.parent
        if not x.parent:self.root = x
        elif y == y.parent.left:y.parent.left = x
        else: y.parent.right = x
        x.right = y
        y.parent = x
        self.update_height(y)
        self.update_height(x)

    def balance(self, node):
        was_balanced = True
        while node:
            self.update_height(node)
            bf = self.balance_factor(node)
            if bf > 1:
                was_balanced = False
                if self.balance_factor(node.left) < 0:
                    print(f"Imbalance at node: {node.data}\nLR case")
                    self.left_rotate(node.left)
                else:print(f"Imbalance at node: {node.data}\nLL case")
                self.right_rotate(node)
            elif bf < -1:
                was_balanced = False
                if self.balance_factor(node.right) > 0:
                    print(f"Imbalance at node: {node.data}\nRL case")
                    self.right_rotate(node.right)
                else:print(f"Imbalance at node: {node.data}\nRR case")
                self.left_rotate(node)
            node = node.parent
        return was_balanced

    def insert(self, data):
        if not self.root:
            self.root = Node(data)
            self.print_tree()
            print("Balanced")
            print(f"Root={self.root.data}")
            return

        temp = self.root
        container = Node(data)
        parent = None

        while temp:
            parent = temp
            if data < temp.data:temp = temp.left
            elif data > temp.data:temp = temp.right
            else:
                print("Data already exists")
                return

        container.parent = parent
        if data < parent.data:parent.left = container
        else:parent.right = container

        self.update_height(container)
        self.print_tree()

        was_balanced = self.balance(parent)
        if was_balanced:
            print("Balanced")
            print(f"Root={self.root.data}")
        else:
            print("status:")
            self.print_tree()
            print(f"Root={self.root.data}")

    def inorder(self, node):
        if node:
            self.inorder(node.left)
            print(f"{node.data}({self.balance_factor(node)})", end=" ")
            self.inorder(node.right)

    def find_min(self, node):
        while node.left:node = node.left
        return node

    def delete_node(self, node):
        if not node:return

        parent = node.parent

        if not node.left and not node.right:
            if node == self.root:self.root = None
            elif parent.left == node:parent.left = None
            else:parent.right = None
            del node
        elif node.left and node.right:
            successor = self.find_min(node.right)
            par=successor.parent
            node.data = successor.data
            if successor.parent.left == successor:successor.parent.left = successor.right
            else:successor.parent.right = successor.right
            if successor.right:successor.right.parent = successor.parent
            del successor
            self.update_height(par)
        else:
            child = node.left if node.left else node.right
            child.parent = parent
            if node == self.root:self.root = child
            elif parent.left == node:parent.left = child
            else:parent.right = child
            del node
        
        self.print_tree()

        if parent:
            self.update_height(parent)
            was_balanced = self.balance(parent)
            if was_balanced:print(f"Balanced\nRoot={self.root.data}")
            else:self.print_tree()

    def delete_key(self, data):
        temp = self.root
        while temp and temp.data != data:temp = temp.left if data < temp.data else temp.right
        if temp:self.delete_node(temp)
        else:print("Data not found")

    def print_tree(self):
        self.inorder(self.root)
        print()

if __name__ == "__main__":
    avl_tree = AVLTree()
    while True:
        val = input()
        if val == "-1":break
        if val[0] in "Dd":
            val=val.split()
            avl_tree.delete_key(int(val[1]))
        else:avl_tree.insert(int(val))

    print("Status:",end=" ")
    avl_tree.print_tree()
