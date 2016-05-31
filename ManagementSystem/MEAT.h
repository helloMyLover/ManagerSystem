#pragma once


// CMEAT 对话框

class CMEAT : public CDialogEx
{
	DECLARE_DYNAMIC(CMEAT)

public:
	CMEAT(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CMEAT();

// 对话框数据
	enum { IDD = IDD_DLG_MEAT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
