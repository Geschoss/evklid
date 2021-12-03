#ifndef MINER_STATES_H
#define MINER_STATES_H

#include "State.h"

class Miner;

class EnterMineAndDigForNugget : public State
{
private:
    EnterMineAndDigForNugget(){};
    // copy ctor and assignment should be private
    EnterMineAndDigForNugget(const EnterMineAndDigForNugget &);
    EnterMineAndDigForNugget &operator=(const EnterMineAndDigForNugget &);

public:
    static EnterMineAndDigForNugget *Instance();
    virtual void Enter(Miner *miner);
    virtual void Execute(Miner *miner);
    virtual void Exit(Miner *miner);
};

#endif