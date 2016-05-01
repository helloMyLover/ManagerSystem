// GuideUI.cpp : 实现文件
//

#include "stdafx.h"
#include "ManagementSystem.h"
#include "GuideUI.h"
#include "afxdialogex.h"
#include <iostream>


// CGuideUI 对话框

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


// CGuideUI 消息处理程序


void CGuideUI::OnBnClickedBtnClose()
{
	// TODO: 在此添加控件通知处理程序代码
	int msg=MessageBox(NULL,_T("确认关闭？"),MB_OKCANCEL);
	if(msg== IDOK)
		CDialogEx::OnOK();
}


void CGuideUI::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 在此处添加消息处理程序代码
	// 不为绘图消息调用 CDialogEx::OnPaint()
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
