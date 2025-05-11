#include "pch.h"
#include "GameController.h"

GameController::GameController(GameState& state)
    : onSpecialSpace(nullptr)
    , m_state(state) {
        {
            // onSpecialSpace �ݹ� �⺻�� ���� �� �߰� �ʱ�ȭ ����
            onSpecialSpace = nullptr;
        }
}

GameController::~GameController() {}

void GameController::StartGame() {
    // TODO: ���� ��ȭ���� ����, �÷��̾� ���� �ʱ�ȭ
    AfxMessageBox(_T("==StartGame=="));
}

void GameController::NextPhase() {
    // TODO: ETurnPhase enum ������� �� ��� ȣ��
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
    // TODO: Ÿ�̸� �Ǵ� �޽��� ���� �� NextPhase ȣ��
    AfxMessageBox(_T("==Run=="));
}




void GameController::NextPhase()
{
    
}
