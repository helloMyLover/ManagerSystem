
// ManagementSystemDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "ManagementSystem.h"
#include "ManagementSystemDlg.h"
#include "afxdialogex.h"
#include "Employee.h"
#include <exception>
#include <Windows.h>
#include "MEAT.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#define  test 1

#define IDC_TEXT_FOOD
#define IDC_NUM_TEXT1 6671

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
	: CDialogEx(CManagementSystemDlg::IDD, pParent),myCount(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CManagementSystemDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX,6671,myCount);
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
	ON_COMMAND_RANGE(10000,12000,&CManagementSystemDlg::addOrCutCount)
END_MESSAGE_MAP()


unsigned __stdcall CManagementSystemDlg::sleepChangeButton(void *pArgument)
{
	CManagementSystemDlg *handle =(CManagementSystemDlg *)pArgument;
	UINT  ID=handle->m_ID;
	HBITMAP hBmp[2];
	hBmp[0]=handle->hBmp[0];
	hBmp[1]=handle->hBmp[2];
	if (ID %2 !=0)
	{
		Sleep(100);
		handle->m_btnAdd[0]->SetBitmap(hBmp[0]);
		handle->m_btnAdd[0]->ShowWindow(SW_SHOW);
	}
	else
	{
		Sleep(100);
		handle->m_btnCut[0]->SetBitmap(hBmp[1]);
		handle->m_btnCut[0]->ShowWindow(SW_SHOW);
	}
	return 1;
}
void CManagementSystemDlg::addOrCutCount(UINT ID)
{
	m_ID=ID;
	if (ID %2 !=0)
	{
		m_btnAdd[0]->SetBitmap(hBmp[1]);
		m_btnAdd[0]->ShowWindow(SW_SHOW);
		myCount++;
		UpdateData(FALSE);
		hThread=(HANDLE)_beginthreadex(NULL,0,&sleepChangeButton,this,0,NULL);
	}
	else
	{

		m_btnCut[0]->SetBitmap(hBmp[3]);
		m_btnCut[0]->ShowWindow(SW_SHOW);
		if (myCount >0 )
		{
			myCount--;
		}
		UpdateData(FALSE);
		hThread=(HANDLE)_beginthreadex(NULL,0,&sleepChangeButton,this,0,NULL);
		
	}

}
// CManagementSystemDlg 消息处理程序

BOOL CManagementSystemDlg::OnInitDialog()
{
	initResouce();
	
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
	createFoodListInstantiation(m_picTemp,m_txtTemp,m_txtPriceTemp,m_cutBtnTemp,m_numTemp,m_addBtnTemp);
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

	mBitmapDrawFood.LoadBitmap(IDB_FOOD);
	//CRect参数1和2确定控件右上角落点在哪，参数2和3确定控件的大小
	for ( int i=0 ; i<5 ; i++ )
	{

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


BOOL CManagementSystemDlg::DestroyWindow()
{
	// TODO: 在此添加专用代码和/或调用基类
	  //避免内存泄漏 [] 号不能少，因为new的时候是数组，少了[]会报 触发一个焦点，堆破坏的错误
	for (int i=0;i<m_text.size();i++)
	{
		delete m_text[i];
	}
	for (int i=0;i<m_pic.size();i++)
	{
		delete m_pic[i];
	}
	for (int i=0;i<m_textPrice.size();i++)
	{
		delete m_textPrice[i];
	}
	for (int i=0;i<m_btnCut.size();i++)
	{
		delete m_btnCut[i];
	}
	for (int i=0;i<m_num.size();i++)
	{
		delete m_num[i];
	}
	for (int i=0;i<m_btnAdd.size();i++)
	{
		delete m_btnAdd[i];
	}
	return CDialogEx::DestroyWindow();
}

//图片 文字介绍 数量显示 按钮  //调整行里各元素的位置
void CManagementSystemDlg::createFoodList()
{
	CPoint picPoint;
	CPoint txtPoint;
	CPoint txtPricePoint;
	CPoint cutBtnPoint;
	CPoint numPoint;
	CPoint addBtnPoint;

	m_picTemp=new CStatic;
	m_txtTemp=new CStatic;
	m_txtPriceTemp=new CStatic;
	m_cutBtnTemp=new CStatic;
	m_numTemp=new CEdit;
	m_addBtnTemp=new CStatic;


	//创建图片控件
	picPoint.x=200;
	picPoint.y=200;
	m_picTemp->Create(_T("pic1"),WS_CHILD|WS_VISIBLE|SS_BITMAP|SS_CENTERIMAGE,CRect(picPoint.x,picPoint.y,picPoint.x+121,picPoint.y+100),this,6667);

	//创建文字控件
	txtPoint.x=picPoint.x+121+10;
	txtPoint.y=picPoint.y+20;  // +20是相对于图片的位置偏移，100是每行的间距  
	m_txtTemp->Create(_T("TextTips"),WS_CHILD|WS_VISIBLE,CRect(txtPoint.x,txtPoint.y,txtPoint.x+800,txtPoint.y+20),this,6668);

	//创建价格文本控件
	txtPricePoint.x=txtPoint.x+800+50;  //在前面800的大小下，再加50的空余
	txtPricePoint.y=txtPoint.y;
	m_txtPriceTemp->Create(_T("19 ¥"),WS_VISIBLE|WS_CHILD,CRect(txtPricePoint.x,txtPricePoint.y,txtPricePoint.x+50,txtPricePoint.y+20),this,6669);
	 
	//创建减按钮控件  SS_NOTIFY|
	cutBtnPoint.x=txtPoint.x+800+50+100;  //再加100空余
	cutBtnPoint.y=txtPoint.y-5;
	m_cutBtnTemp->Create(_T("-"),WS_CHILD|WS_VISIBLE|SS_NOTIFY|SS_BITMAP|SS_CENTERIMAGE,CRect(cutBtnPoint.x,cutBtnPoint.y,cutBtnPoint.x+30,cutBtnPoint.y+30),this,10000);

	//创建显示数量的文字控件
	numPoint.x=txtPoint.x+800+50+100+50+30;
	numPoint.y=txtPoint.y;
	m_numTemp->Create(WS_VISIBLE|WS_CHILD|SS_NOTIFY|ES_NUMBER,CRect(numPoint.x,numPoint.y,numPoint.x+30,numPoint.y+20),this,IDC_NUM_TEXT1);

	//创建增加按钮控件
	addBtnPoint.x=txtPoint.x+800+50+100+50+80;
	addBtnPoint.y=txtPoint.y-5;
	m_addBtnTemp->Create(_T("+"),WS_CHILD|WS_VISIBLE|SS_NOTIFY|SS_BITMAP|SS_CENTERIMAGE,CRect(addBtnPoint.x,addBtnPoint.y,addBtnPoint.x+30,addBtnPoint.y+30),this,10001);
	
}


void CManagementSystemDlg::createFoodListInstantiation(CStatic * m_picTemp,CStatic * m_txtTemp,CStatic * m_textPriceTemp,CStatic * m_cutBtnTemp,CEdit * m_numTemp,CStatic * m_addBtnTemp)
{

	m_pic.push_back(m_picTemp);
	int size=m_pic.size()-1;  

	if(m_pic[size]->GetBitmap() ==NULL)
		m_pic[size]->SetBitmap((HBITMAP)mBitmapDrawFood);

	//设置为位图模式，不可去掉
	m_pic[size]->ModifyStyle(0xf,SS_BITMAP);
	m_pic[size]->ShowWindow(TRUE);

	m_text.push_back(m_txtTemp);
	m_text[size]->SetWindowText(_T("煎牛柳     Seared beef fillet  / ceps mushroom ragout  / garlic cheese mash potato"));
	//	UpdateData(TRUE);

	m_textPrice.push_back(m_textPriceTemp);
	m_textPrice[size]->SetWindowText(_T("&19¥"));

	m_btnCut.push_back(m_cutBtnTemp);
	m_btnCut[size]->SetBitmap(hBmp[2]);
	m_btnCut[size]->ShowWindow(SW_SHOW);

	m_num.push_back(m_numTemp);
	myCount=1;
	UpdateData(FALSE);//将值传入界面

	m_btnAdd.push_back(m_addBtnTemp);
	m_btnAdd[size]->SetBitmap(hBmp[0]);
	m_btnAdd[size]->ShowWindow(SW_SHOW);
}

void CManagementSystemDlg::initResouce()
{
	//加载资源
	imgTemp[0].Load(_T("res/add.png"));
	imgTemp[1].Load(_T("res/addPress.png"));
	imgTemp[2].Load(_T("res/cut.png"));
	imgTemp[3].Load(_T("res/cutPress.png"));

	for (int i=0 ; i<4 ; i++)
	{
		hBmp[i]=imgTemp[i].Detach();
	}

	createFoodList();
}



