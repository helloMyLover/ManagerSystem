// Food.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ManagementSystem.h"
#include "Food.h"
#include "afxdialogex.h"


// CFood �Ի���

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


// CFood ��Ϣ�������


void CFood::OnBnClickedBtnOrder()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}
