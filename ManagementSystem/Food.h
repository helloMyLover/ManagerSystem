#pragma once


// CFood �Ի���

class CFood : public CDialogEx
{
	DECLARE_DYNAMIC(CFood)

public:
	CFood(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CFood();

// �Ի�������
	enum { IDD = IDD_DLG_FOOD };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtnOrder();
	afx_msg void OnBnClickedButton1();
	virtual BOOL OnInitDialog();

	CStatic m_static;
	CBitmap m_bitmap;
};
