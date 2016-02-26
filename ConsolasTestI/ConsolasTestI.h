
// ConsolasTestI.h : main header file for the ConsolasTestI application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CConsolasTestIApp:
// See ConsolasTestI.cpp for the implementation of this class
//

class CConsolasTestIApp : public CWinAppEx
{
public:
	CConsolasTestIApp();


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation

public:
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CConsolasTestIApp theApp;
