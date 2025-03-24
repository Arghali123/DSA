public class QueueCode
{
    int front;
    int end;
    int queue[];
    QueueCode (int size)
    {
        this.queue=new int[size];
        this.front=0;
        this.end=0;
    }

    public void enQueue(int data)
    {
        if(end==queue.length)
        {
            System.out.println("Queue is full");
            return;
        }
        queue[end++]=data;
    }

    public int deQueue()
    {
        if(front>=end)
        {
            System.err.println("Queue is empty");
        }
        int data=queue[front++];
        return data;
    }

    void displayQueue()
    {
        for(int i=front;i<end;i++)
        {
            System.out.print(queue[i]+" ");
        }
    }

  public static void main(String[] args) {
    QueueCode a=new QueueCode(5);
    a.enQueue(1);
    a.enQueue(2);
    a.enQueue(3);
    a.enQueue(4);
    a.enQueue(5);
    a.displayQueue();

    System.out.println();
    System.out.println("Removed element1: "+a.deQueue());
    System.out.println("Removed element2: "+a.deQueue());
    System.out.println("Removed element3: "+a.deQueue());
    a.displayQueue();
    
  }
}