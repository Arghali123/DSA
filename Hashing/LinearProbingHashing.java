public class LinearProbingHashing {
    static int TABLE_SIZE = 10;
    static int[] hashTable = new int[TABLE_SIZE];

    public static void main(String[] args) {
        // Initialize table
        for (int i = 0; i < TABLE_SIZE; i++) {
            hashTable[i] = -1;  // -1 means empty
        }

        int[] keys = {89, 18, 49, 58, 69};

        System.out.println("Inserting keys with collision visualization:");
        for (int key : keys) {
            insert(key);
        }

        System.out.println("\nHash Table:");
        printTable();

        // Search
        System.out.println("\nSearching for 49 and 99:");
        search(49);
        search(99);

        // Delete
        System.out.println("\nDeleting 49 and 18:");
        delete(49);
        delete(18);
        printTable();

        // Search after deletion
        System.out.println("\nSearching after deletion:");
        search(49);
        search(18);
    }

    static void insert(int key) {
        int index = key % TABLE_SIZE;
        int startIndex = index;

        while (hashTable[index] != -1 && hashTable[index] != -2) {
            System.out.println("Collision at index " + index + " for key " + key);
            index = (index + 1) % TABLE_SIZE;
            if (index == startIndex) {
                System.out.println("Hash table is full! Cannot insert " + key);
                return;
            }
        }

        hashTable[index] = key;
        System.out.println("Inserted " + key + " at index " + index);
    }

    static void search(int key) {
        int index = key % TABLE_SIZE;
        int startIndex = index;

        while (hashTable[index] != -1) {
            if (hashTable[index] == key) {
                System.out.println("Found key " + key + " at index " + index);
                return;
            }
            index = (index + 1) % TABLE_SIZE;
            if (index == startIndex) break;
        }
        System.out.println("Key " + key + " not found.");
    }

    static void delete(int key) {
        int index = key % TABLE_SIZE;
        int startIndex = index;

        while (hashTable[index] != -1) {
            if (hashTable[index] == key) {
                hashTable[index] = -2;  // Mark as deleted
                System.out.println("Deleted key " + key + " from index " + index);
                return;
            }
            index = (index + 1) % TABLE_SIZE;
            if (index == startIndex) break;
        }
        System.out.println("Key " + key + " not found. Cannot delete.");
    }

    static void printTable() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            String status;
            if (hashTable[i] == -1) status = "Empty";
            else if (hashTable[i] == -2) status = "Deleted";
            else status = String.valueOf(hashTable[i]);

            System.out.println(i + " --> " + status);
        }
    }
}
