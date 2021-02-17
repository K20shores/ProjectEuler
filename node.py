class Node:
    def __init__(self, value = None, edge = None):
        self.left = None
        self.right = None
        self.upper_left = None
        self.upper_right = None
        self.value = value
        self.edge = None
    
    def add_left_child(self, n):
        self.left = n

    def add_right_child(self, n):
        self.right = n

    def add_upper_left_parent(self, n):
        self.upper_left = n

    def add_upper_right_parent(self, n):
        self.upper_right = n