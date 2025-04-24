import java.util.Iterator;
import java.util.PriorityQueue;
public class PriorityQueueExample {
    public static void main(String[] args) {
        PriorityQueue<Integer> numbers=new PriorityQueue<>();
        numbers.add(4);
        numbers.add(2);
        System.out.println("PriorityQueue: "+numbers);

        //Using offer() method
        numbers.offer(1);
        System.out.println("Updated PriorityQueue: "+numbers);

        //Using peek() method
        int peeked_value=numbers.peek();
        System.out.println("Accessed Element: "+peeked_value);

        //Creating next PriorityQueue
        PriorityQueue<Integer> priorityQueue=new PriorityQueue<>();
        priorityQueue.add(5);
        priorityQueue.add(6);
        priorityQueue.add(7);
        System.out.println("New PriorityQueue: "+priorityQueue);

        //Using remove() method
        boolean result=priorityQueue.remove(6);
        System.out.println("Is the element 6  removed?: "+result);

        //Using poll() method
        int polled_value=priorityQueue.poll();
        System.out.println("Removed elements from Using the poll(): "+polled_value);
        System.out.println("New PriorityQueue after: "+priorityQueue);

        //Using iterator() method
        PriorityQueue<Integer> queue=new PriorityQueue<>();
        queue.add(5);
        queue.add(2);
        queue.add(19);
        queue.add(4);
        queue.add(23);
        queue.add(1);

        System.out.println("PriorityQueue using iterator(): ");
        Iterator<Integer> iterate=queue.iterator();
        while(iterate.hasNext())
        {
            System.out.print(iterate.next());
            System.out.print(", ");
        }

    }
}
