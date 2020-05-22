// sphereView.h : interface of the CSphereView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SPHEREVIEW_H__B544269D_2415_4545_90E6_2641FF2C2C93__INCLUDED_)
#define AFX_SPHEREVIEW_H__B544269D_2415_4545_90E6_2641FF2C2C93__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define PI 3.1415926

class CSphereView : public CView
{
protected: // create from serialization only
	CSphereView();
	DECLARE_DYNCREATE(CSphereView)

// Attributes
public:
	CSphereDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSphereView)
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
	double ViewPointz;
	double ViewPointy;
	double ViewPointx;
	double Tk[9];
	double TR,Theta,Phi,d;//视点在用户坐标系中的球坐标
	double Ia,Ip,ka,kd,ks,ns,LPx,LPy,LPz;

	virtual ~CSphereView();
	void HideSphere(CDC* pDC, float R,float h);
	void CSphereView::FillSphere(CDC* pDC, float R,float h);
	//void FillSphere(CDC* pDC, float R);

#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CSphereView)
	afx_msg void OnGridSphere();
	afx_msg void OnFillShere();
	afx_msg void OnDisppoly();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in sphereView.cpp
inline CSphereDoc* CSphereView::GetDocument()
   { return (CSphereDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SPHEREVIEW_H__B544269D_2415_4545_90E6_2641FF2C2C93__INCLUDED_)
