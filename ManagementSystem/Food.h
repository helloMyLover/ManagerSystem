#pragma once


// CFood 对话框

class CFood : public CDialogEx
{
	DECLARE_DYNAMIC(CFood)

public:
	CFood(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CFood();

// 对话框数据
	enum { IDD = IDD_DLG_FOOD };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtnOrder();
	afx_msg void OnBnClickedButton1();
	virtual BOOL OnInitDialog();

	CStatic m_static;
	CBitmap m_bitmap;
};
