public class SequentialSearchExample {
    public static void main(String[] args) {
        int[] array = {5, 3, 9, 1, 6, 7, 2};
        int searchElement = 6;
        boolean found = false;

        for (int i = 0; i < array.length; i++) {
            if (array[i] == searchElement) {
                System.out.println("Element found at index: " + i);
                found = true;
                break;
            }
        }

        if (!found) {
            System.out.println("Element not found in the array.");
        }
    }
}
