#pragma once

#include <vector>

using namespace std;
// CFood �Ի���

class CFood : public CDialogEx
{
	DECLARE_DYNAMIC(CFood)

public:
	CFood(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CFood();

// �Ի�������
	enum { IDD = IDD_DLG_FOOD };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();


	//����һ����ͼ����
	CBitmap mBitmapDrawFood;
	vector<CStatic *> m_pic;
	//����һ�����������ֵ��ı�����
	vector<CStatic *> m_text;
	//����һ����ʾ�۸���ı�����
	vector<CStatic *> m_textPrice;
	//����һ�����������İ�ť
	vector<CStatic *>m_btnCut;
	//����һ����ʾ�������ı�����
	int myCount;
	//vector<CStatic *> m_num;
	vector<CEdit *>  m_num;
	//����һ�����������İ�ť
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
	UINT m_ID;  //�ڰ�ť����ʱ��¼���µ�ID��
	void initResouce();
	afx_msg void addOrCutCount(UINT ID);
	HANDLE hThread;
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);

	static unsigned __stdcall CFood::sleepChangeButton(void *pArgument);
};
