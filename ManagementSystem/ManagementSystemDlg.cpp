
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

#define IDC_TEXT_FOOD

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
	ON_WM_CTLCOLOR()
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

	//先加载两个菜式，作为测试，后续移除

	createFoodPicCtrl();

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


//添加背景
BOOL CManagementSystemDlg::OnEraseBkgnd(CDC* pDC)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CDC mendc;
	mendc.CreateCompatibleDC(pDC);
	CBitmap * pOldBitmap = mendc.SelectObject(&m_bitmap);
	pDC->BitBlt(0,0,bmp.bmWidth,bmp.bmHeight,&mendc,0,0,SRCCOPY);
	mendc.SelectObject(&pOldBitmap);
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

	//CWnd * pwnd2=GetDlgItem(IDC_MENU);
	//pwnd2->SetWindowPos(NULL,0,0,1200,750,SWP_NOMOVE);

	CWnd * pwnd3=GetDlgItem(IDC_BTN_SURE);
	pwnd3->SetWindowPos(NULL,1250,900,0,0,SWP_NOZORDER | SWP_NOSIZE);

	

	// TODO: 在此处添加消息处理程序代码
}




void CManagementSystemDlg::OnBnClickedBtnSure()
{
	// TODO: 在此添加控件通知处理程序代码
	
}



void CManagementSystemDlg::createFoodPicCtrl()
{
	//读取数据库现有食谱 加载
	CPoint picPoint;
	CPoint txtPoint;
	CPoint numPoint;
	CPoint btnPoint;

	CStatic * m_txt=new CStatic[5];
	//for(int i=0;i<5;i++)
	//	m_text.push_back(m_txt[i]);
	

	//m_pic.resize(5);
	mBitmapDrawFood.LoadBitmap(IDB_FOOD);
	//CRect参数1和2确定控件右上角落点在哪，参数2和3确定控件的大小
	for (int i=0;i<5;i++)
	{
		picPoint.x=200;
		picPoint.y=200;

	//	m_pic[i].Create(_T("pic1"),WS_CHILD|WS_VISIBLE|SS_BITMAP|SS_CENTERIMAGE,CRect(picPoint.x,picPoint.y,picPoint.x+121,picPoint.y+100),this,6667+4*i);
	//	if(m_pic[i].GetBitmap() ==NULL)
	//		m_pic[i].SetBitmap((HBITMAP)mBitmapDrawFood);
	//	//设置为位图模式，不可去掉
	//	m_pic[i].ModifyStyle(0xf,SS_BITMAP);
	////	m_pic[].push_back(m_picTemp);
	//	m_pic[i].ShowWindow(TRUE);

		txtPoint.x=picPoint.x+121+10;
		txtPoint.y=picPoint.y+20+i*100;  // +10位置调整

		m_txt[i].Create(_T("foodTip"),WS_CHILD|WS_VISIBLE,CRect(txtPoint.x,txtPoint.y,txtPoint.x+800,txtPoint.y+20),this,6668+i);
		m_txt[i].SetWindowText(_T("煎牛柳     Seared beef fillet  / ceps mushroom ragout  / garlic cheese mash potato"));
		//	UpdateData(TRUE);

		//numPoint.x=txtPoint.x+800+100;  //800为前面一项的大小，
		//numPoint.y=txtPoint.y;

		//m_num[i].Create(_T("num"),WS_VISIBLE|WS_CHILD,CRect(numPoint.x,numPoint.y,numPoint.x+10,numPoint.y+20),this,6669+4*i);
		//m_num[i].SetWindowText(_T("0"));

		//btnPoint.x=txtPoint.x+800+100+100;
		//btnPoint.y=txtPoint.y;

		//m_btn[i].Create(_T("+"),WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON,CRect(btnPoint.x,btnPoint.y,btnPoint.x+50,btnPoint.y+20),this,4*6670);
		//m_btn[i].ShowWindow(SW_SHOW);
	}
}


HBRUSH CManagementSystemDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何特性

	if (nCtlColor == CTLCOLOR_STATIC)
	{
		pDC->SetTextColor(RGB(255,215,0)); //设置字体颜色
		pDC->SetBkMode(TRANSPARENT);      //设置背景透明
		return HBRUSH(GetStockObject(HOLLOW_BRUSH));
	}

	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return hbr;
}
