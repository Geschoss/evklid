#ifndef QUENCH_THIRST_H
#define QUENCH_THIRST_H

#include "../State.h"

class Miner;

class QuenchThirst : public State
{
private:
    QuenchThirst(){};
    // copy ctor and assignment should be private
    QuenchThirst(const QuenchThirst &);
    QuenchThirst &operator=(const QuenchThirst &);

public:
    static QuenchThirst *Instance();
    virtual void Enter(Miner *miner);
    virtual void Execute(Miner *miner);
    virtual void Exit(Miner *miner);
};

#endif