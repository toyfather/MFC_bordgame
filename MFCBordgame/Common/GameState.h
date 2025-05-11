#pragma once

#include <vector>
#include <string>

// ������ �ܰ� ����
enum class ETurnPhase {
    Setup,
    RollDice,
    Move,
    BuyOrPass,
    CombatCheck,
    SpecialSpace,
    EndTurn
};

// Ư�� ĭ ���� ����
enum class ESpecialSpaceType {
    Island,
    WorldTour,
    CoinBank
};

// �÷��̾� ���� ����ü
struct Player {
    int id;
    std::string name;
    int position;   // Ÿ�� �ε���
    int coins;
    // TODO: ���� Ÿ�� ���� �� �߰�
};

// ���� ���� ����ü
struct GameConfig {
    int numPlayers;
    int targetTurns;
    bool skipSetupDialog;
};

// ��ü ���� ���� ���� Ŭ����
class GameState {
public:
    GameState();
    void Reset();  // ���� ���� �ʱ�ȭ

    GameConfig config;
    std::vector<Player> players;
	int currentPlayerIndex;     // ���� �� �÷��̾� �ε���
	int currentTurnCount;       // ���� �� ī��Ʈ
	ETurnPhase phase;           // ���� �� �ܰ�
	ESpecialSpaceType specialType;      // Ư�� ĭ ����
};