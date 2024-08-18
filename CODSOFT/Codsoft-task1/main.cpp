#include <iostream>
#include <cstdlib>
#include <ctime>

// number guessing game

int main() {
    // Initialize random seed
    std::srand(std::time(0));

    // Generate a random number between 1 and 100
    int secretNumber = std::rand() % 100 + 1;
    int guess = 0;
    int numberOfTries = 0;

    std::cout << "Welcome to the Number Guessing Game!" << std::endl;
    std::cout << "I have selected a number between 1 and 100." << std::endl;

    // Loop until the user guesses the correct number
    while (guess != secretNumber) {
        std::cout << "Enter your guess: ";
        std::cin >> guess;
        numberOfTries++;

        if (guess < secretNumber) {
            std::cout << "Too low! Try again." << std::endl;
        } else if (guess > secretNumber) {
            std::cout << "Too high! Try again." << std::endl;
        } else {
            std::cout << "Congratulations! You've guessed the correct number in " 
                      << numberOfTries << " tries." << std::endl;
        }
    }

    return 0;
}
