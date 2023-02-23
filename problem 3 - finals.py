class Node: 
    
    def __init__(self, name): 
        self.name = name 
        self.next = None

class MyLinkedList: 

    def __init__(self): 
        self.head = None

    def make_null(self): 
        self.head = None

    def insert_sorted(self, name): 
        new_node = Node(name) 
        current = self.head
    
    if not self.head or self.head.name >= new_node.name: 
        new_node.next = self.head 
        self.head = new_node 

    else:
        while current.next and current.next.name < new_node.name: 
            current = current.next 
        new_node.next = current.next 
        current.next = new_node

    def remove(self, name): 
        current = self.head 
        prev = None

        while current and current.name != name:
            prev = current 
            current = current.next
        if not current: 
            print("Record not found") 
        elif not prev: 
            self.head = current.next 
        else: 
            prev.next = current.next

    def display(self): 
        current = self.head 
        print("NAME:") 
        i = 1 
        while current: 
            print(f"{i}. {current.name}") 
            current = current.next 
            i += 1
    
if __name__ == '__main__':

    linked_list = MyLinkedList() 
    linked_list.make_null() 
    choice = 0

    while choice != 4: 
        print("(1) Insert\n(2) Remove\n(3) Display\n(4) Exit\n") 
        choice = int(input("Enter a choice: "))

        if choice == 1: 
            name = input("Input name: ") 
            linked_list.insert_sorted(name) 
        elif choice == 2: 
            name = input("Input name: ") 
            linked_list.remove(name) 
        elif choice == 3: 
            linked_list.display() 
        elif choice == 4: 
            break 
        else: print("Please select from 1 to 4")