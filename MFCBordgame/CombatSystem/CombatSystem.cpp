#include "pch.h"
#include "CombatSystem.h"

CombatSystem::CombatSystem() {}
CombatSystem::~CombatSystem() {}

bool CombatSystem::CanStartCombat(int attackerId, int defenderId)
{
    // TODO: Check adjacency, coin cost, etc.
    return false;
}

void CombatSystem::ResolveCombat(int attackerId, int defenderId)
{
    // TODO: Compute outcome and apply changes
}