
// ManagementSystem.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CManagementSystemApp:
// �йش����ʵ�֣������ ManagementSystem.cpp
//

class CManagementSystemApp : public CWinApp
{
public:
	CManagementSystemApp();

// ��д
public:
	virtual BOOL InitInstance();
	unsigned __stdcall showGuideUI(void * temp);

// ʵ��
private:
	HANDLE hnd_thread;
	unsigned int threadID;

	DECLARE_MESSAGE_MAP()
};

extern CManagementSystemApp theApp;