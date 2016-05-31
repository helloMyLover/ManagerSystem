// MEAT.cpp : 实现文件
//

#include "stdafx.h"
#include "ManagementSystem.h"
#include "MEAT.h"
#include "afxdialogex.h"


// CMEAT 对话框

IMPLEMENT_DYNAMIC(CMEAT, CDialogEx)

CMEAT::CMEAT(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMEAT::IDD, pParent)
{

}

CMEAT::~CMEAT()
{
}

void CMEAT::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CMEAT, CDialogEx)
END_MESSAGE_MAP()


// CMEAT 消息处理程序
