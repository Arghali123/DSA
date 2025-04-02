class Node {
    int data;
    Node next;
    Node prev;

    public Node(int data) {
        this.data = data;
        this.next = null;
        this.prev = null;
    }
}

public class DoublyLinkedList {
    private Node head;

    public void insertAtBeginning(int data) {
        Node newNode = new Node(data);
        newNode.next = head;
        if (head != null) {
            head.prev = newNode;
        }
        head = newNode;
    }

    public void insertAtLast(int data) {
        Node newNode = new Node(data);
        if (head == null) {
            head = newNode;
            return;
        }
        Node last = head;
        while (last.next != null) {
            last = last.next;
        }
        last.next = newNode;
        newNode.prev = last;
    }

    public void insertAtPosition(int pos, int new_data) {
        if (pos < 1) {
            System.out.println("Invalid position.");
            return;
        }
        
        Node new_node = new Node(new_data);
    
        // Insertion at the beginning
        if (pos == 1) {
            new_node.next = head;
            if (head != null) {
                head.prev = new_node;
            }
            head = new_node;
            return;
        }
    
        Node curr = head;
        for (int i = 1; i < pos - 1 && curr != null; i++) {  // Changed ++i to i++
            curr = curr.next;
        }
    
        if (curr == null) {
            System.out.println("Position is out of bounds.");
            return;
        }
    
        new_node.next = curr.next;
        new_node.prev = curr;
    
        if (curr.next != null) {
            curr.next.prev = new_node;
        }
        
        curr.next = new_node;
    }
    

    public void deleteAtBeginning() {
        if (head == null) {
            System.out.println("List is empty");
            return;
        }
        if (head.next != null) {
            head.next.prev = null;
        }
        head = head.next;
    }

    public void deleteAtEnd() {
        if (head == null) {
            System.out.println("List is empty");
            return;
        }
        if (head.next == null) {
            head = null;
            return;
        }
        Node last = head;
        while (last.next != null) {
            last = last.next;
        }
        last.prev.next = null;
    }

    public void deleteSpecificNode(int position) {
        if (head == null) {
            System.out.println("List is empty");
            return;
        }
        Node temp = head;
        if (position == 0) 
        {
            head = temp.next;
            if (temp.next != null) 
            {
                temp.next.prev = null;
            }
            return;
        }
        for (int i = 0; temp != null && i < position; i++) {
            temp = temp.next;
        }
        if (temp == null) {
            System.out.println("Position does not exist");
            return;
        }
        if (temp.next != null) {
            temp.next.prev = temp.prev;
        }
        if (temp.prev != null) {
            temp.prev.next = temp.next;
        }
    }

    public void printList() {
        Node temp = head;
        while (temp != null) {
            System.out.print(temp.data + " ");
            temp = temp.next;
        }
        System.out.println();
    }

    public static void main(String[] args) {
        DoublyLinkedList list = new DoublyLinkedList();
        list.insertAtBeginning(1);
        list.insertAtLast(2);
        list.insertAtLast(3);
        list.insertAtBeginning(0);
        list.insertAtPosition(1, 10);

        list.printList();
        
        list.deleteAtBeginning();
        list.printList();

        list.deleteAtEnd();
        list.printList();

        list.deleteSpecificNode(1);
        list.printList();
    }
}
