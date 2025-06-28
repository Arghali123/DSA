import java.util.Scanner;

class TOHSimulation
{
    void TOH(int n,char A,char B,char C)
    {
        if(n>0)
        {
            TOH(n-1, A, C, B);
            System.out.println("Move disk "+n+" from "+A+" to "+B);
            TOH(n-1, C, B, A);
        }
    }
}

public class TOHDemo {
    public static void main(String[] args) {
     int n;
     Scanner sc=new Scanner(System.in);
     TOHSimulation t=new TOHSimulation();
     System.out.println("Enter the number of disk");
     n=sc.nextInt();
     t.TOH(n, 'O', 'D', 'I');
     sc.close();
    }
}
