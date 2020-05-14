// testView.cpp : implementation of the CTestView class
//

#include "stdafx.h"
#include "test.h"
#include <math.h>
#include "testDoc.h"
#include "testView.h"
#include <Windows.h>
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
	ON_COMMAND(IDD_MDRAW_B, OnMdrawB)
	ON_COMMAND(IDD_MDRAW_B3D, OnMdrawB3d)
	ON_COMMAND(IDD_MDRAW_BEIZER, OnMdrawBeizer)
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

void CTestView::OnMdrawB() 
{
	// TODO: Add your command handler code here
	//int px[13]={261,319,391,409,408,369,260,142,107,116,126,198,263};
	//int py[13]={258,300,298,230,162,115,57,114,161,207,287,287,257};
	int px[13] = {77, 95, 113, 122, 140, 156, 176, 193, 207, 223, 240, 257, 269};
	int py[13] = {81, 126, 189, 233, 281, 323, 354, 317, 279, 231, 186, 135, 95};
	float ax3,ax2,ax1,ax0,ay3,ay2,ay1,ay0,x,y, X[100], Y[100];

	CDC* pDC=GetDC();
	for(int k=0; k<13-3; k=k+3)//10是控制点个数
	{//X(t)的系数，px[k]:p0(x),…px[k+3]:p3(x);
		ax3=-px[k]+3*px[k+1]-3*px[k+2]+px[k+3];
		ax2=3*px[k]-6*px[k+1]+3*px[k+2];
		ax1=-3*px[k]+3*px[k+1];
		ax0=px[k];
		ay3=-py[k]+3*py[k+1]-3*py[k+2]+py[k+3];
		ay2=3*py[k]-6*py[k+1]+3*py[k+2];
		ay1=-3*py[k]+3*py[k+1];
		ay0=py[k];
		float offset = 0;
		for (int i = 0; i <= 100; i++) {
		
			for(double z = 0; z <= i * 0.01; z+=0.01) {
				x = ax3*z*z*z+ax2*z*z+ax1*z+ax0;
				offset = x;
			}
			for(double t = 0; t <= 1; t+=0.01) {
				X[i] = ax3*t*t*t+ax2*t*t+ax1*t+ax0;
				Y[i] = ay3*t*t*t+ay2*t*t+ay1*t+ay0;
				if (t==0)
					pDC->MoveTo(X[i] + offset,Y[i]);
				else
					pDC->LineTo(X[i] + offset,Y[i]);
				//Sleep(1);
			}
			//if (i < 100) RedrawWindow();
		}
		
	}
	ReleaseDC(pDC);
}

void CTestView::OnMdrawB3d() 
{
		CDC* pDC=GetDC();
	// TODO: Add your command handler code here
	float px5[21]={116,98,83,73,73,80,89,109,124,146,172,186,197,196,184,166,147,133,118,98,83};
float py5[21]={91,99,94,71,55,35,19,10,7,7,12,27,50,70,81,90,94,94,89,98,94};//顶点xy坐标

for(int m=0;m<6;m++)
{
	
	for(int i=0;i<21;i++)
	{
		float a=px5[i];
		float b=py5[i];
		px5[i]=a*cos(3.14*m/6)-b*sin(3.14*m/6)-50;
        py5[i]=a*sin(3.14*m/6)+b*cos(3.14*m/6)-50;
	}
		
 //double x1=x*cos(3.14*m/4)-y*sin(m*3.14/4);
//double y1=x*sin(m*3.14/4)+y*cos(m*3.14/4);

for(int k=0; k<21-3; k=k+1)//18是控制点个数
{//X(t)的系数，px[k]:p0(x),…px[k+3]:p3(x);
float ax3=(-px5[k]+3*px5[k+1]-3*px5[k+2]+px5[k+3])/6;
float ax2=(3*px5[k]-6*px5[k+1]+3*px5[k+3])/6;
float ax1=(-3*px5[k]+3*px5[k+2])/6;
float ax0=(px5[k]+4*px5[k+1]+px5[k+2])/6;
float ay3=(-py5[k]+3*py5[k+1]-3*py5[k+2]+py5[k+3])/6;
float ay2=(3*py5[k]-6*py5[k+1]+3*py5[k+3])/6;
float ay1=(-3*py5[k]+3*py5[k+2])/6;
float ay0=(py5[k]+4*py5[k+1]+py5[k+2])/6;
for(double t=0;t<=1;t=t+0.01)
{double x=ax3*t*t*t+ax2*t*t+ax1*t+ax0;
 double y=ay3*t*t*t+ay2*t*t+ay1*t+ay0;

 if (t==0)
      pDC->MoveTo(CPoint(x,y));
else
     pDC->LineTo(CPoint(x,y));
}

}


}
	ReleaseDC(pDC);
}

void CTestView::OnMdrawBeizer() 
{
	// TODO: Add your command handler code here
	// TODO: Add your command handler code here
	int px[14]={242,259,334,378,367,345,259,260,185,168,181,215,282,276};
	int	py[14]={239,247,272,217,177,139,100,97,143,189,264,275,240,267};
	struct P{
	 int px,py;
	 };
	int ax3,ax2,ax1,ax0,ay3,ay2,ay1,ay0,x,y;

	CDC* pDC=GetDC();


	for(int j=0;j<4;j++)
	{
	for(int i=0;i<14;i++)
	{
	px[i]+=10;
	py[i]+=10;
	}

	for(int k=0; k<14-3; k=k++)//10是控制点个数
	{//X(t)的系数，px[k]:p0(x),…px[k+3]:p3(x);
		ax0=(px[k]+4*px[k+1]+px[k+2])/6;
		ax1=(px[k+2]-px[k])/2;
		ax2=(px[k]-2*px[k+1]+px[k+2])/2;
		ax3=-(px[k]-3*px[k+1]+3*px[k+2]-px[k+3])/6;
		ay0=(py[k]+4*py[k+1]+py[k+2])/6;
		ay1=(py[k+2]-py[k])/2;
		ay2=(py[k]-2*py[k+1]+py[k+2])/2;
		ay3=-(py[k]-3*py[k+1]+3*py[k+2]-py[k+3])/6;
		for(double t=0;t<=1;t=t+0.01)
		{
			int i=0;
			x=ax3*t*t*t+ax2*t*t+ax1*t+ax0;
			y=ay3*t*t*t+ay2*t*t+ay1*t+ay0;
			 if (t==0)
				 pDC->MoveTo(x,y);
			else
				 pDC->LineTo(x,y);
			i++;
		//Sleep(10);
		}
	}

	Sleep(1000);
	RedrawWindow();
	}
	ReleaseDC(pDC);
	
}
