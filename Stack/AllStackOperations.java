public class AllStackOperations {
    int[] stack=new int[5];
    int top=-1;
    int size=stack.length;

    public void push(int data)
    {
        if(top>=size)
        {
            System.out.println("Stack is full!");
            return;
        }
        top++;
        stack[top]=data;
        System.out.println("Successfully pushed data into the stack!!");   
    }

    public int pop()
    {
        if(top==-1)
        {
            System.out.println("Stack is empty!");
            return 0;
        }
         int poped_data=stack[top];
         top--;
         return poped_data;
    }

    public int getMin()
    {
        int min=stack[0];
        for(int i=1;i<=top;i++)
        {
            if(min>stack[i])
            {
                min=stack[i];
            }
        }
        return min;
    }

    public int getMax()
    {
        int max=stack[0];
        for(int i=1;i<=top;i++)
        {
            if(max<stack[i])
            {
                max=stack[i];
            }
        }
        return max;
    }

    public void printStack()
    {
      int i=top;
      while (i>=0) {
        System.out.print(stack[i]+" ");
        i--;
      }
      System.out.println();
    }
public static void main(String[] args) {
  
 AllStackOperations st=new AllStackOperations();
    st.push(7);
    st.push(8);
    st.push(3);
    st.push(123);
    st.push(41);
    //st.push(22);
     st.printStack();
    
     //pop
     System.out.println("Popped data: "+st.pop());
     System.out.println("Popped data: "+st.pop());
     st.printStack();

     //min number int the stack
     System.out.println("Min value in the stack is: "+st.getMin());
     System.out.println("Max value in the stack is: "+st.getMax());
}
}