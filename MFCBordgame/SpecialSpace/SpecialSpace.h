#pragma once
#include "GameState.h"

class SpecialSpace
{
public:
    SpecialSpace();
    ~SpecialSpace();

    // Handle World Tour space logic
    void HandleWorldTour(int playerId);

    // Handle Island space logic
    void HandleIsland(int playerId);

    // Handle Coin Bank space logic
    void HandleCoinBank(int playerId);
};