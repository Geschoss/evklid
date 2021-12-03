#include "Miner.h"

void Miner::Update()
{
    m_iThirst += 1;
    if (m_pCurrentState)
    {
        m_pCurrentState->Execute(this);
    }
}

void Miner::ChangeState(State *pNewState)
{
    // make sure both state are valid before attempting to
    // call their methods
    assert(m_pCurrentState && pNewState);

    // call the exit method of the existing state
    m_pCurrentState->Exit(this);

    // change state to the new state
    m_pCurrentState = pNewState;

    // call the entry method of the new state
    m_pCurrentState->Enter(this);
};

void Miner::addToGoldCarried(const int val)
{
    m_iGoldCarried += val;

    if (m_iGoldCarried < 0)
    {
        m_iGoldCarried = 0;
    }
}