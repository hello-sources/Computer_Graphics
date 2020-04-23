// test1_3View.cpp : implementation of the CTest1_3View class
//

#include "stdafx.h"
#include "test1_3.h"

#include "test1_3Doc.h"
#include "test1_3View.h"
#include "math.h"
#define PI 3.1415926
#define Round(a) long(floor(a+0.5))

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTest1_3View

IMPLEMENT_DYNCREATE(CTest1_3View, CView)

BEGIN_MESSAGE_MAP(CTest1_3View, CView)
	//{{AFX_MSG_MAP(CTest1_3View)
	ON_COMMAND(IDD_DIAN, OnDian)
	ON_COMMAND(IDD_XIAN, OnXian)
	ON_COMMAND(IDD_YUAN, OnYuan)
	ON_COMMAND(IDD_MULITSIZE, OnMulitsize)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTest1_3View construction/destruction

CTest1_3View::CTest1_3View()
{
	// TODO: add construction code here

}

CTest1_3View::~CTest1_3View()
{
}

BOOL CTest1_3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CTest1_3View drawing

void CTest1_3View::OnDraw(CDC* pDC)
{
	CTest1_3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CTest1_3View printing

BOOL CTest1_3View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CTest1_3View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CTest1_3View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CTest1_3View diagnostics

#ifdef _DEBUG
void CTest1_3View::AssertValid() const
{
	CView::AssertValid();
}

void CTest1_3View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTest1_3Doc* CTest1_3View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTest1_3Doc)));
	return (CTest1_3Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTest1_3View message handlers

void CTest1_3View::OnDian() 
{
	// TODO: Add your command handler code here
	CDC *pDC = GetDC();
	CRect rect;
	GetClientRect(&rect);
	pDC->SetMapMode(MM_ANISOTROPIC);
	pDC->SetWindowExt(rect.Width(),rect.Height());
	pDC->SetViewportExt(rect.Width(),-rect.Height());
	pDC->SetViewportOrg(rect.Width()/2,rect.Height()/2);
	srand((unsigned)time(NULL));
	COLORREF crColor;
	int x,y;
	for(y=-50;y<50;y++)
		for(x=-150;x<-50;x++)
			pDC->SetPixelV(x,y,RGB(rand()%255,rand()%255,rand()%255));
	for(y=-50;y<50;y++)
		for(x=-150;x<-50;x++)
		{
			crColor=pDC->GetPixel(x,y);
			pDC->SetPixelV(x+200,y,crColor);
		}
	ReleaseDC(pDC);
}

void CTest1_3View::OnXian() 
{
	// TODO: Add your command handler code here
	CDC *pDC = GetDC();
	CRect rect;
	GetClientRect(&rect);
	pDC->SetMapMode(MM_ANISOTROPIC);
	pDC->SetWindowExt(rect.Width(),rect.Height());
	//pDC->SetWindowExt(rect.Width(),rect.Height()/2);
	pDC->SetViewportExt(rect.Width(),-rect.Height());
	pDC->SetViewportOrg(rect.Width()/2,rect.Height()/2);
	CPoint p0(-100,-100),p1(100,100);
	CPen NewPen,*pOldPen; 
	NewPen.CreatePen(PS_SOLID,1,RGB(0,0,255));//ѡ����ɫ���� 
	pOldPen=pDC->SelectObject(&NewPen);
	pDC->MoveTo(p0);
	pDC->LineTo(p1);
	p0.x=-rect.Width()/2;
	p0.y=0;
	p1.x=rect.Width()/2;
	p1.y=0;
	pDC->MoveTo(p0);
	pDC->LineTo(p1);
	p0.x=0;
	p0.y=-rect.Height()/2;
	p1.x=0;
	p1.y=rect.Height()/2;
	pDC->MoveTo(p0);
	pDC->LineTo(p1);
	//pDC->Rectangle(CRect(50,50,100,100));
	
	pDC->SelectObject(pOldPen);
	ReleaseDC(pDC);
}

void CTest1_3View::OnYuan() 
{
	CDC *pDC = GetDC();
	// TODO: Add your command handler code here
	CRect rect;
	GetClientRect(&rect);
	pDC->SetMapMode(MM_ANISOTROPIC);
	pDC->SetWindowExt(rect.Width(),rect.Height());
	pDC->SetViewportExt(rect.Width(),-rect.Height());
	pDC->SetViewportOrg(rect.Width()/2,rect.Height()/2);
	rect.OffsetRect(-rect.Width()/2,-rect.Height()/2);
	rect.DeflateRect(100,100);
	CBrush NewBrush,*pOldBrush;
	pOldBrush=(CBrush*)pDC->SelectStockObject(NULL_BRUSH);//ѡ��͸����ˢ
	int r=rect.Height()/2;//����Բ�İ뾶
	CRect rect1(CPoint(-r,-r),CPoint(r,r));//����Բ����Ӿ���
	pDC->Ellipse(rect1);//����Բ
	pDC->Ellipse(rect);//������Բ	
	pDC->Rectangle(rect);//������Ӿ���
	pDC->SelectObject(pOldBrush);
	ReleaseDC(pDC);
}

void CTest1_3View::OnMulitsize() 
{
	CDC *pDC = GetDC();
	// TODO: Add your command handler code here
	CRect rect;
	GetClientRect(&rect);
	pDC->SetMapMode(MM_ANISOTROPIC);
	pDC->SetWindowExt(rect.Width(),rect.Height());
	pDC->SetViewportExt(rect.Width(),-rect.Height());
	pDC->SetViewportOrg(rect.Width()/2,rect.Height()/2);
	CPen penBlue(PS_SOLID,5,RGB(0,0,255));//����5�����ؿ����ɫ����
	CPen *pOldPen=pDC->SelectObject(&penBlue);
	CBrush brushRed(RGB(255, 255, 255));//�����ɫ��ˢ
	CBrush *pOldBrush=pDC->SelectObject(&brushRed);
	pDC->SetPolyFillMode(WINDING);//�������ģʽ
	int r=200;//����������Բ�뾶
    CPoint p[5];//����������ζ�������
	double Alpha=2*PI/5;//����ÿ���ߵ�Բ�ĽǦ�
	for(int i=0;i<5;i++)
	{
		p[i].x=Round(r*cos(i*Alpha));//����������ζ�������
		p[i].y=Round(r*sin(i*Alpha));
	}
	CPoint v[5];//��������Ƕ�������
	v[0]=p[0];v[1]=p[2];v[2]=p[4];v[3]=p[1];v[4]=p[3];//ת������
	pDC->Polygon(v,5);//���������
	pDC->SelectObject(pOldPen);//�ָ�����
	pDC->SelectObject(pOldBrush);//�ָ���ˢ
	ReleaseDC(pDC);
}
