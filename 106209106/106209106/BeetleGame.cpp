#include "BeetleGame.h"
#include "BeetleDrawing.h"
#include <iostream>

namespace cs31 {

    BeetleGame::BeetleGame() : mHuman(), mComputer(), mHumanDie(), mComputerDie() {
        // Constructor initializes member variables
    }

    std::string BeetleGame::display(std::string msg) const {
        // Draws the board using a BeetleDrawing object and returns the result as a string
        BeetleDrawing drawing(mHuman, mComputer);
        std::string result = drawing.draw() + "\n" + msg;
        return result;
    }

    void BeetleGame::humanRoll(int amount) {
        // Rolls the human player's die. If amount is zero, it performs a random roll;
        // otherwise, it sets the die value to the specified amount (for cheating).
        if (amount == 0)
            mHumanDie.roll();
        else
            mHumanDie.setValue(amount);
    }

    int BeetleGame::getHumanDie() const {
        // Returns the value of the human player's die
        return mHumanDie.getValue();
    }

    bool BeetleGame::humanPlay() {
        // Converts the human player's die value to a Beetle's body part and attempts
        // to build the corresponding body part on the human player's beetle.
        // Returns true if a body part was successfully built, false otherwise.
        Beetle::BodyPart part = mHuman.convertRollToBodyPart(getHumanDie());
        bool result = false;
        switch (part) {
        case Beetle::BodyPart::EYE:
            // Check game ordering and build eye on human beetle if allowed
            if (mHuman.hasHead() && mHuman.hasLeg1()) {
                mHuman.buildEye();
                result = true;
            }
            break;
        case Beetle::BodyPart::ANTENNA:
            // Check game ordering and build antenna on human beetle if allowed
            if (mHuman.hasHead() && mHuman.hasLeg1()) {
                mHuman.buildAntenna();
                result = true;
            }
            break;
        case Beetle::BodyPart::LEG:
            // Check game ordering and build leg on human beetle if allowed
            if (mHuman.hasBody()) {
                mHuman.buildLeg();
                result = true;
            }
            break;
        case Beetle::BodyPart::TAIL:
            // Check game ordering and build tail on human beetle if allowed
            if (mHuman.hasBody()) {
                mHuman.buildTail();
                result = true;
            }
            break;
        case Beetle::BodyPart::HEAD:
            // Check game ordering and build head on human beetle if allowed
            if (!mHuman.hasHead()) {
                mHuman.buildHead();
                result = true;
            }
            break;
        case Beetle::BodyPart::BODY:
            // Check game ordering and build body on human beetle if allowed
            if (!mHuman.hasBody()) {
                mHuman.buildBody();
                result = true;
            }
            break;
        default:
            // If the die roll does not correspond to a valid body part, do nothing
            break;
        }
        return result;
    }



    void BeetleGame::computerRoll(int amount) {
        // Rolls the computer player's die. If amount is zero, it performs a random roll;
        // otherwise, it sets the die value to the specified amount (for cheating).
        if (amount == 0)
            mComputerDie.roll();
        else
            mComputerDie.setValue(amount);
    }

    int BeetleGame::getComputerDie() const {
        // Returns the value of the computer player's die
        return mComputerDie.getValue();
    }

    bool BeetleGame::computerPlay() {
        // Retrieve the computer player's die value
        int dieValue = getComputerDie();

        // Convert die value to a Beetle's body part
        Beetle::BodyPart part = mComputer.convertRollToBodyPart(dieValue);

        // Attempt to build the corresponding body part on the computer player's beetle
        bool result = false;
        switch (part) {
        case Beetle::BodyPart::EYE:
            // Check game ordering and build eye on computer beetle if allowed
            if (mComputer.hasHead() && mComputer.hasLeg1()) {
                mComputer.buildEye();
                result = true;
            }
            break;
        case Beetle::BodyPart::ANTENNA:
            // Check game ordering and build antenna on computer beetle if allowed
            if (mComputer.hasHead() && mComputer.hasLeg1()) {
                mComputer.buildAntenna();
                result = true;
            }
            break;
        case Beetle::BodyPart::LEG:
            // Check game ordering and build leg on computer beetle if allowed
            if (mComputer.hasBody()) {
                mComputer.buildLeg();
                result = true;
            }
            break;
        case Beetle::BodyPart::TAIL:
            // Check game ordering and build tail on computer beetle if allowed
            if (mComputer.hasBody()) {
                mComputer.buildTail();
                result = true;
            }
            break;
        case Beetle::BodyPart::HEAD:
            // Check game ordering and build head on computer beetle if allowed
            if (!mComputer.hasHead()) {
                mComputer.buildHead();
                result = true;
            }
            break;
        case Beetle::BodyPart::BODY:
            // Check game ordering and build body on computer beetle if allowed
            if (!mComputer.hasBody()) {
                mComputer.buildBody();
                result = true;
            }
            break;
        default:
            // If the die roll does not correspond to a valid body part, do nothing
            break;
        }

        // Return true if a body part was successfully built, false otherwise
        return result;
    }



    BeetleGame::GameOutcome BeetleGame::determineGameOutcome() const {
        // Determines the current state of the game and returns the result as a GameOutcome enum value
        // Implement the logic to determine the game outcome based on the current game state

        // Check if the human player has completed the beetle and the computer player has not
        if (mHuman.isComplete() && !mComputer.isComplete())
            return GameOutcome::HUMANWONGAME;
        // Check if the computer player has completed the beetle and the human player has not
        else if (!mHuman.isComplete() && mComputer.isComplete())
            return GameOutcome::COMPUTERWONGAME;
        // Check if both players have completed their beetles
        else if (mHuman.isComplete() && mComputer.isComplete())
            return GameOutcome::GAMENOTOVER;
        // If none of the above conditions are met, the game is not over yet
        else
            return GameOutcome::GAMENOTOVER;
    }

    std::string BeetleGame::stringifyGameOutcome() const {
        // Converts the game outcome enum value into a string representation
        // (e.g., "Human Won!", "Computer Won!", "Game Not Over!")
        switch (determineGameOutcome()) {
        case GameOutcome::COMPUTERWONGAME:
            return "Computer Won!";
        case GameOutcome::HUMANWONGAME:
            return "Human Won!";
        case GameOutcome::GAMENOTOVER:
            return "Game Not Over!";
        }
        return ""; // Placeholder return statement
    }

    bool BeetleGame::gameIsOver() const {
        // Checks if the game has ended with a winner and returns true if it has, false otherwise
        // Implement the logic to check if the game is over based on the current game state
        return determineGameOutcome() != GameOutcome::GAMENOTOVER;
    }


    Beetle BeetleGame::getHumanBeetle() const {
        // Returns the human player's beetle
        return mHuman;
    }

    Beetle BeetleGame::getComputerBeetle() const {
        // Returns the computer player's beetle
        return mComputer;
    }

} // namespace cs31

