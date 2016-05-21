// Employee.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ManagementSystem.h"
#include "Employee.h"
#include "afxdialogex.h"

// CEmployee �Ի���

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


// CEmployee ��Ϣ�������


BOOL CEmployee::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	//�������ݿ�
	CRect rc;
	m_ListCtrl.GetWindowRect(&rc);
	//LVS_EX_GRIDLINES��ϣ����ʾ����LVS_EX_FULLROWSELECT��ϣ����ѡ��ʱ����
	//LVS_EX_HEADERDRAGDROP������֧�ֵ����ͷ����LVS_EX_TWOCLICKACTIVATE��ϣ���������δ��ѡ�е������ƶ���ʱ����һЩЧ�� 
//	m_ListCtrl.InsertColumn(0,_T("���"),LVCFMT_CENTER,rc.Size().cx/4,0);
	m_ListCtrl.InsertColumn(0,_T("����"),LVCFMT_CENTER,rc.Size().cx/3,0);
	m_ListCtrl.InsertColumn(1,_T("����"),LVCFMT_CENTER,rc.Size().cx/3,1);
	m_ListCtrl.InsertColumn(2,_T("��ϵ����"),LVCFMT_CENTER,rc.Size().cx/3,2);
	m_ListCtrl.SetExtendedStyle(m_ListCtrl.GetExtendedStyle()| LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT | LVS_EX_HEADERDRAGDROP /*| LVS_EX_TWOCLICKACTIVATE*/);

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


void CEmployee::OnBnClickedBtnQuit()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (m_DataBase.m_pConnection->State)  //��ֹ�ظ�����
	{
		m_DataBase.m_pConnection->Close();
		m_DataBase.m_pConnection=NULL;
	}
}

void CEmployee::OnBnClickedBtnShow()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	//	m_DataBase.Close();// �ᱨ����
	}
	else
	{
		MessageBox(_T("open database failure"),_T("Warning"));
	}
}
