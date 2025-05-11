#pragma once
#include <vector>
#include "GameState.h"

class TileManager
{
public:
    TileManager();
    ~TileManager();

    // Load tile data (price, attributes)
    void LoadTiles();

    // Handle purchase; returns true if successful
    bool PurchaseTile(int playerId);

    // Process landing on a tile (buy, pass, etc.)
    void HandleTileAction(int playerId);
};