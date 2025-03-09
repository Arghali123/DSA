public class Merge_part 
{
    static void sort(int a[], int start, int mid, int end){

        int k = 0;
        int size = (end-start);
        int i = start;
        int j = mid;
        int temp [] = new int[size]; 
        while(i < mid && j < end){
            if (a[i] < a[j]) {
                temp[k++] = a[i++];
            }else{
                temp[k++] = a[j++];
            }
        }

        while(i < mid){
            temp[k++] = a[i++];
        }
        while(j < end){
            temp[k++] = a[j++];
        }
        k = 0;
        for (int l = start; l < end;){
            a[l++] = temp[k++];
        }
    }

    public static void main(String[] args) 
    {
        int a[] = {2, 6, 8, 20, 1, 3, 7, 32};
    //    Merge_part.sort(a, 0, 4, 8);
       Merge_part.sort(a,3,4,5);

       for (int num : a) 
       {
              System.out.print(num + " ");
       }
    }
}
  
