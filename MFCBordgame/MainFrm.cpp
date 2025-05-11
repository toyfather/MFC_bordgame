
// MainFrm.cpp: CMainFrame 클래스의 구현
//

#include "pch.h"
#include "framework.h"
#include "MFCBordgame.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

IMPLEMENT_DYNAMIC(CMainFrame, CMDIFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CMDIFrameWnd)
	ON_WM_CREATE()
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // 상태 줄 표시기
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

// CMainFrame 생성/소멸

CMainFrame::CMainFrame() noexcept
	: m_gameState()
	, m_controller(m_gameState)
	, m_turnMgr()
	, m_tileMgr()
	, m_combatSys()
	, m_specialSpc()
{
	// TODO: 여기에 멤버 초기화 코드를 추가합니다.
	// 특수칸 모듈 연결
	m_controller.onSpecialSpace = [&](ESpecialSpaceType type) {
		switch (type)
		{
		case ESpecialSpaceType::WorldTour:
			m_specialSpc.HandleWorldTour(m_gameState.currentPlayerIndex);
			break;
		case ESpecialSpaceType::Island:
			m_specialSpc.HandleIsland(m_gameState.currentPlayerIndex);
			break;
		case ESpecialSpaceType::CoinBank:
			m_specialSpc.HandleCoinBank(m_gameState.currentPlayerIndex);
			break;
		}
	};
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CMDIFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP | CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("도구 모음을 만들지 못했습니다.\n");
		return -1;      // 만들지 못했습니다.
	}

	if (!m_wndStatusBar.Create(this))
	{
		TRACE0("상태 표시줄을 만들지 못했습니다.\n");
		return -1;      // 만들지 못했습니다.
	}
	m_wndStatusBar.SetIndicators(indicators, sizeof(indicators)/sizeof(UINT));

	// TODO: 도구 모음을 도킹할 수 없게 하려면 이 세 줄을 삭제하십시오.
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);

	// 여기부터 수정해보자
	// (1) 모델리스 다이얼로그 생성
	m_mapDlg.Create(IDD_MAIN_MAP, this);

	// (2) 다이얼로그 위치/크기 조정: 클라이언트 영역 전체 사용
	CRect rc;
	GetClientRect(&rc);
	m_mapDlg.MoveWindow(&rc);

	// (3) 화면에 보이기
	m_mapDlg.ShowWindow(SW_SHOW);

	AfxMessageBox(_T("==StartGame=="));

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CMDIFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return TRUE;
}

// CMainFrame 진단

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CMDIFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CMDIFrameWnd::Dump(dc);
}
#endif //_DEBUG


// CMainFrame 메시지 처리기
