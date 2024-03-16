#include "Beetle.h"
#include <iostream>


namespace cs31 {
    using namespace std;

    Beetle::Beetle() {
        // Initialize all body parts to false, indicating they have not been built
        mBody = false;
        mTail = false;
        mLeg1 = false;
        mLeg2 = false;
        mLeg3 = false;
        mLeg4 = false;
        mHead = false;
        mEye1 = false;
        mEye2 = false;
        mAntenna1 = false;
        mAntenna2 = false;
    }

    // Convert a tossed die value into a BodyPart
    Beetle::BodyPart Beetle::convertRollToBodyPart(int die) const {
        // Map the die value to the corresponding body part enum
        switch (die) {
        case 1:
            return BodyPart::EYE;
        case 2:
            return BodyPart::ANTENNA;
        case 3:
            return BodyPart::LEG;
        case 4:
            return BodyPart::TAIL;
        case 5:
            return BodyPart::HEAD;
        case 6:
            return BodyPart::BODY;
        default:
            return BodyPart::NOTVALID;
        }
    }

    // Build the Beetle's body
    void Beetle::buildBody() {
        mBody = true;
    }

    // Check if the Beetle's body has been built
    bool Beetle::hasBody() const {
        return mBody;
    }

    // Build the Beetle's tail
    void Beetle::buildTail() {
        // Build the tail only if the body has already been built
        if (mBody)
            mTail = true;
    }

    // Check if the Beetle's tail has been built
    bool Beetle::hasTail() const {
        return mTail;
    }

 
    // Build the Beetle's leg
    void Beetle::buildLeg() {
        if (mBody) {
            if (!mLeg1) {
                mLeg1 = true;
            }
            else if (!mLeg2) {
                mLeg2 = true;
            }
            else if (!mLeg3) {
                mLeg3 = true;
            }
            else if (!mLeg4) {
                mLeg4 = true;
            }
        }
    }





 
    // Build the Beetle's head
    void Beetle::buildHead() {
        // Build the head regardless of whether the body exists
        mHead = true;
    }


    // Check if the Beetle's head has been built
    bool Beetle::hasHead() const {
        return mHead;
    }

    // Check if any of the Beetle's legs have been built
    bool Beetle::hasLeg1() const {
        return mLeg1;
    }

    bool Beetle::hasLeg2() const {
        return mLeg2;
    }

    bool Beetle::hasLeg3() const {
        return mLeg3;
    }

    bool Beetle::hasLeg4() const {
        return mLeg4;
    }


    // Build the Beetle's eye
    void Beetle::buildEye() {
        // Build the eye only if the head has already been built
        if (mHead) {
            if (!mEye1)
                mEye1 = true;
            else if (!mEye2)
                mEye2 = true;
        }
    }

    // Check if any of the Beetle's eyes have been built
    bool Beetle::hasEye1() const {
        return mEye1;
    }

    bool Beetle::hasEye2() const {
        return mEye2;
    }

    // Build the Beetle's antenna
    void Beetle::buildAntenna() {
        // Build the antenna only if the head has already been built
        if (mHead) {
            if (!mAntenna1)
                mAntenna1 = true;
            else if (!mAntenna2)
                mAntenna2 = true;
        }
    }

    // Check if any of the Beetle's antennas have been built
    bool Beetle::hasAntenna1() const {
        return mAntenna1;
    }

    bool Beetle::hasAntenna2() const {
        return mAntenna2;
    }

    // Check if the Beetle is completely built out
    bool Beetle::isComplete() const {
        // Check if all body parts have been built
        return mBody && mTail && mLeg1 && mLeg2 && mLeg3 && mLeg4 && mHead && mEye1 && mEye2 && mAntenna1 && mAntenna2;
    }

} // namespace cs31
