
// ManagementSystemDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "ManagementSystem.h"
#include "ManagementSystemDlg.h"
#include "afxdialogex.h"
#include "Employee.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#define  test 1

#if test
#include "GuideUI.h"
#include "Food.h"
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()



// CManagementSystemDlg 对话框


CManagementSystemDlg::CManagementSystemDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CManagementSystemDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CManagementSystemDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CManagementSystemDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_TEST, &CManagementSystemDlg::OnBnClickedBtnTest)
	ON_WM_ERASEBKGND()
	ON_WM_SIZE()
	ON_BN_CLICKED(IDC_BTN_SURE, &CManagementSystemDlg::OnBnClickedBtnSure)
END_MESSAGE_MAP()


// CManagementSystemDlg 消息处理程序

BOOL CManagementSystemDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	//改变窗口大小
	m_bitmap.LoadBitmap(IDB_PIC_BACKGROUND);
	m_bitmap.GetBitmap(&bmp);
	SetWindowPos(this,0,0,bmp.bmWidth,bmp.bmHeight,SWP_NOZORDER|SWP_NOMOVE);  //
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE


}

void CManagementSystemDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CManagementSystemDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CManagementSystemDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CManagementSystemDlg::OnBnClickedBtnTest()
{
	// TODO: 在此添加控件通知处理程序代码
#if  test
	CEmployee dlg;
	dlg.DoModal();
#else 
	CFood DLG;
	DLG.DoModal();
#endif
}




BOOL CManagementSystemDlg::OnEraseBkgnd(CDC* pDC)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CDC mendc;
	mendc.CreateCompatibleDC(pDC);

	CBitmap * pOldBitmap = mendc.SelectObject(&m_bitmap);
	pDC->BitBlt(0,0,bmp.bmWidth,bmp.bmHeight,&mendc,0,0,SRCCOPY);
	mendc.SelectObject(pOldBitmap);
	m_bitmap.DeleteObject();
	mendc.DeleteDC();

	return true;
	//return CDialogEx::OnEraseBkgnd(pDC);
}


void CManagementSystemDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	CRect oldrc;
	GetWindowRect(oldrc);
	CWnd * pwnd = GetDlgItem(IDOK);
//	if(pwnd->GetSafeHwnd())
//		pwnd->MoveWindow(cx-20,);
	pwnd->SetWindowPos(NULL,1425,11,0,0,SWP_NOZORDER | SWP_NOSIZE);

	CWnd * pwnd2=GetDlgItem(IDC_MENU);
	pwnd2->SetWindowPos(NULL,0,0,1200,750,SWP_NOMOVE);

	CWnd * pwnd3=GetDlgItem(IDC_BTN_SURE);
	pwnd3->SetWindowPos(NULL,1250,900,0,0,SWP_NOZORDER | SWP_NOSIZE);


	// TODO: 在此处添加消息处理程序代码
}




void CManagementSystemDlg::OnBnClickedBtnSure()
{
	// TODO: 在此添加控件通知处理程序代码
	
}


//创建控件并显示图片
template <typename T>
T CManagementSystemDlg::createCtrl(T str,CRect Coord,UINT IDC)
{
	T * p=NULL;
	p = new T;
	ASSERT_VALID(p);
	T->Create(str,  WS_CHILD|WS_VISIBLE|SS_CENTER, Coord, this, IDC);
	return p;
}
