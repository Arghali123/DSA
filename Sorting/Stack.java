
public class Stack {
    static int[] stack = new int[3];
    static int top = -1;
    static int size = stack.length;

    static public Boolean isFull()
    {
        if(top>=size-1)
        {
            return true;
        }
        return false;
    }

    static Boolean isEmpty()
    {
        if(top<=-1)
        {
            return true;
        }
        return false;
    }

    static void push(int number) {
        // if (top >= size - 1) {
        //     System.out.println("Stack is full");
        //     return;
        // }

        if(isFull())
        {
            System.out.println("Stack is full"); 
        }
        top++;
        stack[top] = number;
    }

    static int pop()
    {
        // if(top==-1)
        // {
        //     System.out.println("Stack is empty");
        //     return 0;
        // }

        if(isEmpty())
        {
            System.out.println("Stack is empty");
        }
        int value=stack[top];
        top--;
        return value;
    }

    static void printStack() {
        int i = top;
        while (i >= 0) {
           System.out.println(stack[i]);
           i--;
        }
    }

    // Main function
    public static void main(String[] args) {
        push(1);
        push(2);
        push(3);
        printStack();
        

        pop();
        pop();
        pop();
        pop();
        //int  poppedValue=pop();
        //System.out.println("Popped value: "+poppedValue);
        printStack();
    }
}
