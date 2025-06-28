import java.util.ArrayList;

public class MyArray
{
  
    public static void main(String[] args) {
        ArrayList<Integer> real_array=new ArrayList<>();
        real_array.add(0);
        real_array.add(0);
        real_array.add(3);
        real_array.add(3);
        real_array.add(5);
        real_array.add(6);

        ArrayList <Integer> temp_arr=new ArrayList<>();
        for(int i=0;i<real_array.size();i++) 
        {
            for(int j=0;j<=temp_arr.size();j++)
            {
                if(real_array[i]!=temp_arr[j])
                {

                }
            }
        }
    }
}