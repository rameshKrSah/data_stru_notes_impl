# -*- coding: utf-8 -*-
"""
Created on Thu Sep 13 22:04:01 2018

@author: rames

Binary Search Trees

"""
import queue as Queue

class BinarySearchTree:
    def __init__(self, value):
        self.value = value
        self.left_child = None
        self.right_child = None
        
    """
    Insertion in Binary Search Tree
    """
    def insert_node(self, value):
        if value <= self.value and self.left_child:
            self.left_child.insert_node(value)
        elif value <= self.value:
            self.left_child = BinarySearchTree(value)
        elif value > self.value and self.right_child:
            self.right_child.insert_node(value)
        else:
            self.right_child = BinarySearchTree(value)
            
    """
    Search in Binary search tree
    """
    def search(self, value):
        if value < self.value and self.left_child:
            return self.left_child.search(value)
        elif value > self.value and self.right_child:
            return self.right_child.search(value)
        else:
            return value == self.value
    
    """
    Deletion in Binary Search Tree 
    """
    def delete(self, value, parent):
        if value < self.value and self.left_child:
            return self.left_child.delete(value, self)
        elif value < self.value:
            return False
        elif value > self.value and self.right_child:
            return self.right_child.delete(value, self)
        elif value > self.value:
            return False
        else:
            if self.left_child is None and self.right_child is None and self == parent.left_child:
                parent.left_child = None
                self.clear_node()
            elif self.left_child is None and self.right_child is None and self == parent.right_child:
                parent.right_child = None
                self.clear_node()
            elif self.left_child and self.right_child is None and self == parent.left_child:
                parent.left_child = self.left_child
                self.clear_node()
            elif self.left_child and self.right_child is None and self == parent.right_child:
                parent.right_child = self.left_child
                self.clear_node()
            elif self.left_child is None and self.right_child and self == parent.left_child:
                parent.left_child = self.right_child
                self.clear_node()
            elif self.left_child is None and self.right_child and self == parent.right_child:
                parent.right_child = self.right_child
                self.clear_node()
            else:
                self.value = self.right_child.find_minimum()
                self.right_child.remove_node(self.value, self)
            
            return True
    
    """
    Clear a node values
    """
    def clear_node(self):
        self.value = None
        self.left_child = None
        self.right_child = None
        
    """
    Find the minimum in a tree 
    """
    def find_minimum(self):
        if self.left_child:
            return self.left_child.find_minimum()
        else:
            return self.value
    
        """
    Pre-order DFS traversal 
    """
    def pre_order(self):
        print(self.value)
        
        if self.left_child:
            self.left_child.pre_order()
            
        if self.right_child:
            self.right_child.pre_order()
    
    """
    In-order DFS traversal
    """
    def in_order(self):
        if self.left_child:
            self.left_child.in_order()
            
        print(self.value)
        
        if self.right_child:
            self.right_child.in_order()
    
    """
    Post-order DFS traversal
    """
    def post_order(self):
        if self.left_child:
            self.left_child.post_order()
            
        if self.right_child:
            self.right_child.post_order()
            
        print(self.value)
    
    """
    BFS Traversal : Using queue 
    """
    def breadth_first_search(self):
        q = Queue()
        q.put(self)
        
        while not q.empty():
            cur_node = q.get()
            print(cur_node.value)
            
            if cur_node.left_child:
                q.put(cur_node.left_child)
            
            if cur_node.right_child:
                q.put(cur_node.right_child)
                    
        
"""
Testing 
"""
# create the root node 
bst = BinarySearchTree(15)

# insert more nodes
bst.insert_node(10)
bst.insert_node(8)
bst.insert_node(12)
bst.insert_node(21)
bst.insert_node(17)
bst.insert_node(19)
bst.insert_node(5)
bst.insert_node(9)

# search for some node
print(bst.search(0))
print(bst.search(23))
print(bst.search(19))
print(bst.search(10))
print(bst.search(88))
print(bst.search(21))

# find the minimum in the tree
print(bst.find_minimum())

# Remove the minimum and then find the minimum
print(bst.delete(bst.find_minimum(), None))

# find the minimum in the tree
print(bst.find_minimum())

# Traversal
print("Pre-order:")
bst.pre_order();

print("In-order:")
bst.in_order();

print("Post-order:")
bst.post_order();
