//
//  FBullCowGame.hpp
//  Section_02
//
//  Created by Robert Delfs on 11/19/17.
//  Copyright © 2017 Robert Delfs. All rights reserved.
//
/*
    The game logic (no view code or direct user interaction).
    The game is a simple guess the word game based on Mastermind
*/
#pragma once

#include <stdio.h>
#include <string>

// to make syntax Unreal friendly
using FString = std::string;
using int32 = int;

// all values initialized to zero
struct FBullCowCount {
    int32 Bulls = 0;
    int32 Cows = 0;
};

enum class EGuessStatus {
    Invalid_Status,
    OK,
    Not_Isogram,
    Wrong_Length,
    Not_Lowercase
};

class FBullCowGame {
    
public:
    FBullCowGame(); // constructor
    int32 getMaxTries() const;
    int32 getCurrentTry() const;
    int32 getHiddenWordLength() const;
    bool isGameWon() const;
    EGuessStatus checkGuessValidity(FString) const;
    FBullCowCount submitValidGuess(FString);
    void reset();
    
private:
    int32 myCurrentTry;
    FString myHiddenWord;
    bool bGameIsWon;
    bool isIsogram(FString) const;
    bool isLowercase(FString) const;
};
