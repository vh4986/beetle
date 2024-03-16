#pragma once
#ifndef BeetleH
#define BeetleH

#include <string>

namespace cs31
{
    class Beetle
    {
    public:
        Beetle();

        // the possible BodyPart choices for a Beetle
        enum class BodyPart {
            EYE = 1, ANTENNA = 2, LEG = 3,
            TAIL = 4, HEAD = 5, BODY = 6, NOTVALID = 7
        };

        // convert a tossed die value into a BodyPart
        BodyPart convertRollToBodyPart(int die) const;

        // build the Beetle's body
        void buildBody();
        // has the Beetle's body been built?
        bool hasBody() const;

        // build the Beetle's tail
        void buildTail();
        // has the Beetle's tail been built?
        bool hasTail() const;

        // build the Beetle's leg building leg1 before leg2 before leg3 before leg4
        void buildLeg();
        // has the Beetle's legs been built?
        bool hasLeg1() const;
        bool hasLeg2() const;
        bool hasLeg3() const;
        bool hasLeg4() const;

        // build the Beetle's head
        void buildHead();
        // has the Beetle's head been built?
        bool hasHead() const;

        // build the Beetle's eye building eye1 before eye2
        void buildEye();
        // has the Beetle's eyes been built?
        bool hasEye1() const;
        bool hasEye2() const;

        // build the Beetle's antenna building antenna1 before antenna2
        void buildAntenna();
        // has the Beetle's antennas been built?
        bool hasAntenna1() const;
        bool hasAntenna2() const;

        // is this Beetle completely built out?
        bool isComplete() const;
    private:
        bool mBody, mTail, mLeg1, mLeg2, mLeg3, mLeg4, mEye1, mEye2, mAntenna1, mHead, mAntenna2;

    };

} // namespace cs31

#endif // BEETLE_H
