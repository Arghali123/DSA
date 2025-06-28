public class LinearProbingHashTable {
    private static final int SIZE = 10;
    private static final Integer DELETED = Integer.MIN_VALUE; // Marker for deleted slots
    private Integer[] table;

    public LinearProbingHashTable() {
        table = new Integer[SIZE];
    }

    private int hash(int key) {
        return key % SIZE;
    }

    public void insert(int key) {
        int index = hash(key);

        while (table[index] != null && table[index] != DELETED) {
            index = (index + 1) % SIZE;
        }

        table[index] = key;
    }

    public boolean search(int key) {
        int index = hash(key);
        int start = index;

        while (table[index] != null) {
            if (table[index] != DELETED && table[index] == key) {
                return true;
            }

            index = (index + 1) % SIZE;
            if (index == start) break;
        }

        return false;
    }

    public void delete(int key) {
        int index = hash(key);
        int start = index;

        while (table[index] != null) {
            if (table[index] != DELETED && table[index] == key) {
                table[index] = DELETED;
                System.out.println("Key " + key + " deleted.");
                return;
            }

            index = (index + 1) % SIZE;
            if (index == start) break;
        }

        System.out.println("Key " + key + " not found.");
    }

    public void display() {
        System.out.println("Hash Table:");
        for (int i = 0; i < SIZE; i++) {
            if (table[i] == null) {
                System.out.println(i + " => empty");
            } else if (table[i] == DELETED) {
                System.out.println(i + " => deleted");
            } else {
                System.out.println(i + " => " + table[i]);
            }
        }
    }

    public static void main(String[] args) {
        LinearProbingHashTable hashTable = new LinearProbingHashTable();

        int[] keys = {23, 43, 13, 27};
        for (int key : keys) {
            hashTable.insert(key);
        }

        hashTable.display();

        System.out.println("Search 43: " + hashTable.search(43));
        System.out.println("Search 99: " + hashTable.search(99));

        hashTable.delete(43);
        hashTable.display();
        System.out.println("Search 43 after deletion: " + hashTable.search(43));
    }
}

