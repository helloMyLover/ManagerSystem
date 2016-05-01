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
END_MESSAGE_MAP()


// CFood 消息处理程序


void CFood::OnBnClickedBtnOrder()
{
	// TODO: 在此添加控件通知处理程序代码
}
