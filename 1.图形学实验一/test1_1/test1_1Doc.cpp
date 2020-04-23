// test1_1Doc.cpp : implementation of the CTest1_1Doc class
//

#include "stdafx.h"
#include "test1_1.h"

#include "test1_1Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTest1_1Doc

IMPLEMENT_DYNCREATE(CTest1_1Doc, CDocument)

BEGIN_MESSAGE_MAP(CTest1_1Doc, CDocument)
	//{{AFX_MSG_MAP(CTest1_1Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTest1_1Doc construction/destruction

CTest1_1Doc::CTest1_1Doc()
{
	// TODO: add one-time construction code here

}

CTest1_1Doc::~CTest1_1Doc()
{
}

BOOL CTest1_1Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CTest1_1Doc serialization

void CTest1_1Doc::Serialize(CArchive& ar)
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
// CTest1_1Doc diagnostics

#ifdef _DEBUG
void CTest1_1Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CTest1_1Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTest1_1Doc commands
