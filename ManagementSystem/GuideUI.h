#pragma once
#include "afxcmn.h"
#include "afxwin.h"


// CGuideUI �Ի���

class CGuideUI : public CDialogEx
{
	DECLARE_DYNAMIC(CGuideUI)

public:
	CGuideUI(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CGuideUI();

// �Ի�������
	enum { IDD = IDD_DLD_GUIDE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()


public:
	// ����������ǰ�Ļ���ʱ��
	CButton Btn_close;
	afx_msg void OnBnClickedBtnClose();
	CStatic pic_Guide;
	CProgressCtrl pro_Guide;
	afx_msg void OnPaint();
	BITMAP bmp1;
	CBitmap m_bitmap;
	void Create(UINT picID);
};
