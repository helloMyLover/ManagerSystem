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
	ON_BN_CLICKED(IDC_BUTTON1, &CFood::OnBnClickedButton1)
END_MESSAGE_MAP()


// CFood ��Ϣ�������


void CFood::OnBnClickedBtnOrder()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CFood::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


BOOL CFood::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��

	m_bitmap.LoadBitmap(IDB_NOFOOD);
	m_static.Create(_T("ͼ��"),WS_CHILD|WS_VISIBLE|SS_CENTERIMAGE|SS_BITMAP|SS_CENTER,CRect(10,20,30,50),
		this,6666);
	m_static.ModifyStyle(0xf,SS_BITMAP);
	m_static.SetBitmap((HBITMAP)m_bitmap);
	m_static.ShowWindow(TRUE);

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}
