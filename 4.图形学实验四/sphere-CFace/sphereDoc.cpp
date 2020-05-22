// sphereDoc.cpp : implementation of the CSphereDoc class
//

#include "stdafx.h"
#include "sphere.h"

#include "sphereDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSphereDoc

IMPLEMENT_DYNCREATE(CSphereDoc, CDocument)

BEGIN_MESSAGE_MAP(CSphereDoc, CDocument)
	//{{AFX_MSG_MAP(CSphereDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSphereDoc construction/destruction

CSphereDoc::CSphereDoc()
{
	// TODO: add one-time construction code here

}

CSphereDoc::~CSphereDoc()
{
}

BOOL CSphereDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CSphereDoc serialization

void CSphereDoc::Serialize(CArchive& ar)
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
// CSphereDoc diagnostics

#ifdef _DEBUG
void CSphereDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CSphereDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSphereDoc commands
