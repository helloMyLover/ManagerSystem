#pragma once

#include <vector>

using namespace std;
// CFood 对话框

class CFood : public CDialogEx
{
	DECLARE_DYNAMIC(CFood)

public:
	CFood(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CFood();

// 对话框数据
	enum { IDD = IDD_DLG_FOOD };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();


	//定义一个绘图变量
	CBitmap mBitmapDrawFood;
	vector<CStatic *> m_pic;
	//定义一个描述性文字的文本变量
	vector<CStatic *> m_text;
	//定义一个显示价格的文本变量
	vector<CStatic *> m_textPrice;
	//定义一个减少数量的按钮
	vector<CStatic *>m_btnCut;
	//定义一个显示数量的文本变量
	int myCount;
	//vector<CStatic *> m_num;
	vector<CEdit *>  m_num;
	//定义一个增加数量的按钮
	vector<CStatic *> m_btnAdd;
	void createFoodList();
	CStatic * m_picTemp;
	CStatic * m_txtTemp;
	CStatic * m_txtPriceTemp;
	CStatic * m_cutBtnTemp;
	CEdit   * m_numTemp;
	CStatic * m_addBtnTemp;
	vector<CImage> image;
	void createFoodListInstantiation(CStatic * m_picTemp,CStatic * m_txtTemp,CStatic *m_textPriceTemp,CStatic * m_cutBtnTemp,CEdit *m_numTemp,CStatic * m_addBtnTemp);

	virtual BOOL DestroyWindow();

	CImage imgTemp[4];
	HBITMAP hBmp[4];
	UINT m_ID;  //在按钮按下时记录当下的ID号
	void initResouce();
	afx_msg void addOrCutCount(UINT ID);
	HANDLE hThread;
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);

	static unsigned __stdcall CFood::sleepChangeButton(void *pArgument);
};
