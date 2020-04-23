// test1_3.h : main header file for the TEST1_3 application
//

#if !defined(AFX_TEST1_3_H__C198A7D9_7C93_4129_9C73_E21E00C6CDE9__INCLUDED_)
#define AFX_TEST1_3_H__C198A7D9_7C93_4129_9C73_E21E00C6CDE9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CTest1_3App:
// See test1_3.cpp for the implementation of this class
//

class CTest1_3App : public CWinApp
{
public:
	CTest1_3App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTest1_3App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CTest1_3App)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TEST1_3_H__C198A7D9_7C93_4129_9C73_E21E00C6CDE9__INCLUDED_)
