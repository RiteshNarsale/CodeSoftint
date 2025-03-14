#include <iostream>
#include <vector>

using namespace std;

// Function to initialize the board
void initializeBoard(vector<vector<char>>& board) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';  // Empty spaces at the start
        }
    }
}

// Function to display the current game board
void displayBoard(const vector<vector<char>>& board) {
    cout << "\nCurrent board:\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        cout << endl;
        if (i < 2) cout << "---------\n";
    }
}

// Function to check if a player has won
bool checkWin(const vector<vector<char>>& board, char player) {
    // Check rows, columns, and diagonals
    for (int i = 0; i < 3; i++) {
        // Check row
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return true;
        // Check column
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return true;
    }

    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return true;

    return false;
}

// Function to check if the board is full (for a draw)
bool checkDraw(const vector<vector<char>>& board) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return false;  // If any space is empty, it's not a draw
            }
        }
    }
    return true;  // If no spaces are empty, it's a draw
}

// Function to handle player move input and update the board
bool makeMove(vector<vector<char>>& board, char player) {
    int row, col;

    while (true) {
        cout << "Player " << player << ", enter your move (row and column 0-2): ";
        cin >> row >> col;

        // Check for valid input
        if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
            board[row][col] = player;  // Update the board with the player's move
            return true;
        } else {
            cout << "Invalid move! Try again.\n";
        }
    }
}

// Function to play a single game of Tic-Tac-Toe
void playGame() {
    vector<vector<char>> board(3, vector<char>(3));
    initializeBoard(board);
    char currentPlayer = 'X';
    bool gameWon = false;

    // Loop for game turns
    while (true) {
        displayBoard(board);
        makeMove(board, currentPlayer);

        // Check if the current player has won
        if (checkWin(board, currentPlayer)) {
            displayBoard(board);
            cout << "Player " << currentPlayer << " wins!\n";
            gameWon = true;
            break;
        }

        // Check for draw
        if (checkDraw(board)) {
            displayBoard(board);
            cout << "It's a draw!\n";
            break;
        }

        // Switch players
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    // Ask if the players want to play again
    char playAgain;
    cout << "Do you want to play again? (y/n): ";
    cin >> playAgain;
    if (playAgain == 'y' || playAgain == 'Y') {
        playGame();  // Recursively restart the game
    } else {
        cout << "Thanks for playing! Goodbye.\n";
    }
}

int main() {
    // Start the game
    playGame();
    return 0;
}
