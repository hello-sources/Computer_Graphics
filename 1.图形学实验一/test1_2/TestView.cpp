// TestView.cpp : implementation of the CTestView class
//

#include "stdafx.h"
#include "Test.h"
#include "TestDoc.h"
#include "TestView.h"
#define ROUND(a) int(a+0.5)//��������
#define PI 3.1415926//Բ����
#include "cmath"//��ѧͷ�ļ�

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


/////////////////////////////////////////////////////////////////////////////
// CTestView

IMPLEMENT_DYNCREATE(CTestView, CView)

BEGIN_MESSAGE_MAP(CTestView, CView)
	//{{AFX_MSG_MAP(CTestView)
	ON_COMMAND(ID_MDRAW, OnMdraw)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTestView construction/destruction

CTestView::CTestView()
{
	// TODO: add construction code here
}

CTestView::~CTestView()
{
}

BOOL CTestView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CTestView drawing

void CTestView::OnDraw(CDC* pDC)
{
	CTestDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here	
	//�Զ�������ϵ
	CRect rect;
	GetClientRect(&rect);
	pDC->SetMapMode(MM_ANISOTROPIC);//����ӳ��ģʽ
	pDC->SetWindowExt(rect.Width(),rect.Height());//���ô���
	pDC->SetViewportExt(rect.Width(),rect.Height());//��������:x��ˮƽ���ң�y�ᴹֱ����
	pDC->SetViewportOrg(rect.Width()/2,rect.Height()/2);//�ͻ�������Ϊ����ϵԭ��
	//����������
	CPen NewPen,*pOldPen;
	NewPen.CreatePen(PS_SOLID,3,RGB(128,128,128));
	pOldPen=pDC->SelectObject(&NewPen);
	pDC->MoveTo(-rect.right/2,0);//����x��
	pDC->LineTo(rect.right/2,0);	
	pDC->MoveTo(rect.right/2-10,5);//�����Ҽ�ͷ��
	pDC->LineTo(rect.right/2,0);
	pDC->LineTo(rect.right/2-10,-5);
	pDC->LineTo(rect.right/2,0);
	pDC->TextOut(rect.right/2-20,30,"x");
	pDC->MoveTo(0,-rect.bottom/2);//����y��
	pDC->LineTo(0,rect.bottom/2);
	pDC->MoveTo(-5,rect.bottom/2-10);//�����ϼ�ͷ
	pDC->LineTo(0,rect.bottom/2);
	pDC->LineTo(5,rect.bottom/2-10);
	pDC->LineTo(0,rect.bottom/2);
	pDC->TextOut(-30,rect.bottom/2-20,"y");
	pDC->TextOut(-20,-10,"O");
	//��������ϵ	
	pDC->TextOut(300,200,"��(300,200)λ�ڵ�һ����");
	pDC->TextOut(-300,200,"��(-300,200)λ�ڵڶ�����");
	pDC->TextOut(-300,-200,"��(-300,-200)λ�ڵ�������");
	pDC->TextOut(300,-200,"��(300,-200)λ�ڵ�������");
	pDC->Rectangle(CRect(50,50,100,100));
	pDC->SelectObject(pOldPen);
	NewPen.DeleteObject();
}

/////////////////////////////////////////////////////////////////////////////
// CTestView printing

BOOL CTestView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CTestView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CTestView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CTestView diagnostics

#ifdef _DEBUG
void CTestView::AssertValid() const
{
	CView::AssertValid();
}

void CTestView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTestDoc* CTestView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTestDoc)));
	return (CTestDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTestView message handlers

void CTestView::OnMdraw() 
{
	// TODO: Add your command handler code here
	
}
