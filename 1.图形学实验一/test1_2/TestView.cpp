// TestView.cpp : implementation of the CTestView class
//

#include "stdafx.h"
#include "Test.h"
#include "TestDoc.h"
#include "TestView.h"
#define ROUND(a) int(a+0.5)//四舍五入
#define PI 3.1415926//圆周率
#include "cmath"//数学头文件

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
	//自定义坐标系
	CRect rect;
	GetClientRect(&rect);
	pDC->SetMapMode(MM_ANISOTROPIC);//设置映射模式
	pDC->SetWindowExt(rect.Width(),rect.Height());//设置窗口
	pDC->SetViewportExt(rect.Width(),rect.Height());//设置视区:x轴水平向右，y轴垂直向上
	pDC->SetViewportOrg(rect.Width()/2,rect.Height()/2);//客户区中心为坐标系原点
	//绘制坐标轴
	CPen NewPen,*pOldPen;
	NewPen.CreatePen(PS_SOLID,3,RGB(128,128,128));
	pOldPen=pDC->SelectObject(&NewPen);
	pDC->MoveTo(-rect.right/2,0);//绘制x轴
	pDC->LineTo(rect.right/2,0);	
	pDC->MoveTo(rect.right/2-10,5);//绘制右箭头　
	pDC->LineTo(rect.right/2,0);
	pDC->LineTo(rect.right/2-10,-5);
	pDC->LineTo(rect.right/2,0);
	pDC->TextOut(rect.right/2-20,30,"x");
	pDC->MoveTo(0,-rect.bottom/2);//绘制y轴
	pDC->LineTo(0,rect.bottom/2);
	pDC->MoveTo(-5,rect.bottom/2-10);//绘制上箭头
	pDC->LineTo(0,rect.bottom/2);
	pDC->LineTo(5,rect.bottom/2-10);
	pDC->LineTo(0,rect.bottom/2);
	pDC->TextOut(-30,rect.bottom/2-20,"y");
	pDC->TextOut(-20,-10,"O");
	//测试坐标系	
	pDC->TextOut(300,200,"点(300,200)位于第一象限");
	pDC->TextOut(-300,200,"点(-300,200)位于第二象限");
	pDC->TextOut(-300,-200,"点(-300,-200)位于第三象限");
	pDC->TextOut(300,-200,"点(300,-200)位于第四象限");
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
