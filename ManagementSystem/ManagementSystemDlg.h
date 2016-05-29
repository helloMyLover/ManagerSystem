
// ManagementSystemDlg.h : ͷ�ļ�
//

#pragma once

#include <vector>
using namespace std;
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
	
public:
	//����һ����ͼ����
	CBitmap mBitmapDrawFood;
	vector<CStatic *> m_pic;
	//����һ�����������ֵ��ı�����
	vector<CStatic *> m_text;
	//����һ����ʾ�۸���ı�����
	vector<CStatic *> m_textPrice;
	//����һ�����������İ�ť
	vector<CButton *>m_btnCut;
	//����һ����ʾ�������ı�����
	int myCount;
	//vector<CStatic *> m_num;
	vector<CEdit *>  m_num;
	//����һ�����������İ�ť
	vector<CStatic *> m_btnAdd;
	void createFoodList();
	CStatic * m_picTemp;
	CStatic * m_txtTemp;
	CStatic * m_txtPriceTemp;
	CButton * m_cutBtnTemp;
	CEdit   * m_numTemp;
	CStatic * m_addBtnTemp;

	void createFoodListInstantiation(CStatic * m_picTemp,CStatic * m_txtTemp,CStatic *m_textPriceTemp,CButton * m_cutBtnTemp,CEdit *m_numTemp,CStatic * m_addBtnTemp);

	//CStatic m_picTemp;
	//CStatic m_txt;
//	CStatic * m_txt;
	void createFoodPicCtrl();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	virtual BOOL DestroyWindow();
	static UINT ctrlID;
};


class CFoodList
{
public:
	CFoodList();
	UINT ID;
	string text;
	
	float price;
	CBitmap mBitmapDrawFood;

private:
	int count; //���� Ӧ��ֻͨ����ť���ı� ��������س�����

};


