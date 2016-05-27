
// ManagementSystemDlg.h : 头文件
//

#pragma once

#include <vector>
using namespace std;
// CManagementSystemDlg 对话框
class CManagementSystemDlg : public CDialogEx
{
// 构造
public:
	CManagementSystemDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_MANAGEMENTSYSTEM_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持

// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
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
	//定义一个绘图变量
	CBitmap mBitmapDrawFood;
	vector<CStatic *> m_pic;
	//定义一个描述性文字的文本变量
	vector<CStatic *> m_text;
	//定义一个显示数量的文本变量
	vector<CStatic *> m_num;
	//定义一个增加数量的按钮
	vector<CButton *> m_btn;
	void createFoodList();
	void createFoodListInstantiation(CStatic * m_picTemp,CStatic * m_txtTemp,CStatic * m_numTemp,CButton * m_btnTemp);
	
	//CStatic m_picTemp;
	//CStatic m_txt;
//	CStatic * m_txt;
	void createFoodPicCtrl();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	virtual BOOL DestroyWindow();
	static UINT ctrlID;
};


