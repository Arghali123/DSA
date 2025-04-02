class Node
{
    int data;
    Node next;

    Node(int new_data)
    {
        this.data=new_data;
        this.next=null;
    }
}

class Queue
{
   private Node front;
   private Node rear;
   public Queue() 
   {
    front=rear=null;
   }

   public boolean isEmpty()
   {
    return front==null;
   }

   public void enqueue(int new_data)
   {
    Node new_Node=new Node(new_data);
    if(isEmpty())
    {
        front=rear=new_Node;
        printQueue();
        return;
    }
    rear.next=new_Node;
    rear=new_Node;
    printQueue();
   }

   public void dequeue()
   {
    if(isEmpty())
    {
        return;
    }
    Node temp=front;
    front=front.next;
    if(front==null)
    {
        rear=null;
    }
    printQueue();
   }

   public void printQueue()
    {
    if (isEmpty()) {
        System.out.println("Queue is empty");
        return;
    }
    Node temp = front;
    System.out.print("Current Queue: ");
    while (temp != null) {
        System.out.print(temp.data + " ");
        temp = temp.next;
    }
    System.out.println();
}
}
public class Queue_Implementation {
    public static void main(String[] args) {
        Queue q=new Queue();

        q.enqueue(10);
        q.enqueue(20);

        q.dequeue();
        q.dequeue();

        q.enqueue(30);
        q.enqueue(40);
        q.enqueue(50);

        q.dequeue();
    }
}
