
// ManagementSystemDlg.h : ͷ�ļ�
//

#pragma once


// CManagementSystemDlg �Ի���
class CManagementSystemDlg : public CDialogEx
{
// ����
public:
	CManagementSystemDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MANAGEMENTSYSTEM_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtnTest();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	CBitmap m_bitmap;
	BITMAP bmp;
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnBnClickedBtnSure();
	template <typename T>void createCtrl(T* STR,CRect Coord,UINT IDC);
	
};


