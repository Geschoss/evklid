#ifndef MINER_H
#define MINER_H

#include <string>
#include <cassert>

#include "BaseGameEntity.h"
#include "State.h"
#include "Locations.h"

// the amount of gold a miner must have beefore he fells comfortable
const int COMFORT_GOLD_COUNT = 5;
// the amount of nuggets a miner can carry
const int MAX_CURRY_NUGGETTS = 3;
// above this level of thirsty minner must go to bar
const int MAX_THIRSTY_LEVEL = 5;
// above this value a miner is sleepy
const int TIREDNESS_THRESHOLD = 5;

class Miner : public BaseGameEntity
{
private:
    // current state
    State *m_pCurrentState;
    // the place where the miner is currently situated
    location_type m_Location;
    // how many nuggets thee miner has in his pockets
    int m_iGoldCarried;
    // how much money the miner has deposited in the bank
    int m_iMoneyInBank;
    // the higher the value, the thirstier the miner
    int m_iThirst;
    // the higher the value, the more tired the miner
    int m_iFatigue;

public:
    Miner(int ID);

    void Update();

    void ChangeState(State *pNewState);

    location_type getlocation() const { return m_Location; };
    void changeLocation(const location_type loc) { m_Location = loc; };

    void addToGoldCarried(const int val);
    bool isPocketsFull() const { return m_iGoldCarried >= MAX_CURRY_NUGGETTS; }

    void increaseFatigue() { m_iFatigue += 1; };

    bool isThirsty() const;
};

#endif