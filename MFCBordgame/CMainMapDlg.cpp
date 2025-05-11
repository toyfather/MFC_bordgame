// CMainMapDlg.cpp: 구현 파일
//

#include "pch.h"
#include "MFCBordgame.h"
#include "afxdialogex.h"
#include "CMainMapDlg.h"


// CMainMapDlg 대화 상자

IMPLEMENT_DYNAMIC(CMainMapDlg, CDialogEx)

CMainMapDlg::CMainMapDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MAIN_MAP, pParent)
{
	
}

CMainMapDlg::~CMainMapDlg()
{
}

void CMainMapDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CMainMapDlg, CDialogEx)
END_MESSAGE_MAP()


// CMainMapDlg 메시지 처리기
