public class MergeSort
{
    static void sort(int[] a,int start,int mid,int end)
    {
      int k=0;
      int size=end-start;
      int i=start;
      int j=mid;
      int[] temp=new int[size];
      while(i<mid && j<end)
      {
        if(a[i]<a[j])
        {
            temp[k++]=a[i++];
        }
        else
        {
          temp[k++]=a[j++];
        }
      }
      while(i<mid)
      {
        temp[k++]=a[i++];
      }
      while(j<end)
      {
        temp[k++]=a[j++];
      }

      for(int l=start;l<size;l++)
      {
        a[l]=temp[l];
      }

      for(int d=0;d<size;d++)
      {
        System.out.print(a[d]+" ");
      }

    }
 
    public static void main(String[] args) {
        int[] a={1,6,8,20,2,3,7,12};
        int s=0;
        int e=a.length;
        int m=(s+e)/2;
        MergeSort.sort(a, s,m,e);
        
    }
}