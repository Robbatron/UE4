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
    const FString HIDDEN_WORD = "ant";
    
    myMaxTries = MY_MAX_TRIES;
    myHiddenWord = HIDDEN_WORD;
    
    myCurrentTry = 1;
    myMaxTries = MY_MAX_TRIES;
    
    return;
}

// receives a VALID guess, increments turn, and returns count
FBullCowCount FBullCowGame::SubmitGuess(FString guess) {
    
    myCurrentTry++;
    
    FBullCowCount bullCowCount;
    FString hiddenWord = "ant"; // temporary
    
    for (int32 i = 0; i < hiddenWord.length(); i++) {
        for (int32 j = 0; j < guess.length(); j++) {
            if (hiddenWord[i] == guess[j]) {
                if (i == j) {
                    bullCowCount.Bulls++;
                } else {
                    bullCowCount.Cows++;
                }
            }
        }
    }
    
    return bullCowCount;
}






