
// MFC_0310_5.h : MFC_0310_5 应用程序的主头文件
//
#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"       // 主符号


// CMFC_0310_5App:
// 有关此类的实现，请参阅 MFC_0310_5.cpp
//

class CMFC_0310_5App : public CWinApp
{
public:
	CMFC_0310_5App();


// 重写
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// 实现
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFC_0310_5App theApp;
