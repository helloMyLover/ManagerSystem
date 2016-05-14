
// ManagementSystemDlg.cpp : ʵ���ļ�
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


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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



// CManagementSystemDlg �Ի���


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


// CManagementSystemDlg ��Ϣ�������

BOOL CManagementSystemDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	//�ı䴰�ڴ�С
	m_bitmap.LoadBitmap(IDB_PIC_BACKGROUND);
	m_bitmap.GetBitmap(&bmp);
	SetWindowPos(this,0,0,bmp.bmWidth,bmp.bmHeight,SWP_NOZORDER|SWP_NOMOVE);  //
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE


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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CManagementSystemDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CManagementSystemDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CManagementSystemDlg::OnBnClickedBtnTest()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
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


	// TODO: �ڴ˴������Ϣ����������
}




void CManagementSystemDlg::OnBnClickedBtnSure()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	
}


//�����ؼ�����ʾͼƬ
template <typename T>
T CManagementSystemDlg::createCtrl(T str,CRect Coord,UINT IDC)
{
	T * p=NULL;
	p = new T;
	ASSERT_VALID(p);
	T->Create(str,  WS_CHILD|WS_VISIBLE|SS_CENTER, Coord, this, IDC);
	return p;
}
