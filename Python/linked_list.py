class Node:
    """An object for storing a single node of a linked list.
    Models two attributes - data and the link to the next node in the list.
    """
    def __init__(self, data):
        self.data = data
        self.next_node = None

    def __repr__(self):
        return "<Node data: %s>" % self.data
    
class LinkedList:
    """Singly linked list"""
    def __init__(self):
        self.head = None

    def is_empty(self):
        return self.head is None
        
    def size(self):
        current = self.head
        count = 0

        while current:
            count += 1
            current = current.next_node

        return count
        
    def add(self, data):
        """ 
        Adds new nodes containing data at the head of the list.
        Takes O(1) - constant time
        """
        new_node = Node(data)
        new_node.next_node = self.head
        self.head = new_node

    def search(self, key):
        """
        Search for the first node that contains the data that matches the key. 
        Returns the Node or None. Takes O(n) linear time.
        """
        current = self.head

        while current:
            if current.data == key:
                return current
            else:
                current = current.next_node
        return None
    
    def insert(self, data, index):
        if index == 0:
            self.add(data)
        elif index > 0:
            """
            Inserts a new node containing data at index position. Insertion takes O(1) constant time but 
            finding node at insert position takes O(n) linear time.
            """
            new_node = Node(data)
            position = index
            current = self.head

            while position > 1 and current:
                current = current.next_node
                position -= 1

            if current is None:
                raise IndexError("Index out of bounds")

            prev_node = current
            next_node = current.next_node

            prev_node.next_node = new_node
            new_node.next_node = next_node

    def remove(self,key):
        current = self.head
        previous = None
        found = False
        """
        Removes node containig data that matches key. Returns node or None if key doesn't exist.
        Takes 0(n) linear time.
        """

        while current and not Found:
            if current_data == key and current is self.head:
                found = True
                self.head = current.next_node
            elif current.data == key:
                found = True
                previous.next_node = current.next_node
            else:
                previous = current
                current = current.next_node
            return current
    


    def __repr__(self):
        """
        Takes a string representation of the list.
        Takes O(n) linear time.
        """
        nodes = []
        current = self.head

        while current:
            if current is self.head:
                nodes.append("[Head: %s]" % current.data)
            elif current.next_node is None:
                nodes.append("[Tail: %s]" % current.data)
            else:
                nodes.append("[%s]" % current.data)
            
            current = current.next_node
        return '->'.join(nodes)