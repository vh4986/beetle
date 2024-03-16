#pragma once
#ifndef BeetleGameH
#define BeetleGameH

#include <string>
#include "Beetle.h"
#include "Die.h"

namespace cs31 {

    class BeetleGame {
    public:
        BeetleGame();  // Constructor

        // Enumeration for game outcomes
        enum class GameOutcome { HUMANWONGAME, COMPUTERWONGAME, GAMENOTOVER };

        // Draw the board by using a BeetleDrawing to draw the two Beetles
        std::string display(std::string msg = "") const;

        // Roll the human player's die
        void humanRoll(int amount = 0);

        // Return the value of the Human's die
        int getHumanDie() const;

        // Convert the Human's die value to a Beetle's body part and build the desired body part on the Human's beetle
        bool humanPlay();

        // Roll the computer player's die
        void computerRoll(int amount = 0);

        // Return the value of the Computer's die
        int getComputerDie() const;

        // Convert the Computer's die value to a Beetle's body part and build the desired body part on the Computer's beetle
        bool computerPlay();

        // Determine the current state of the game
        GameOutcome determineGameOutcome() const;

        // Convert the game outcome to a string
        std::string stringifyGameOutcome() const;

        // Check if the game has ended with a winner
        bool gameIsOver() const;

        // Getter methods for human and computer beetles
        Beetle getHumanBeetle() const;
        Beetle getComputerBeetle() const;

    private:
        Beetle mHuman;         // Beetle for the human player
        Beetle mComputer;      // Beetle for the computer player
        Die mHumanDie;         // Die for the human player
        Die mComputerDie;      // Die for the computer player
    };

}

#endif // BeetleGameH


