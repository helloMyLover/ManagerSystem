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

class Cemployee
{
	UINT ID;
	char * NAME;
	CString PHONE;
	CString POST; //职务
	CString ID_CARD; //身份证号码
	virtual bool order(void);
};

class CCook:public Cemployee
{
	bool order(void);
};

class CWaiter:public Cemployee
{
	bool order(void);
};

class CManager:public Cemployee
{
	int addEmployee(void);  //增删员工
	int deleteEmployee(void);
	bool order(void);
};
