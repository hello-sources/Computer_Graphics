// test1_1View.h : interface of the CTest1_1View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TEST1_1VIEW_H__C35441E7_BC72_4550_A9A6_BACE6F24C99D__INCLUDED_)
#define AFX_TEST1_1VIEW_H__C35441E7_BC72_4550_A9A6_BACE6F24C99D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CTest1_1View : public CView
{
protected: // create from serialization only
	CTest1_1View();
	DECLARE_DYNCREATE(CTest1_1View)

// Attributes
public:
	CTest1_1Doc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTest1_1View)
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
	virtual ~CTest1_1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTest1_1View)
	afx_msg void OnMdraw();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in test1_1View.cpp
inline CTest1_1Doc* CTest1_1View::GetDocument()
   { return (CTest1_1Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TEST1_1VIEW_H__C35441E7_BC72_4550_A9A6_BACE6F24C99D__INCLUDED_)
