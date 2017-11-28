//
//  FBullCowGame.cpp
//  Section_02
//
//  Created by Robert Delfs on 11/19/17.
//  Copyright © 2017 Robert Delfs. All rights reserved.
//
#include <iostream>
#include "FBullCowGame.hpp"

using FString = std::string;
using int32 = int;

FBullCowGame::FBullCowGame() { reset(); }

// putting const at end of member function prevents you from mutating member variables
int32 FBullCowGame::getMaxTries() const { return myMaxTries; }
int32 FBullCowGame::getCurrentTry() const { return myCurrentTry; }
int32 FBullCowGame::getHiddenWordLength() const { return static_cast<int32>(myHiddenWord.length()); }

void FBullCowGame::reset() {
    
    constexpr int32 MY_MAX_TRIES = 3;
    const FString HIDDEN_WORD = "planet";
    
    myMaxTries = MY_MAX_TRIES;
    myHiddenWord = HIDDEN_WORD;
    
    myCurrentTry = 1;
    myMaxTries = MY_MAX_TRIES;
    
    return;
}

// receives a VALID guess, increments turn, and returns count
FBullCowCount FBullCowGame::submitValidGuess(FString guess) {
    
    myCurrentTry++;
    
    FBullCowCount bullCowCount;
    int32 wordLength = getHiddenWordLength();
    
    // loop through all letters in the hidden word
    for (int32 hWChar = 0; hWChar < wordLength; hWChar++) {
        // loop through all letters in the guess
        for (int32 gChar = 0; gChar < wordLength; gChar++) {
            if (myHiddenWord[hWChar] == guess[gChar]) {
                if (hWChar == gChar) {
                    bullCowCount.Bulls++;
                } else {
                    bullCowCount.Cows++;
                }
            }
        }
    }
    
    return bullCowCount;
}

EGuessStatus FBullCowGame::checkGuessValidity(FString guess) const {
    
    if (false) {
        return EGuessStatus::Not_Isogram;
    } else if (false) {
        return EGuessStatus::Not_Lowercase;
    } else if (guess.length() != getHiddenWordLength()) {
        return EGuessStatus::Wrong_Length;
    } else {
        return EGuessStatus::OK;
    }
}


bool FBullCowGame::isGameWon() const { 
    return true;
}
