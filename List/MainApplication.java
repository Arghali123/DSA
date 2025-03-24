
class Node {
	int data;
	Node next;

	public Node(int data) {
		this.data = data;
	}
}

class LinkedList {
	// Null
	Node head;

	public void insertAtLast(int data) {
		Node nextNode = new Node(data);

		if (head == null) {
			head = nextNode;
			return;
		}

		Node temp = head;

		while (temp.next != null) {
			temp = temp.next;
		}
		temp.next = nextNode;
	}

	public void print() {
		Node temp = head;
		if (head == null) {
			System.out.println("No element on Linked List");
			return;
		}

		while (temp != null) {
			System.out.print(temp.data + "-->");
			temp = temp.next;

		}

	}

}

public class MainApplication {

	public static void main(String[] args) {
		LinkedList linkedList = new LinkedList();
		linkedList.print();
		
		linkedList.insertAtLast(1);
	    linkedList.insertAtLast(2);
        linkedList.insertAtLast(3);
		linkedList.insertAtLast(4);
		System.out.println("Print after insertion");
		linkedList.print();

	}

}
