#pragma once


// CMEAT �Ի���

class CMEAT : public CDialogEx
{
	DECLARE_DYNAMIC(CMEAT)

public:
	CMEAT(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CMEAT();

// �Ի�������
	enum { IDD = IDD_DLG_MEAT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
