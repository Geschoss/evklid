#ifndef VISIT_BANK_AND_DEPOSIT_GOLD_STATE_H
#define VISIT_BANK_AND_DEPOSIT_GOLD_STATE_H

#include "../State.h"

class Miner;

class VisitBankAndDepositGold : public State
{
private:
    VisitBankAndDepositGold(){};
    // copy ctor and assignment should be private
    VisitBankAndDepositGold(const VisitBankAndDepositGold &);
    VisitBankAndDepositGold &operator=(const VisitBankAndDepositGold &);

public:
    static VisitBankAndDepositGold *Instance();
    virtual void Enter(Miner *miner);
    virtual void Execute(Miner *miner);
    virtual void Exit(Miner *miner);
};

#endif