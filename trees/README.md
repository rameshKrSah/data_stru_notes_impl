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


## Binary Search Tree
- A binary search tree is a sorted or ordered binary trees, and it keeps its values in sorted order, so that lookup and othe operations can be performed in O(log(n)). The property of a binary search tree is that the left child value is less than the root node and the right child value is greater than that of root node.

### Insertion in Binary search trees
1 Is the new node value greater or smaller than the current node?

2 If the value of the new node is greater than the current node, go to the right subtree. If the current node doesn't have a right child, inser it there, or else go to step 1.

3 If the value of the new node is smaller than the current node, go to the left subtree. If the current node doesn't have a left child, insert it there, or else go to step 1.

### Search in Binary Search Trees
- First we have our root node. All the left subtree nodes will have smaller values than the root node. And all the right subtree nodes will have values greater than the root node.

1 Start from the root node. Is the given value smaller than the current node? If yes, then search for it in the left subtree.

2 Is the given value greater than the current node? If yes, then serach for it in the right subtree.

3 If both 1 and 2 is false, compare the given value with the current node. If they are equal, report that the tree has the given value, else the tree don't have it.

## Deletion or removing a node
Deletion is a more complex task in a BST because we need to handle differen case.

1 Case 1. If we want to remove a node with no child or a leaf node
	If the node we want to delete has no children, then we simply delete it. The tree does not needs to be modified in this case.

2 Case 2. If we want to remove a node with only one child left or right
	Here, the tree needs to be modified before deletion. If we are going to delete a current node with a parent node and a child node then, the parent node needs to point to the child node before the current node is deleted.

3 Case 3. If we want to remove a node with two child
	When the current node has two child, we can make the deletion in two possible ways. We either find the minimum value in the right subtree and replace the current node with it and then delete the current node or find the maximum value in the left subtree and replace the current node with and then delete the current node. Either of these cases will results in lesser balanced trees in the long run.



