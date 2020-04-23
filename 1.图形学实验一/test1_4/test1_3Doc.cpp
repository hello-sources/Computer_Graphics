// test1_3Doc.cpp : implementation of the CTest1_3Doc class
//

#include "stdafx.h"
#include "test1_3.h"

#include "test1_3Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTest1_3Doc

IMPLEMENT_DYNCREATE(CTest1_3Doc, CDocument)

BEGIN_MESSAGE_MAP(CTest1_3Doc, CDocument)
	//{{AFX_MSG_MAP(CTest1_3Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTest1_3Doc construction/destruction

CTest1_3Doc::CTest1_3Doc()
{
	// TODO: add one-time construction code here

}

CTest1_3Doc::~CTest1_3Doc()
{
}

BOOL CTest1_3Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CTest1_3Doc serialization

void CTest1_3Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CTest1_3Doc diagnostics

#ifdef _DEBUG
void CTest1_3Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CTest1_3Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTest1_3Doc commands
