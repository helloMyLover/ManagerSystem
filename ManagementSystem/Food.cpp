// Food.cpp : 实现文件
//

#include "stdafx.h"
#include "ManagementSystem.h"
#include "Food.h"
#include "afxdialogex.h"

#define IDC_NUM_TEXT1 6671
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
	DDX_Text(pDX,6671,myCount);
}


BEGIN_MESSAGE_MAP(CFood, CDialogEx)
	ON_COMMAND_RANGE(10000,12000,&CFood::addOrCutCount)
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CFood 消息处理程序



BOOL CFood::OnInitDialog()
{
	initResouce();
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	//m_bitmap.LoadBitmap(IDB_NOFOOD);
	//m_static.Create(_T("图标"),WS_CHILD|WS_VISIBLE|SS_CENTERIMAGE|SS_BITMAP|SS_CENTER,CRect(10,20,30,50),
	//	this,6666);
	//m_static.ModifyStyle(0xf,SS_BITMAP);
	//m_static.SetBitmap((HBITMAP)m_bitmap);
	//m_static.ShowWindow(TRUE);
	createFoodListInstantiation(m_picTemp,m_txtTemp,m_txtPriceTemp,m_cutBtnTemp,m_numTemp,m_addBtnTemp);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


BOOL CFood::DestroyWindow()
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


void CFood::initResouce()
{
	//加载按钮图标
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

void CFood::createFoodList()
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

void CFood::createFoodListInstantiation(CStatic * m_picTemp,CStatic * m_txtTemp,CStatic *m_textPriceTemp,CStatic * m_cutBtnTemp,CEdit *m_numTemp,CStatic * m_addBtnTemp)
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

HBRUSH CFood::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
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


void CFood::addOrCutCount(UINT ID)
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


unsigned __stdcall CFood::sleepChangeButton(void *pArgument)
{
	CFood *handle =(CFood *)pArgument;
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