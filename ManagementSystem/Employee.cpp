// Employee.cpp : 实现文件
//

#include "stdafx.h"
#include "ManagementSystem.h"
#include "Employee.h"
#include "afxdialogex.h"

// CEmployee 对话框

IMPLEMENT_DYNAMIC(CEmployee, CDialogEx)

CEmployee::CEmployee(CWnd* pParent /*=NULL*/)
	: CDialogEx(CEmployee::IDD, pParent)
{

}

CEmployee::~CEmployee()
{

}

void CEmployee::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_ListCtrl);
}


BEGIN_MESSAGE_MAP(CEmployee, CDialogEx)
	ON_BN_CLICKED(IDC_BTN_QUIT, &CEmployee::OnBnClickedBtnQuit)
	ON_BN_CLICKED(IDC_BTN_SHOW, &CEmployee::OnBnClickedBtnShow)
END_MESSAGE_MAP()


// CEmployee 消息处理程序


BOOL CEmployee::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	// TODO:  在此添加额外的初始化
	//连接数据库
	CRect rc;
	m_ListCtrl.GetWindowRect(&rc);
	//LVS_EX_GRIDLINES是希望显示网格；LVS_EX_FULLROWSELECT是希望被选中时整行
	//LVS_EX_HEADERDRAGDROP是让其支持点击表头排序；LVS_EX_TWOCLICKACTIVATE是希望有鼠标在未被选中的行上移动的时候有一些效果 
//	m_ListCtrl.InsertColumn(0,_T("序号"),LVCFMT_CENTER,rc.Size().cx/4,0);
	m_ListCtrl.InsertColumn(0,_T("工号"),LVCFMT_CENTER,rc.Size().cx/3,0);
	m_ListCtrl.InsertColumn(1,_T("姓名"),LVCFMT_CENTER,rc.Size().cx/3,1);
	m_ListCtrl.InsertColumn(2,_T("联系号码"),LVCFMT_CENTER,rc.Size().cx/3,2);
	m_ListCtrl.SetExtendedStyle(m_ListCtrl.GetExtendedStyle()| LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT | LVS_EX_HEADERDRAGDROP /*| LVS_EX_TWOCLICKACTIVATE*/);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void CEmployee::OnBnClickedBtnQuit()
{
	// TODO: 在此添加控件通知处理程序代码
	if (m_DataBase.m_pConnection->State)  //防止重复调用
	{
		m_DataBase.m_pConnection->Close();
		m_DataBase.m_pConnection=NULL;
	}
}

void CEmployee::OnBnClickedBtnShow()
{
	// TODO: 在此添加控件通知处理程序代码
	bool t=m_DataBase.Open();
	if( t==true )
	{
		vector<_variant_t> vName;
		vName.push_back("ID");
		vName.push_back("NAME");
		vName.push_back("Phone");
		vector<vector<_variant_t> > vResult(m_DataBase.Select(::SysAllocString(L"SELECT * FROM Employee"),vName));
		m_ListCtrl.DeleteAllItems();
		for(int i=0; i<vResult.size(); ++i )
		{
			m_ListCtrl.InsertItem(i,  m_DataBase.VariantToCString(vResult.at(i).at(0)) );
			m_ListCtrl.SetItemText(i, 1, m_DataBase.VariantToCString(vResult.at(i).at(1)) ); 
			m_ListCtrl.SetItemText(i, 2, m_DataBase.VariantToCString(vResult.at(i).at(2)) ); 
		}
	//	m_DataBase.Close();// 会报错？？
	}
	else
	{
		MessageBox(_T("open database failure"),_T("Warning"));
	}
}
