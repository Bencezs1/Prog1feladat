#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

// Function to shuffle the vector
void shuffle(std::vector<int>& vec) {
    srand(time(0)); // Seed the random number generator
    for (int i = vec.size() - 1; i > 0; --i) {
        int j = rand() % (i + 1);
        std::swap(vec[i], vec[j]);
    }
}

// Function to print the game board with memory addresses
void printBoard(const std::vector<std::vector<int>>& board) {
    for (const auto& row : board) {
        for (int i = 0; i < row.size(); ++i) {
            std::cout << &row[i] << " "; // Directly print the address of each element
        }
        std::cout << std::endl;
    }
}

// Function to play the game
void playGame() {
    std::vector<int> numbers = {1, 1, 2, 2, 3, 3, 4, 4, 5, 5};
    shuffle(numbers);

    std::vector<std::vector<int>> board(5, std::vector<int>(2, 0));
    for (int i = 0; i < 5; ++i) {
        board[i][0] = numbers[i * 2];
        board[i][1] = numbers[i * 2 + 1];
    }

    printBoard(board);

    int guess1, guess2, guess3, guess4;
    bool found = false;
    while (!found) {
        std::cout << "Enter the first pair of numbers (row and column): ";
        std::cin >> guess1 >> guess2;
        std::cout << "Enter the second pair of numbers (row and column): ";
        std::cin >> guess3 >> guess4;

        if (&board[guess1 - 1][guess2 - 1] == &board[guess3 - 1][guess4 - 1]) {
            std::cout << "Match found!\n";
            board[guess1 - 1][guess2 - 1] = 0;
            board[guess3 - 1][guess4 - 1] = 0;
            printBoard(board);
            found = true;
        } else {
            std::cout << "No match found. Try again.\n";
        }
    }
}

int main() {
    playGame();
    return 0;
}