import java.util.Scanner;

class BTNode {
    BTNode left, right;
    int data;

    public BTNode() {
        left = null;
        right = null;
        data = 0;
    }

    public BTNode(int n) {
        left = null;
        right = null;
        data = n;
    }

    public void setLeft(BTNode n) {
        left = n;
    }

    public BTNode getLeft() {
        return left;
    }

    public void setRight(BTNode n) {
        right = n;
    }

    public BTNode getRight() {
        return right;
    }

    public void setData(int d) {
        data = d;
    }

    public int getData() {
        return data;
    }
}

class BT {
    private BTNode root;

    public BT() {
        root = null;
    }

    public boolean isEmpty() {
        return root == null;
    }

    // function to insert data
    public void insert(int data) {
        root = insert(root, data);
    }

    private BTNode insert(BTNode node, int data) {
        if (node == null) {
            node = new BTNode(data);
        } else {
            if (node.getRight() == null) {
                node.right = insert(node.right, data);
            } else {
                node.left = insert(node.left, data);
            }
        }
        return node;
    }

    // Pre-order
    public void preorder() {
        preorder(root);
    }

    private void preorder(BTNode r) {
        if (r != null) {
            System.out.print(r.getData() + " ");
            preorder(r.getLeft());
            preorder(r.getRight());
        }
    }

    // In-order
    public void inorder() {
        inorder(root);
    }

    private void inorder(BTNode r) {
        if (r != null) {
            inorder(r.getLeft());
            System.out.print(r.getData() + " ");
            inorder(r.getRight());
        }
    }

    // Post-order
    public void postorder() {
        postorder(root);
    }

    private void postorder(BTNode r) {
        if (r != null) {
            postorder(r.getLeft());
            postorder(r.getRight());
            System.out.print(r.getData() + " ");
        }
    }

    // Search
    public boolean search(int val) {
        return search(root, val);
    }

    private boolean search(BTNode r, int val) {
        if (r.getData() == val) {
            return true;
        }
        if (r.getLeft() != null) {
            if (search(r.getLeft(), val)) {
                return true;
            }
        }
        if (r.getRight() != null) {
            if (search(r.getRight(), val)) {
                return true;
            }
        }
        return false;
    }

    // Count nodes
    public int count() {
        return count(root);
    }

    private int count(BTNode r) {
        if (r == null) {
            return 0;
        } else {
            int l = 1;
            l += count(r.getLeft());
            l += count(r.getRight());
            return l;
        }
    }

    // Delete node
    public void delete(int key) {
        if (root == null) {
            System.out.println("Tree is empty");
            return;
        }

        if (root.left == null && root.right == null) {
            if (root.data == key) {
                root = null;
            }
            return;
        }

        BTNode keyNode = null;
        BTNode temp = null;
        BTNode parentOfDeepest = null;

        // Level-order traversal to find keyNode and the deepest node
        java.util.Queue<BTNode> queue = new java.util.LinkedList<>();
        queue.add(root);

        while (!queue.isEmpty()) {
            temp = queue.poll();

            if (temp.data == key) {
                keyNode = temp;
            }

            if (temp.left != null) {
                parentOfDeepest = temp;
                queue.add(temp.left);
            }

            if (temp.right != null) {
                parentOfDeepest = temp;
                queue.add(temp.right);
            }
        }

        if (keyNode != null) {
            keyNode.data = temp.data; // Replace keyNode's data with deepest node's data

            // Delete deepest node
            if (parentOfDeepest.right == temp) {
                parentOfDeepest.right = null;
            } else if (parentOfDeepest.left == temp) {
                parentOfDeepest.left = null;
            }
        } else {
            System.out.println("Node with value " + key + " not found.");
        }
    }

}

public class BinaryTree {

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        BT bt = new BT();
        bt.insert(1);
        bt.insert(2);
        bt.insert(3);
        bt.insert(4);
        bt.insert(5);
        bt.insert(6);
        bt.insert(7);

        System.out.println("Pre-Order");
        bt.preorder();

        System.out.println("\nIn-order");
        bt.inorder();

        System.out.println("\nPost-order");
        bt.postorder();

        System.out.println("\nRearch result: " + bt.search(16));

        System.out.println("\nTotal no of node present: " + bt.count());

        System.out.println("\nDeleting node 3...");
        bt.delete(3);

        System.out.println("\nPre-Order after deletion:");
        bt.preorder();

        scan.close();
    }
}
