
// MainFrm.h: CMainFrame 클래스의 인터페이스
//
#include "Common/GameState.h"
#include "Common/GameController.h"
#include "TurnManager/TurnManager.h"
#include "TileManager/TileManager.h"
#include "CombatSystem/CombatSystem.h"
#include "SpecialSpace/SpecialSpace.h"
#include "CMainMapDlg.h"  // 메인 맵


#pragma once

class CMainFrame : public CMDIFrameWnd
{
	DECLARE_DYNAMIC(CMainFrame)
public:
	CMainFrame() noexcept;

// 특성입니다.
public:

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// 구현입니다.
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // 컨트롤 모음이 포함된 멤버입니다.
	CToolBar          m_wndToolBar;
	CStatusBar        m_wndStatusBar;

// 생성된 메시지 맵 함수
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	DECLARE_MESSAGE_MAP()

private:
	GameState      m_gameState;
	GameController m_controller;
	TurnManager    m_turnMgr;
	TileManager    m_tileMgr;
	CombatSystem   m_combatSys;
	SpecialSpace   m_specialSpc;
	CMainMapDlg	   m_mapDlg;	// 메인 맵
};


