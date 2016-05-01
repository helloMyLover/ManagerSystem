#pragma once
#include "afxcmn.h"
#include "DataBaseAdo.h"

// CEmployee 对话框

class CEmployee : public CDialogEx
{
	DECLARE_DYNAMIC(CEmployee)

public:
	CEmployee(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CEmployee();

// 对话框数据
	enum { IDD = IDD_DLG_EMPLOYEE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_ListCtrl;
	virtual BOOL OnInitDialog();
	CDataBaseAdo m_DataBase;
	afx_msg void OnBnClickedBtnQuit();
	afx_msg void OnBnClickedBtnShow();
	
};
