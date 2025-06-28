class BSTNode {
    int data;
    BSTNode left, right;

    public BSTNode(int data) {
        this.data = data;
        left = right = null;
    }
}

public class BST {
    BSTNode root;

    public BST() {
        root = null;
    }

    // Public method to insert data
    public void insert(int data) {
        root = insertRec(root, data);
    }

    // Recursive method to insert a new node
    private BSTNode insertRec(BSTNode root, int data) {
        // If the tree is empty, return a new node
        if (root == null) {
            return new BSTNode(data);
        }

        // Otherwise, recur down the tree
        if (data < root.data) {
            root.left = insertRec(root.left, data);
        } else if (data > root.data) {
            root.right = insertRec(root.right, data);
        }

        // return the unchanged root node
        return root;
    }

    // Inorder Traversal to check if insertion is correct
    public void inorder() {
        inorderRec(root);
    }

    private void inorderRec(BSTNode root) {
        if (root != null) {
            inorderRec(root.left);
            System.out.print(root.data + " ");
            inorderRec(root.right);
        }
    }


    //deleting a node 
    // Public method to delete a node
public void delete(int key) {
    root = deleteRec(root, key);
}

// Recursive method to delete a node
private BSTNode deleteRec(BSTNode root, int key) {
    if (root == null) {
        return root;
    }

    // Traverse the tree
    if (key < root.data) {
        root.left = deleteRec(root.left, key);
    } else if (key > root.data) {
        root.right = deleteRec(root.right, key);
    } else {
        // Node to be deleted found

        // Case 1: No child (leaf node)
        if (root.left == null && root.right == null) {
            return null;
        }

        // Case 2: One child
        if (root.left == null) {
            return root.right;
        } else if (root.right == null) {
            return root.left;
        }

        // Case 3: Two children
        // Find inorder successor (smallest in right subtree)
        root.data = minValue(root.right);

        // Delete the inorder successor
        root.right = deleteRec(root.right, root.data);
    }

    return root;
}

// Helper method to find the minimum value
private int minValue(BSTNode root) {
    int min = root.data;
    while (root.left != null) {
        root = root.left;
        min = root.data;
    }
    return min;
}


    // Main method to test insertion
    public static void main(String[] args) {
        BST bst = new BST();

        // Inserting nodes
        bst.insert(50);
        bst.insert(30);
        bst.insert(70);
        bst.insert(20);
        bst.insert(40);
        bst.insert(60);
        bst.insert(80);

        // Print inorder traversal
        System.out.print("Inorder traversal: ");
        bst.inorder();  // Output: 20 30 40 50 60 70 80
    }
}
