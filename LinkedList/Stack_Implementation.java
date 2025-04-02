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

class Stack
{
    Node head;

    Stack()
    {
     this.head=null;
    }

    boolean isEmpty()
    {
        return head==null;//If head is null,the stack is empty
    }

    void push(int new_data)
    {
        Node new_Node=new Node(new_data);
      
        // if(new_Node==null)
        // {
        //     System.out.println("\nStack Overflow");
        //     return;
        // }

        new_Node.next=head;
        head=new_Node;
    }

    void pop()
    {
        if(isEmpty())
        {
            System.out.println("Stack underflow");
            return;
        }else
        {
            Node temp=head;
            head=head.next;
            temp=null;
        }
    }

    //Function to return the top element of the stack
    int peek()
    {
      if(!isEmpty())
      {
        return head.data;
      }else
      {
        System.out.println("Stack is empty");
        return Integer.MIN_VALUE;
      }
    }
   
}

public class Stack_Implementation {
    public static void main(String[] args) {
        Stack st=new Stack();

        st.push(1);
        st.push(2);
        st.push(3);
        st.push(4);

        System.out.println("Top element is: "+st.peek());

        System.out.println("Removing top element...");
        st.pop();

        System.out.println("Top element is: "+st.peek());

    }
}
