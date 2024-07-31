""" Creating an empty linlked List """

class Node:
    """ An object for storing a single node of a linked list.
    Models two attributes - data and the link to the next node in the list.
    """
    data = None
    next_node = None

    def __init__(self, data):
        self.data = data

    def __repr__(self):
        return "<Node data: %s>" % self.data
    
    class LinkedList:
        """singly linked list"""
        def __intit__(self):
            self.head = None

        def is_empty(self):
            return self.head == None
        
        def size(self):
            current = self.head
            count = 0

            while current:
                count += 1
                current = current.next_node

            return current
        
    def add(self, data):
        """ 
        Adds new nodes containing data at the head of the list.
        Takes 0(1) - constant time
        """
        new_node = Node(data)
        new_node.next_node = self.head
        self.head = new_node

    def search(self, key):
        """
        Search for the first node that contains the data that matches the key. 
        Returns the Node or None. Take O(n) or constant time.
        """
        current = self.head

        while current:
            if current.data == key:
                return current
            else:
                current = current.next_node
            return None
        

    def __repr__(self):
        """
        Take a string representation of the list.
        Takes 0(1) - constant time
        """
        nodes = []
        current = self.head

        while current:
            if current is self.head:
                nodes.append("[Head: %s]" % current.data)
            elif current is None:
                nodes.append("[Tail: %s]" % current.data)
            else:
                nodes.append("[%s]" % current.data)
            
            current = current.next_node
        return '->' .join(nodes)