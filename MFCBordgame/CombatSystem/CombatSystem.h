#pragma once

class CombatSystem
{
public:
    CombatSystem();
    ~CombatSystem();

    // Check if combat can start between two players
    bool CanStartCombat(int attackerId, int defenderId);

    // Resolve combat outcome (ownership, stats)
    void ResolveCombat(int attackerId, int defenderId);
};