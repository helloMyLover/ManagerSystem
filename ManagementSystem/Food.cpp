// Food.cpp : 实现文件
//

#include "stdafx.h"
#include "ManagementSystem.h"
#include "Food.h"
#include "afxdialogex.h"


// CFood 对话框

IMPLEMENT_DYNAMIC(CFood, CDialogEx)

CFood::CFood(CWnd* pParent /*=NULL*/)
	: CDialogEx(CFood::IDD, pParent)
{

}

CFood::~CFood()
{
}

void CFood::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CFood, CDialogEx)
	ON_BN_CLICKED(IDC_BTN_ORDER, &CFood::OnBnClickedBtnOrder)
	ON_BN_CLICKED(IDC_BUTTON1, &CFood::OnBnClickedButton1)
END_MESSAGE_MAP()


// CFood 消息处理程序


void CFood::OnBnClickedBtnOrder()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CFood::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
}


BOOL CFood::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	m_bitmap.LoadBitmap(IDB_NOFOOD);
	m_static.Create(_T("图标"),WS_CHILD|WS_VISIBLE|SS_CENTERIMAGE|SS_BITMAP|SS_CENTER,CRect(10,20,30,50),
		this,6666);
	m_static.ModifyStyle(0xf,SS_BITMAP);
	m_static.SetBitmap((HBITMAP)m_bitmap);
	m_static.ShowWindow(TRUE);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}
