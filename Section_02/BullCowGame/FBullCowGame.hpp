//
//  FBullCowGame.hpp
//  Section_02
//
//  Created by Robert Delfs on 11/19/17.
//  Copyright © 2017 Robert Delfs. All rights reserved.
//
#pragma once

#include <stdio.h>
#include <string>

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
    
    void reset(); // TODO: make a more rich return value
    FBullCowCount submitValidGuess(FString);

private:
    int32 myCurrentTry;
    int32 myMaxTries;
    FString myHiddenWord;
};
