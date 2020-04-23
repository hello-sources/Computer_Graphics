// test1_3View.h : interface of the CTest1_3View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TEST1_3VIEW_H__7E6DD567_8D30_4194_A311_9227D69FE38E__INCLUDED_)
#define AFX_TEST1_3VIEW_H__7E6DD567_8D30_4194_A311_9227D69FE38E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CTest1_3View : public CView
{
protected: // create from serialization only
	CTest1_3View();
	DECLARE_DYNCREATE(CTest1_3View)

// Attributes
public:
	CTest1_3Doc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTest1_3View)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CTest1_3View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTest1_3View)
	afx_msg void OnDian();
	afx_msg void OnXian();
	afx_msg void OnYuan();
	afx_msg void OnMulitsize();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in test1_3View.cpp
inline CTest1_3Doc* CTest1_3View::GetDocument()
   { return (CTest1_3Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TEST1_3VIEW_H__7E6DD567_8D30_4194_A311_9227D69FE38E__INCLUDED_)
