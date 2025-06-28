public class ShellSort {

    public static void main(String[] args) {
        int[] array={3,2,5,4,1};
        int i,j,k,temp,increment;
        int number_of_elements=array.length;

        for(increment=number_of_elements/2;increment>0;increment /=2)
        {
            for(i=increment;i<number_of_elements;i++)
            {
              temp=array[i];
              for(j=i;j>=increment;j-=increment)
              {
                if(temp<array[j-increment])
                {
                    array[j]=array[j-increment];
                }else
                {
                    break;
                }
            }
            array[j]=temp;
            }
        }

        System.out.println("After sorting");
        for(k=0;k<5;k++)
        {
            System.out.print(array[k]);
        }
    }
}