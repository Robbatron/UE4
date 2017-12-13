//
//  FBullCowGame.cpp
//  Section_02
//
//  Created by Robert Delfs on 11/19/17.
//  Copyright © 2017 Robert Delfs. All rights reserved.
//
#pragma once

#include <iostream>
#include "FBullCowGame.hpp"
#include <map>

// to make syntax more Unreal friendly
#define TMap std::map

using FString = std::string;
using int32 = int;

FBullCowGame::FBullCowGame() { reset(); } // default constructor

// putting const at end of member function prevents you from mutating member variables

int32 FBullCowGame::getCurrentTry() const { return myCurrentTry; }
int32 FBullCowGame::getHiddenWordLength() const { return static_cast<int32>(myHiddenWord.length()); }
bool FBullCowGame::isGameWon() const { return bGameIsWon; }

int32 FBullCowGame::getMaxTries() const {
    TMap<int32, int32> wordLengthToMaxTries { {3,4}, {4,7}, {5,10}, {6,16}, {7,20} };
    return wordLengthToMaxTries[getHiddenWordLength()];
}

void FBullCowGame::reset() {
    
    const FString HIDDEN_WORD = "plane"; // this MUST be an isogram
    
    myHiddenWord = HIDDEN_WORD;
    myCurrentTry = 1;
    bGameIsWon = false;
    
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
    
    if (bullCowCount.Bulls == wordLength) { bGameIsWon = true; }
    else { bGameIsWon = false; }
    
    return bullCowCount;
}

EGuessStatus FBullCowGame::checkGuessValidity(FString guess) const {
    
    if (!isIsogram(guess)) {
        return EGuessStatus::Not_Isogram;
    } else if (!isLowercase(guess)) {
        return EGuessStatus::Not_Lowercase;
    } else if (guess.length() != getHiddenWordLength()) {
        return EGuessStatus::Wrong_Length;
    } else {
        return EGuessStatus::OK;
    }
    
}

bool FBullCowGame::isIsogram(FString word) const {
    
    // treat 0 and 1 letter words as isograms
    if (word.length() <= 1) { return true; }

    // set up our map
    TMap<char, bool> letterSeen;
    
    // loop through all the letters of the word
    for (auto letter : word) {
        letter = tolower(letter);
        if (letterSeen[letter]) { return false; }
        else { letterSeen[letter] = true; }
    }

    return true; // in cases where /0 is entered
    
}

bool FBullCowGame::isLowercase(FString word) const {
    
    for (auto w : word) {
        if (!islower(w)) {
            return false;
        }
    }
    return true;
    
}




