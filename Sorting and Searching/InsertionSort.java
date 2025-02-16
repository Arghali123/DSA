public class InsertionSort {
    public static void main(String[] args) {
        int[] numbers={32,10,22,21,30,16,8,50};
        int size=numbers.length;

        System.out.print("Before sorting: ");
        for(int i=0;i<size;i++)
        {
            System.out.print(numbers[i]+" ");
        }
        System.out.println();
        
        for(int i=1;i<size;i++)
        {
            int key=numbers[i];
            int j = i - 1; // Declare j and initialize
            while(j>=0 && numbers[j]>key)
            {
              numbers[j+1]=numbers[j];
              j--;
            }
            numbers[j+1]=key;
        }

        System.out.print("After sorting: ");
        for(int i=0;i<size;i++)
        {
            System.out.print(numbers[i]+" ");
        }
    }
}
