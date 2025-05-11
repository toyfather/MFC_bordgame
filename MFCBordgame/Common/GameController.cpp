#include "pch.h"
#include "GameController.h"

GameController::GameController(GameState& state)
    : onSpecialSpace(nullptr)
    , m_state(state) {
        {
            // onSpecialSpace 콜백 기본값 설정 등 추가 초기화 가능
            onSpecialSpace = nullptr;
        }
}

GameController::~GameController() {}

void GameController::StartGame() {
    // TODO: 설정 대화상자 띄우기, 플레이어 순서 초기화
    AfxMessageBox(_T("==StartGame=="));
}

void GameController::NextPhase() {
    // TODO: ETurnPhase enum 기반으로 각 모듈 호출
    switch (m_state.phase)
    {
    case ETurnPhase::Setup:
        StartGame();
        m_state.phase = ETurnPhase::RollDice;
        break;

    case ETurnPhase::RollDice:

        break;

    case ETurnPhase::EndTurn:
        
        break;


    }
}

void GameController::Run() {
    // TODO: 타이머 또는 메시지 루프 후 NextPhase 호출
    AfxMessageBox(_T("==Run=="));
}




void GameController::NextPhase()
{
    
}
