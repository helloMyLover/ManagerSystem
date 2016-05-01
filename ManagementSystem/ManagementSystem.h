
// ManagementSystem.h : PROJECT_NAME 应用程序的主头文件
//

#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"		// 主符号


// CManagementSystemApp:
// 有关此类的实现，请参阅 ManagementSystem.cpp
//

class CManagementSystemApp : public CWinApp
{
public:
	CManagementSystemApp();

// 重写
public:
	virtual BOOL InitInstance();
	unsigned __stdcall showGuideUI(void * temp);

// 实现
private:
	HANDLE hnd_thread;
	unsigned int threadID;

	DECLARE_MESSAGE_MAP()
};

extern CManagementSystemApp theApp;