#pragma once

#include <vector>
#include <string>

// 게임의 단계 정의
enum class ETurnPhase {
    Setup,
    RollDice,
    Move,
    BuyOrPass,
    CombatCheck,
    SpecialSpace,
    EndTurn
};

// 특수 칸 종류 정의
enum class ESpecialSpaceType {
    Island,
    WorldTour,
    CoinBank
};

// 플레이어 정보 구조체
struct Player {
    int id;
    std::string name;
    int position;   // 타일 인덱스
    int coins;
    // TODO: 소유 타일 정보 등 추가
};

// 게임 설정 구조체
struct GameConfig {
    int numPlayers;
    int targetTurns;
    bool skipSetupDialog;
};

// 전체 게임 상태 관리 클래스
class GameState {
public:
    GameState();
    void Reset();  // 게임 상태 초기화

    GameConfig config;
    std::vector<Player> players;
	int currentPlayerIndex;     // 현재 턴 플레이어 인덱스
	int currentTurnCount;       // 현재 턴 카운트
	ETurnPhase phase;           // 현재 턴 단계
	ESpecialSpaceType specialType;      // 특수 칸 종류
};