#pragma once

#include "GameState.h"
#include <functional>

// ���� �帧 ���� Ŭ����
class GameController {
public:
    GameController(GameState& state);
    ~GameController();

    // �ʱ� ���� ��ȭ���� �� ���� ����
    void StartGame();

    // ���� �ܰ�(phase)�� ���� ó�� �� �ܰ� ��ȯ
    void NextPhase();

    // ���� ������ Ÿ�̸ӿ��� ȣ��
    void Run();

    // ���(Ư��ĭ ��) ����� �ݹ�
    std::function<void(ESpecialSpaceType)> onSpecialSpace;
private:
    GameState& m_state;  
};