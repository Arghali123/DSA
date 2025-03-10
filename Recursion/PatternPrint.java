/*
 Print the following pattern
 *
 * *
 * * *
 * * * * 
 * * * * *
 * * * * * *
 * * * * * * *
 */
public class PatternPrint {
    
   static void Traingle(int n)
    {
        if(n<=0)
        {
            return;
        }
        else
        {
            Traingle(n-1);
            for(int i=1;i<=n;i++)
            {
                System.out.print("*\t");
            }
            System.out.println();
        }
    }
    public static void main(String[] args) {
       Traingle(7); 
    }
}
