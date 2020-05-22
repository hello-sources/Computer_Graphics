// sphereDoc.h : interface of the CSphereDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SPHEREDOC_H__5C4B42A4_446C_471D_800A_2B5DE4717A9B__INCLUDED_)
#define AFX_SPHEREDOC_H__5C4B42A4_446C_471D_800A_2B5DE4717A9B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CSphereDoc : public CDocument
{
protected: // create from serialization only
	CSphereDoc();
	DECLARE_DYNCREATE(CSphereDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSphereDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CSphereDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CSphereDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SPHEREDOC_H__5C4B42A4_446C_471D_800A_2B5DE4717A9B__INCLUDED_)
