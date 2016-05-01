// GuideUI.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ManagementSystem.h"
#include "GuideUI.h"
#include "afxdialogex.h"
#include <iostream>


// CGuideUI �Ի���

IMPLEMENT_DYNAMIC(CGuideUI, CDialogEx)

CGuideUI::CGuideUI(CWnd* pParent /*=NULL*/)
	: CDialogEx(CGuideUI::IDD, pParent)
{
//	guideProBar.CenterWindow();
	//guideProBar.SetRange(4,45);
	////Load guide picture
	//CBitmap bitmap;
	//HBITMAP hBmp;
	//bitmap.LoadBitmapW(IDB_PIC_GUIDE);
	//hBmp=(HBITMAP)bitmap.GetSafeHandle();
	//
	
	//CRect rect;
	//GetWindowRect(&rect);
	//pic_Guide.SetBitmap(bmp1);

	//load processCtrl 
	//OnPaint();
//	pro_Guide.SetRange(0,100);


}

CGuideUI::~CGuideUI()
{
}

void CGuideUI::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BTN_CLOSE, Btn_close);
	DDX_Control(pDX, IDC_PIC_GUIDE, pic_Guide);
	DDX_Control(pDX, IDC_PRO_GUIDE, pro_Guide);
}


BEGIN_MESSAGE_MAP(CGuideUI, CDialogEx)
	
	ON_BN_CLICKED(IDC_BTN_CLOSE, &CGuideUI::OnBnClickedBtnClose)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CGuideUI ��Ϣ�������


void CGuideUI::OnBnClickedBtnClose()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int msg=MessageBox(NULL,_T("ȷ�Ϲرգ�"),MB_OKCANCEL);
	if(msg== IDOK)
		CDialogEx::OnOK();
}


void CGuideUI::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: �ڴ˴������Ϣ����������
	// ��Ϊ��ͼ��Ϣ���� CDialogEx::OnPaint()
	CRect rect;
	GetClientRect(&rect);
	m_bitmap.GetBitmap(&bmp1);
	CDC mendc;
	mendc.CreateCompatibleDC(&dc);
	mendc.SelectObject(&m_bitmap);
	//use it ,it will show black 
	//dc.StretchBlt(rect.left,rect.top,rect.Width(),rect.Height(),&mendc,0,0,bmp1.bmWidth,bmp1.bmHeight,0);
	
	//this can show the pic why? 
	dc.BitBlt(0,0,bmp1.bmWidth,bmp1.bmHeight,&mendc,0,0,SRCCOPY); 


}

void CGuideUI::Create(UINT picID)
{
	m_bitmap.LoadBitmapW(picID);
	BITMAP bitmap;
	m_bitmap.GetBitmap(&bitmap);
	CreateEx(0,
		AfxRegisterWndClass(0,AfxGetApp()->LoadStandardCursor(IDC_ARROW)),
		NULL,WS_POPUP | WS_VISIBLE , 0 , 0 ,bitmap.bmWidth,bitmap.bmHeight,0,0);
	UpdateWindow();
}
