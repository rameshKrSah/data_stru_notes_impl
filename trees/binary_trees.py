# -*- coding: utf-8 -*-
"""

Binary tree 

"""

from queue import Queue

#Binary calss declaration 
class BinaryTree:
    def __init__(self, value):
        self.value = value
        self.left_child = None
        self.right_child = None
        
    """ 
    Insetion in the left     
    """
    def insert_in_left(self, value):
        new_node = BinaryTree(value)
    
        if self.left_child == None:
           self.left_child = new_node
        
        else:
             new_node.left_child = self.left_child;
             self.left_node = new_node;
             
    """
    Insertion in the right 
    """
    def insert_in_right(self, value):
        new_node = BinaryTree(value)
        
        if self.right_child == None:
            self.right_child = new_node
        else:
            new_node.right_child = self.right_child
            self.right_child = new_node

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
            
    
#Create a binary tree
tree = BinaryTree(10)

        
# Testing 
root = tree
root.insert_in_left(8)
root.insert_in_right(32)

print("Our Tree ")
print(root.value)
print(root.left_child.value)
print(root.right_child.value)

left = root.left_child
left.insert_in_left(7)

right = root.right_child
right.insert_in_left(12)
right.insert_in_right(64)

print(root.left_child.left_child.value)
print(root.right_child.left_child.value)
print(root.right_child.right_child.value)

"""
            |10|
            / \
        |8|   |32|
        /      / \
      |7|    |12| |64|
      
    The above created tree.
    
"""

# Pre-order DFS traversal
print("Pre-order DFS ")
root.pre_order()

# In-order DFS traversal
print("In-order DFS")
root.in_order()

# Post-order traversal
print("Post-order DFS")
root.post_order()

# BFS traversal
print("BFS traversal")
root.breadth_first_search()

























