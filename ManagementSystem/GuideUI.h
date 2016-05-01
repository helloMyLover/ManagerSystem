#pragma once
#include "afxcmn.h"
#include "afxwin.h"


// CGuideUI 对话框

class CGuideUI : public CDialogEx
{
	DECLARE_DYNAMIC(CGuideUI)

public:
	CGuideUI(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CGuideUI();

// 对话框数据
	enum { IDD = IDD_DLD_GUIDE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()


public:
	// 启动主程序前的缓冲时间
	CButton Btn_close;
	afx_msg void OnBnClickedBtnClose();
	CStatic pic_Guide;
	CProgressCtrl pro_Guide;
	afx_msg void OnPaint();
	BITMAP bmp1;
	CBitmap m_bitmap;
	void Create(UINT picID);
};
