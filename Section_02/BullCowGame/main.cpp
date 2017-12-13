//
//  main.cpp
//  Section_02
//
//  Created by Robert Delfs on 11/18/17.
//  Copyright © 2017 Robert Delfs. All rights reserved.
//
// This is the console executable that makes use of the BullCow class.
// This acts as the view in a MVC pattern, and is responsible for all user interaction.
// For game logic, see the FBullCowGame class.
#pragma once

#include <iostream>
#include <string>
#include "main.hpp"
#include "FBullCowGame.hpp"

// to make syntax Unreal friendly
using FText = std::string;
using int32 = int;

FBullCowGame BCGame; // instantiate a new game to be reused across plays

int main() {
    
    do {
        printIntro();
        playGame();
    } while (askToPlayAgain());
    
    return 0;
}

// prompt the user for Y or N to play again
bool askToPlayAgain() {
    
    FText answer = "";
    
    std::cout << "\nWould you like to play again with the same word? (y or n): ";
    getline(std::cin, answer);
    
    BCGame.reset();
    
    return (tolower(answer[0]) == 'y');
    
}

// introduce the game
void printIntro() {
    
    std::cout << "Welcome to Bulls and Cows, a fun word game." << std::endl;
    std::cout << "Can you guess the " << BCGame.getHiddenWordLength() << " letter isogram I'm thinking of?" << std::endl;
    
}

// set the number of turns, get user's guesses, then print them back
void playGame() {
    
    BCGame.reset();
    
    int maxTries = BCGame.getMaxTries();
    
    // loop asking for guesses while the game is NOT won
    // and there are still tries remaining
    while (!BCGame.isGameWon() && BCGame.getCurrentTry() <= maxTries) {
    
        FText guess = getValidGuess();
        
        // submit valid guess
        FBullCowCount bullCowCount = BCGame.submitValidGuess(guess);
        // print numbers of bulls and cows
        std::cout << "Bulls = " << bullCowCount.Bulls << std::endl;
        std::cout << "Cows = " << bullCowCount.Cows << std::endl;
        
        int32 triesLeft = (BCGame.getMaxTries() - BCGame.getCurrentTry()) + 1;
        
        if (triesLeft > 1) {
            std::cout << triesLeft << " tries left." << std::endl;
        } else if (triesLeft > 0){
            std::cout << triesLeft << " try left." << std::endl;
        }
        
    }
    
    printGameSummary();
    return;
}

void printGameSummary() {
    if (BCGame.isGameWon()) {
        std::cout << "\nGood job!\n" << std::endl;
    } else {
        std::cout << "\nBetter luck next time!\n" << std::endl;
    }
};

// loop continually until the user gives a valid guess
FText getValidGuess() {
    
    // initialize to invalid status
    EGuessStatus Status = EGuessStatus::Invalid_Status;
    FText guess = "";
    
    do {
        // prompt for guess and store input
        int32 currentTry = BCGame.getCurrentTry();
        
        std::cout << "\nTry " << currentTry << ". Enter your guess: ";
        std::getline(std::cin, guess);
        
        // check guess validity
        Status = BCGame.checkGuessValidity(guess);
        switch (Status) {
            case EGuessStatus::Wrong_Length:
                std::cout << "Please enter a " << BCGame.getHiddenWordLength() << " letter word." << std::endl;
                break;
            case EGuessStatus::Not_Isogram:
                std::cout << "Please enter a word without repeating letters." << std::endl;
                break;
            case EGuessStatus::Not_Lowercase:
                std::cout << "Please enter all lowercase letters." << std::endl;
                break;
            default:
                break;
        }
    } while (Status != EGuessStatus::OK);
    
    return guess;
}


