#include "States.h"
#include "Miner.h"
#include "Locations.h"
#include "EntityNames.h"

#include <iostream>
using namespace std;

EnterMineAndDigForNugget *EnterMineAndDigForNugget::Instance()
{
    static EnterMineAndDigForNugget instance;
    return &instance;
};
void EnterMineAndDigForNugget::Enter(Miner *miner)
{
    // if the miner is not already located at the goldmine, he must
    // change location to the gold mine
    if (miner->getlocation() != goldmine)
    {
        cout << "\n"
             << getNameOfEntity(miner->ID()) << ": "
             << "Walkin to the gold mine";

        miner->changeLocation(goldmine);
    }
}

void EnterMineAndDigForNugget::Execute(Miner *miner)
{
    // the miner digs for gold until he is carrying in excess of MaxNuggets
    // If he gets thirsty during his digging he stops work and
    // changes state to go to the salmon forr a whiskey
    miner->addToGoldCarried(1);

    // diggin' is hard work
    miner->increaseFatigue();

    cout << "\n"
         << getNameOfEntity(miner->ID()) << ": "
         << "Pickin' up a nugget";

    // if enough gold mined, go and put it in the bank
    if (miner->isPocketsFull())
    {
        // miner->ChangeState()
    }
}