#pragma once
#include "afxdialogex.h"


// CMainMapDlg 대화 상자

class CMainMapDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CMainMapDlg)

public:
	CMainMapDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CMainMapDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MAIN_MAP };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
};
