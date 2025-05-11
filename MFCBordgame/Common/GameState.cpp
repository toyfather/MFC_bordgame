#include "pch.h"
#include "GameState.h"

GameState::GameState() {
    Reset();
}

void GameState::Reset() {
    players.clear();
    currentPlayerIndex = 0;
    currentTurnCount = 0;
    phase = ETurnPhase::Setup;
    specialType = ESpecialSpaceType::CoinBank;
}