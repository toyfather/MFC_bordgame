#pragma once

#include "GameState.h"
#include <functional>

// 게임 흐름 제어 클래스
class GameController {
public:
    GameController(GameState& state);
    ~GameController();

    // 초기 설정 대화상자 및 순서 결정
    void StartGame();

    // 현재 단계(phase)에 따라 처리 및 단계 전환
    void NextPhase();

    // 메인 루프나 타이머에서 호출
    void Run();

    // 모듈(특수칸 등) 연결용 콜백
    std::function<void(ESpecialSpaceType)> onSpecialSpace;
private:
    GameState& m_state;  
};