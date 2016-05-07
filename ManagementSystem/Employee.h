#pragma once
#include "afxcmn.h"
#include "DataBaseAdo.h"

// CEmployee �Ի���

class CEmployee : public CDialogEx
{
	DECLARE_DYNAMIC(CEmployee)

public:
	CEmployee(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CEmployee();

// �Ի�������
	enum { IDD = IDD_DLG_EMPLOYEE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

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
	CString POST; //ְ��
	CString ID_CARD; //���֤����
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
	int addEmployee(void);  //��ɾԱ��
	int deleteEmployee(void);
	bool order(void);
};
