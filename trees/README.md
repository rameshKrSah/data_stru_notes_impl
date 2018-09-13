# Trees and it's elements

-A tree is a collection of entities called nodes. Nodes are connected by edges. Each node contains a value or data, and it may or may not have a child node.

-The first node of the tree is called the root. If the root is connected by another node, then the root is the parent node of the connected node and the connected node is the child of root.

- Leaves are the last nodes on a tree. They are nodes without children.

- The height of a tree is the length of the longest path to a leaf. The depth of a node is the length of the path to its root.

## Binary Trees

- A binary tree is a tree data structure in which each node has at the most two children, which are referred to as the left child and the right child.

### Insertion in left in Binary tree

- If the current node doesn't have a left child, just create a new node and set it as the left child of the current node.

- If the current node has a left child, create a new node and make it the current node left child and make the current left child the left child of the new node

### Insertion in right in Binary tree

- If the current node doesn't have a right child, create a new node and set it as the right child of the current node.

- If the current node has a right child, create a new node and make this the right child of the current node and make the current right child the right child of the new node.

### Tree traversal

There are two options for tree traversal: Depth-First Search (DFS) and Breadth-First Search (BFS)

- DFS is an algorithm for traversing or searching tree data structures. One starts at the root and explores as far as possible along each branch before backtracking.

- BFS is an algorithm for traversing or searching tree data structure. It starts at the tree root and explores the neighbor nodes first, before moving to the next level neighbors.

BFS traverses the tree level by level and depth by depth.

DFS explores a path all the way to a leaf before backtracking and exploring another path. There are three types of DFS: 
	1 Pre-order
	2 Post-order
	3 In-order

### Pre-order DFS traversal

- Print the value of the node

- Go to the left child and print it. This is if, and only if, it has a left child.

- Go to the right child and print it. This is if, and only if, it has a right child.

### In-order DFS traversal

- Go to the left child and print it. This is if, and only if, it has a left child.

- Print the node's value

- Go to the right child and print it. This is if, and only if, it has a right child.

### Post-order DFS traversal

- Go to the left child and print it. This is if, and only if, it has a left child.

- Go to the right child and print it. This is if, and only if, it has a right child.

- Print the node's value 


