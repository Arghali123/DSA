

public class Practice {
    private static final int SIZE=10;
    private static final Integer DELETED=Integer.MIN_VALUE;//Marker of deleted slots
    private Integer[] table;

    public Practice()
    {
        table=new Integer[SIZE];
    }

    private int hash(int key)
    {
        return key%SIZE;
    }

    public void insert(int key)
    {
        int index=hash(key);
        while(table[index]!=null && table[index]!=DELETED)
        {
            index=(index+1)%SIZE;
        }
        table[index]=key;
    }

    public boolean search(int key)
    {
        int index=hash(key);
        int start=index;

       while(table[index]!=null)
       {
         if(table[index]!=DELETED && table[index]==key)
         {
            return true;
         }
         index=(index+1)%SIZE;
         if(index==start) break;
       }
       return false;
    }

    public void delete(int key)
    {
        int index=hash(key);
        int start=index;

        while (table[index]!=null) 
        {
            if(table[index]!=DELETED && table[index]==key)
            {
                table[index]=DELETED;
                System.out.println("Key "+key+" deleted.");
                return;
            }
            index=(index+1)%SIZE;
            if(index==start) break;
        }

        System.out.println("Key "+key+" not found.");
    }

    public void display()
    {
        System.out.println("Hash Table.");
        for(int i=0;i<SIZE;i++)
        {
            if(table[i]==null)
            {
                System.out.println(i+" =>empty");
            }
            else if(table[i]==DELETED)
            {
                System.out.println(i+" =>Deleted");
            }else
            {
                System.out.println(i+" =>"+table[i]);
            }
        }
    }

    public static void main(String[] args) {
        Practice hashTable=new Practice();
        int[] keys={89,18,49,58,69};
        for(int key:keys)
        {
            hashTable.insert(key);
        }
        hashTable.display();

        //Searching
        System.out.println("Search 58: "+hashTable.search(58));
        System.out.println("Search 91: "+hashTable.search(91));

        //Delete
        hashTable.delete(18);
        hashTable.display();
    }
}
