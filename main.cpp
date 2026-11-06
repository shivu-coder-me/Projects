
#include <iostream>
#include <limits>
using namespace std;

const int SIZE = 3;

// Display the game board
void displayBoard(char board[SIZE][SIZE]) {
    cout << "\n";
    cout << " " << board[0][0] << " | " << board[0][1]
         << " | " << board[0][2] << "\n";
    cout << "---+---+---\n";
    cout << " " << board[1][0] << " | " << board[1][1]
         << " | " << board[1][2] << "\n";
    cout << "---+---+---\n";
    cout << " " << board[2][0] << " | " << board[2][1]
         << " | " << board[2][2] << "\n\n";
}

// Check whether a player has won
bool checkWin(char board[SIZE][SIZE], char player) {
    // Check rows and columns
    for (int i = 0; i < SIZE; i++) {
        if (board[i][0] == player &&
            board[i][1] == player &&
            board[i][2] == player) {
            return true;
        }

        if (board[0][i] == player &&
            board[1][i] == player &&
            board[2][i] == player) {
            return true;
        }
    }

    // Check diagonals
    if (board[0][0] == player &&
        board[1][1] == player &&
        board[2][2] == player) {
        return true;
    }

    if (board[0][2] == player &&
        board[1][1] == player &&
        board[2][0] == player) {
        return true;
    }

    return false;
}

// Check whether the board is full
bool isDraw(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] != 'X' &&
                board[i][j] != 'O') {
                return false;
            }
        }
    }

    return true;
}

// Run one complete game
void playGame() {
    char board[SIZE][SIZE] = {
        {'1', '2', '3'},
        {'4', '5', '6'},
        {'7', '8', '9'}
    };

    char player = 'X';
    int move;

    while (true) {
        displayBoard(board);

        cout << "Player " << player
             << ", choose a cell (1-9): ";

        // Validate numeric input
        if (!(cin >> move)) {
            cout << "Invalid input. Enter a number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        if (move < 1 || move > 9) {
            cout << "Choose a number between 1 and 9.\n";
            continue;
        }

        // Convert cell number to row and column
        int row = (move - 1) / SIZE;
        int col = (move - 1) % SIZE;

        // Prevent overwriting an occupied cell
        if (board[row][col] == 'X' ||
            board[row][col] == 'O') {
            cout << "That cell is already occupied!\n";
            continue;
        }

        board[row][col] = player;

        if (checkWin(board, player)) {
            displayBoard(board);
            cout << "Player " << player << " wins!\n";
            break;
        }

        if (isDraw(board)) {
            displayBoard(board);
            cout << "It's a draw!\n";
            break;
        }

        // Switch players
        player = (player == 'X') ? 'O' : 'X';
    }
}

int main() {
    char again;

    cout << "========================\n";
    cout << "   TIC-TAC-TOE GAME\n";
    cout << "========================\n";

    do {
        playGame();

        cout << "\nPlay again? (y/n): ";
        cin >> again;

        // Discard any extra input on the line
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

    } while (again == 'y' || again == 'Y');

    cout << "\nThanks for playing!\n";

    return 0;
