public class BinarySearchExample {
    public static void main(String[] args) {
        int[] array = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        int searchElement = 7;
        int start = 0;
        int end = array.length - 1;
        int mid = (start + end) / 2;

        while (start <= end) {
            if (array[mid] == searchElement) {
                System.out.println("Found");
                break;
            } else if (array[mid] < searchElement) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
            mid = (start + end) / 2;
        }
    }
}
