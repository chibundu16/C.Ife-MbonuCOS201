#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function prototypes
void playRockPaperScissors();
void playTicTacToe();
void playNumberGuessingGame();

int main() {
    srand(static_cast<unsigned int>(time(0))); // Seed the random number generator

    int choice;

    while (true) {
        cout << "Choose a game to play:\n";
        cout << "1. Rock, Paper, Scissors\n";
        cout << "2. Tic-Tac-Toe\n";
        cout << "3. Number Guessing Game\n";
        cout << "4. Exit\n";
        cout << "Enter your choice (1-4): ";
        cin >> choice;

        switch (choice) {
            case 1:
                playRockPaperScissors();
                break;
            case 2:
                playTicTacToe();
                break;
            case 3:
                playNumberGuessingGame();
                break;
            case 4:
                cout << "Exiting the game. Goodbye!\n";
                return 0;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 4.\n";
                break;
        }
    }

    return 0;
}

// Function to play Rock, Paper, Scissors
void playRockPaperScissors() {
    int playerChoice, computerChoice;
    string choiceToString(int choice);

    cout << "Welcome to Rock, Paper, Scissors!\n";
    cout << "Enter your choice: (0) Rock, (1) Paper, (2) Scissors: ";
    cin >> playerChoice;

    computerChoice = rand() % 3; // 0 = Rock, 1 = Paper, 2 = Scissors

    cout << "You chose " << choiceToString(playerChoice) << "\n";
    cout << "Computer chose " << choiceToString(computerChoice) << "\n";

    if (playerChoice == computerChoice) {
        cout << "It's a tie!\n";
    } else if ((playerChoice == 0 && computerChoice == 2) ||
               (playerChoice == 1 && computerChoice == 0) ||
               (playerChoice == 2 && computerChoice == 1)) {
        cout << "You win!\n";
    } else {
        cout << "You lose!\n";
    }
}

// Function to convert choice to string
string choiceToString(int choice) {
    if (choice == 0) return "Rock";
    if (choice == 1) return "Paper";
    return "Scissors";
}

// Function to play Tic-Tac-Toe
void playTicTacToe() {
    char board[3][3] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };
    char currentMarker;
    int currentPlayer;
    int slot;

    auto drawBoard = [&]() {
        cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << "\n";
        cout << "---|---|---\n";
        cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << "\n";
        cout << "---|---|---\n";
        cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << "\n";
    };

    auto placeMarker = [&](int slot) -> bool {
        int row = (slot - 1) / 3;
        int col = (slot - 1) % 3;
        if (board[row][col] != 'X' && board[row][col] != 'O') {
            board[row][col] = currentMarker;
            return true;
        } else {
            return false;
        }
    };

    auto checkWinner = [&]() -> int {
        for (int i = 0; i < 3; i++) {
            if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return currentPlayer;
        }
        for (int i = 0; i < 3; i++) {
            if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return currentPlayer;
        }
        if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return currentPlayer;
        if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return currentPlayer;
        return 0;
    };

    auto swapPlayerAndMarker = [&]() {
        if (currentMarker == 'X') {
            currentMarker = 'O';
        } else {
            currentMarker = 'X';
        }
        currentPlayer = (currentPlayer == 1) ? 2 : 1;
    };

    cout << "Player 1, choose your marker (X or O): ";
    char markerP1;
    cin >> markerP1;
    currentPlayer = 1;
    currentMarker = markerP1;
    
    drawBoard();
    int playerWon;

    for (int i = 0; i < 9; i++) {
        cout << "It's Player " << currentPlayer << "'s turn. Enter your slot: ";
        cin >> slot;

        if (slot < 1 || slot > 9) {
            cout << "Invalid slot! Try again.\n";
            i--;
            continue;
        }

        if (!placeMarker(slot)) {
            cout << "Slot already taken! Try again.\n";
            i--;
            continue;
        }

        drawBoard();

        playerWon = checkWinner();

        if (playerWon == 1) {
            cout << "Player 1 wins!\n";
            break;
        }
        if (playerWon == 2) {
            cout << "Player 2 wins!\n";
            break;
        }

        swapPlayerAndMarker();
    }

    if (playerWon == 0) {
        cout << "It's a tie!\n";
    }
}

// Function to play Number Guessing Game
void playNumberGuessingGame() {
    int secretNumber = rand() % 100 + 1;
    int playerGuess = 0;
    int numberOfTries = 5;

    cout << "Welcome to the Number Guessing Game!\n";
    cout << "I have selected a number between 1 and 100.\n";
    cout << "You have " << numberOfTries << " attempts to guess it.\n";

    while (numberOfTries > 0) {
        cout << "Enter your guess: ";
        cin >> playerGuess;

        if (playerGuess > secretNumber) {
            cout << "Too high! ";
        } else if (playerGuess < secretNumber) {
            cout << "Too low! ";
        } else {
            cout << "Congratulations! You guessed the number.\n";
            break;
        }

        numberOfTries--;
        if (numberOfTries > 0) {
            cout << "You have " << numberOfTries << " attempts left.\n";
        } else {
            cout << "Sorry, you're out of attempts! The correct number was " << secretNumber << ".\n";
        }
    }

    cout << "Thanks for playing!\n";
}
