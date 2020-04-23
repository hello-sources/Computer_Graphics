// test1_1View.cpp : implementation of the CTest1_1View class
//

#include "stdafx.h"
#include "test1_1.h"

#include "test1_1Doc.h"
#include "test1_1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTest1_1View

IMPLEMENT_DYNCREATE(CTest1_1View, CView)

BEGIN_MESSAGE_MAP(CTest1_1View, CView)
	//{{AFX_MSG_MAP(CTest1_1View)
	ON_COMMAND(IID_MDRAW, OnMdraw)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTest1_1View construction/destruction

CTest1_1View::CTest1_1View()
{
	// TODO: add construction code here

}

CTest1_1View::~CTest1_1View()
{
}

BOOL CTest1_1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CTest1_1View drawing

void CTest1_1View::OnDraw(CDC* pDC)
{
	CTest1_1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CTest1_1View printing

BOOL CTest1_1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CTest1_1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CTest1_1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CTest1_1View diagnostics

#ifdef _DEBUG
void CTest1_1View::AssertValid() const
{
	CView::AssertValid();
}

void CTest1_1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTest1_1Doc* CTest1_1View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTest1_1Doc)));
	return (CTest1_1Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTest1_1View message handlers

void CTest1_1View::OnMdraw() 
{
	// TODO: Add your command handler code here
	CDC *pDC = GetDC();
	// TODO: add draw code for native data here
	CRect rect;
	GetClientRect(&rect);
	pDC->SetMapMode(MM_ANISOTROPIC);//自定义坐标系
	pDC->SetWindowExt(rect.Width(),rect.Height());
	pDC->SetViewportExt(rect.Width(),-rect.Height());//x轴水平向右为正，y轴垂直向上为正
	pDC->SetViewportOrg(rect.Width()/2,rect.Height()/2);//客户区中心为坐标系原点
	CPoint dl,tr;
	//绘制外部黑色椭圆
	dl=CPoint(-200,-150),tr=CPoint(200,150);
	CBrush NewBrush,*pOldBrush;
	NewBrush.CreateSolidBrush(RGB(0,0,0));
	pOldBrush=pDC->SelectObject(&NewBrush);
	pDC->Ellipse(CRect(dl,tr));
	pDC->SelectObject(pOldBrush);
	NewBrush.DeleteObject();
	//绘制外部白色圆
	dl=CPoint(-147,-147),tr=CPoint(147,147);
	pDC->Ellipse(CRect(dl,tr));
	//绘制内部黑色椭圆
	dl=CPoint(-140,-90),tr=CPoint(140,90);
	NewBrush.CreateSolidBrush(RGB(0,0,0));
	pOldBrush=pDC->SelectObject(&NewBrush);
	pDC->Ellipse(CRect(dl,tr));
	pDC->SelectObject(pOldBrush);
	NewBrush.DeleteObject();
	//绘制内部白色圆
	dl=CPoint(-88,-88),tr=CPoint(88,88);
	pDC->Ellipse(CRect(dl,tr));
	ReleaseDC(pDC);
}
