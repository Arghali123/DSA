
import java.util.ArrayList;
import java.util.List;

public class NQueenProblem {

    public boolean isSafe(int row, int col, char[][] board) {
        // horizontal
        for (int j = 0; j < board.length; j++) 
        {
            if (board[row][j] == 'Q') return false;
        }

        // vertical
        for (int i = 0; i < board.length; i++) 
        {
            if (board[i][col] == 'Q') return false;
        }

        // upper-left diagonal
        int r = row, c = col;
        while (r >= 0 && c >= 0) 
        {
            if (board[r][c] == 'Q') return false;
            r--; c--;
        }

        // upper-right diagonal
        r = row; c = col;
        while (r >= 0 && c < board.length) 
        {
            if (board[r][c] == 'Q') return false;
            r--; c++;
        }

        // lower-left diagonal
        r = row; c = col;
        while (r < board.length && c >= 0) 
        {
            if (board[r][c] == 'Q') return false;
            r++; c--;
        }

        // lower-right diagonal
        r = row; c = col;
        while (r < board.length && c < board.length) 
        {
            if (board[r][c] == 'Q') return false;
            r++; c++;
        }

        return true;
    }

    public void saveBoard(char[][] board, List<List<String>> allBoards) 
    {
        List<String> newBoard = new ArrayList<>();
        for (int i = 0; i < board.length; i++) 
        {

            String row = "";
            for (int j = 0; j < board[0].length; j++) 
            {
                if (board[i][j] == 'Q')
                    row += 'Q';
                else
                    row += '.';
            }
            newBoard.add(row);
        }
        allBoards.add(newBoard);
    }

    public void helper(char[][] board, List<List<String>> allBoards, int col) 
    {
        if (col == board.length) 
        {
            saveBoard(board, allBoards);
            return;
        }

        for (int row = 0; row < board.length; row++) 
        {
            if (isSafe(row, col, board)) 
            {
                board[row][col] = 'Q';             // Place queen
                helper(board, allBoards, col + 1); // Recurse
                board[row][col] = '.';             // Backtrack
            }
        }
    }

    public List<List<String>> solveNQueens(int n) 
    {
        List<List<String>> allBoards = new ArrayList<>();
        char[][] board = new char[n][n];

        // initialize board with '.'
        for (int i = 0; i < n; i++) 
        {
            for (int j = 0; j < n; j++) 
            {
                board[i][j] = '.';
            }
        }

        helper(board, allBoards, 0);
        return allBoards;
    }

    public static void main(String[] args) 
    {
        NQueenProblem solver = new NQueenProblem();
        int n = 4;
        List<List<String>> solutions = solver.solveNQueens(n);

        for (List<String> board : solutions) {
            for (String row : board) 
            {
                System.out.println(row);
            }
            System.out.println();
        }
    }
}
