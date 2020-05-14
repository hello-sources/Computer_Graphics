// testView.cpp : implementation of the CTestView class
//

#include "stdafx.h"
#include "test.h"

#include "testDoc.h"
#include "testView.h"
#include "Transform.h"
#include "P2.h"
#include "math.h"


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
	ON_COMMAND(IDD_MDRAW, OnMdraw)
	ON_COMMAND(IDD_MDRAW1, OnMdraw1)
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
	CRect rect;
	GetClientRect(&rect);
	pDC->SetMapMode(MM_ANISOTROPIC);//设置映射模式
	pDC->SetWindowExt(rect.Width(),rect.Height());//设置窗口
	pDC->SetViewportExt(rect.Width(),-rect.Height());//设置视区:x轴水平向右，y轴垂直向上
	pDC->SetViewportOrg(rect.Width()/2,rect.Height()/2);//客户区中心为坐标系原点
	//绘制坐标轴
	CPen NewPen,*pOldPen;
	NewPen.CreatePen(PS_SOLID,1,RGB(128,128,128));
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
	CDC* pDC=GetDC();
	CTransform trans;//声明一个Transform对象

	CRect rect;
	GetClientRect(&rect);
	pDC->SetMapMode(MM_ANISOTROPIC);//设置映射模式
	pDC->SetWindowExt(rect.Width(),rect.Height());//设置窗口
	pDC->SetViewportExt(rect.Width(),-rect.Height());//设置视区:x轴水平向右，y轴垂直向上
	pDC->SetViewportOrg(rect.Width(),rect.Height());//客户区中心为坐标系原点

	trans.num=28;//变换点个数
	CP2* PArray=new CP2[trans.num];  
	PArray[0].x=212;PArray[0].y=166;
	PArray[1].x=186;PArray[1].y=189;
	PArray[2].x=166;PArray[2].y=200;
	PArray[3].x=142;PArray[3].y=203;
	PArray[4].x=124;PArray[4].y=202;
	PArray[5].x=97;PArray[5].y=191;
	PArray[6].x=80;PArray[6].y=162;
	PArray[7].x=80;PArray[7].y=135;
	PArray[8].x=89;PArray[8].y=107;
	PArray[9].x=114;PArray[9].y=82;
	PArray[10].x=134;PArray[10].y=77;
	PArray[11].x=147;PArray[11].y=74;
	PArray[12].x=150;PArray[12].y=51;
	PArray[13].x=153;PArray[13].y=35;
	PArray[14].x=153;PArray[14].y=21;
	PArray[15].x=170;PArray[15].y=10;
	PArray[16].x=183;PArray[16].y=13;
	PArray[17].x=195;PArray[17].y=24;
	PArray[18].x=193;PArray[18].y=41;
	PArray[19].x=192;PArray[19].y=56;
	PArray[20].x=191;PArray[20].y=74;
	PArray[21].x=210;PArray[21].y=78;
	PArray[22].x=226;PArray[22].y=82;
	PArray[23].x=237;PArray[23].y=101;
	PArray[24].x=237;PArray[24].y=136;
	PArray[25].x=227;PArray[25].y=153;
	PArray[26].x=218;PArray[26].y=166;
	PArray[27].x=206;PArray[27].y=176;

	//画矩形
	trans.POld=PArray;
	DrawRectangle(pDC,&trans);

	CTransform tran1;
	tran1.num = 10;
	CP2* PArray1 = new CP2[tran1.num]; 
	PArray1[0].x=203;PArray1[0].y=177;
	PArray1[1].x=208;PArray1[1].y=202;
	PArray1[2].x=223;PArray1[2].y=221;
	PArray1[3].x=245;PArray1[3].y=223;
	PArray1[4].x=271;PArray1[4].y=220;
	PArray1[5].x=280;PArray1[5].y=197;
	PArray1[6].x=285;PArray1[6].y=177;
	PArray1[7].x=284;PArray1[7].y=158;
	PArray1[8].x=263;PArray1[8].y=147;
	PArray1[9].x=230;PArray1[9].y=154;
	tran1.POld=PArray1;
	DrawRectangle(pDC,&tran1);


	CTransform tran2;
	tran2.num = 10;
	CP2* PArray2 = new CP2[tran2.num]; 
	PArray2[0].x=101;PArray2[0].y=190;
	PArray2[1].x=90;PArray2[1].y=212;
	PArray2[2].x=58;PArray2[2].y=226;
	PArray2[3].x=40;PArray2[3].y=219;
	PArray2[4].x=27;PArray2[4].y=199;
	PArray2[5].x=33;PArray2[5].y=163;
	PArray2[6].x=54;PArray2[6].y=152;
	PArray2[7].x=77;PArray2[7].y=157;
	PArray2[8].x=80;PArray2[8].y=162;
	PArray2[9].x=80;PArray2[9].y=169;
	tran2.POld=PArray2;
	DrawRectangle(pDC,&tran2);

	CTransform tran3;
	tran3.num = 7;
	CP2* PArray3 = new CP2[tran3.num]; 
	PArray3[0].x=130;PArray3[0].y=156;
	PArray3[1].x=123;PArray3[1].y=151;
	PArray3[2].x=126;PArray3[2].y=141;
	PArray3[3].x=134;PArray3[3].y=142;
	PArray3[4].x=140;PArray3[4].y=145;
	PArray3[5].x=140;PArray3[5].y=153;
	PArray3[6].x=137;PArray3[6].y=157;
	tran3.POld=PArray3;
	DrawRectangle(pDC,&tran3);

	CTransform tran4;
	tran4.num = 7;
	CP2* PArray4 = new CP2[tran4.num]; 
	PArray4[0].x=182;PArray4[0].y=157;
	PArray4[1].x=171;PArray4[1].y=146;
	PArray4[2].x=175;PArray4[2].y=136;
	PArray4[3].x=182;PArray4[3].y=131;
	PArray4[4].x=195;PArray4[4].y=135;
	PArray4[5].x=198;PArray4[5].y=149;
	PArray4[6].x=186;PArray4[6].y=155;
	tran4.POld=PArray4;
	DrawRectangle(pDC,&tran4);


	for(int i = 1; i <= 2; i++){
		trans.Translate(10,0);
		tran1.Translate(10,0);
		tran2.Translate(10,0);
		tran3.Translate(10,0);
		tran4.Translate(10,0);
		Sleep(1000);
		RedrawWindow();
		DrawRectangle(pDC,&trans);
		DrawRectangle(pDC,&tran1);
		DrawRectangle(pDC,&tran2);
		DrawRectangle(pDC,&tran3);
		DrawRectangle(pDC,&tran4);
	}
	ReleaseDC(pDC);
	delete []PArray;

}

void CTestView::DrawRectangle(CDC* pDC,CTransform *transP)
{
	int number = transP->num;
	for(int k=0; k < number-3; k=k+3){
		double ax3 = -transP->POld[k].x + 3*transP->POld[k+1].x - 3*transP->POld[k+2].x + transP->POld[k+3].x;
		double ax2 = 3*transP->POld[k].x - 6*transP->POld[k+1].x + 3*transP->POld[k+2].x;
		double ax1 = -3*transP->POld[k].x + 3*transP->POld[k+1].x;
		double ax0 = transP->POld[k].x;
		double ay3 = -transP->POld[k].y + 3*transP->POld[k+1].y - 3*transP->POld[k+2].y + transP->POld[k+3].y;
		double ay2 = 3*transP->POld[k].y - 6*transP->POld[k+1].y + 3*transP->POld[k+2].y;
		double ay1 = -3*transP->POld[k].y + 3*transP->POld[k+1].y;
		double ay0 = transP->POld[k].y;
		for(double t=0; t<=1; t=t+0.01){
			int x = (int)ax3*t*t*t + ax2*t*t + ax1*t + ax0;
			int y = (int)ay3*t*t*t + ay2*t*t + ay1*t + ay0;
			if(t == 0)
				pDC->MoveTo(x,y);
			else
				pDC->LineTo(x,y);
		}
	}

}

void CTestView::OnMdraw1() 
{
	CDC* pDC=GetDC();
	CTransform trans;//声明一个Transform对象

	CRect rect;
	GetClientRect(&rect);
	pDC->SetMapMode(MM_ANISOTROPIC);//设置映射模式
	pDC->SetWindowExt(rect.Width(),rect.Height());//设置窗口
	pDC->SetViewportExt(rect.Width(),-rect.Height());//设置视区:x轴水平向右，y轴垂直向上
	pDC->SetViewportOrg(rect.Width()/2,rect.Height()/2);//客户区中心为坐标系原点

	CTransform tran;
	trans.num = 22;
	CP2* PArray=new CP2[trans.num];  
	PArray[0].x=220;PArray[0].y=236;
	PArray[1].x=252;PArray[1].y=234;
	PArray[2].x=292;PArray[2].y=258;
	PArray[3].x=319;PArray[3].y=244;
	PArray[4].x=321;PArray[4].y=219;
	PArray[5].x=308;PArray[5].y=187;
	PArray[6].x=288;PArray[6].y=162;
	PArray[7].x=264;PArray[7].y=141;
	PArray[8].x=245;PArray[8].y=125;
	PArray[9].x=231;PArray[9].y=133;
	PArray[10].x=212;PArray[10].y=142;
	PArray[11].x=204;PArray[11].y=150;
	PArray[12].x=190;PArray[12].y=161;
	PArray[13].x=179;PArray[13].y=179;
	PArray[14].x=172;PArray[14].y=203;
	PArray[15].x=165;PArray[15].y=229;
	PArray[16].x=171;PArray[16].y=243;
	PArray[17].x=182;PArray[17].y=262;
	PArray[18].x=203;PArray[18].y=258;
	PArray[19].x=214;PArray[19].y=250;
    PArray[20].x=270;PArray[20].y=240;
	PArray[21].x=280;PArray[21].y=235;
	trans.POld=PArray;
	DrawRectangle1(pDC,&trans);

	
	for(int i = 1; i <= 12; i++){
		trans.Rotate(i*2);
		if(i%2 == 0)
			trans.Scale(0.5,0.5);
		else 
			trans.Scale(1,1);
		Sleep(1000);
		RedrawWindow();
		DrawRectangle1(pDC,&trans);
	}
}
void CTestView::DrawRectangle1(CDC *pDC, CTransform *transP)
{
	int number = transP->num;
	for(int k=0; k < number-3; k=k+1){
		double mid = 1.0/6.0;
		double ax3 = (-transP->POld[k].x + 3*transP->POld[k+1].x - 3*transP->POld[k+2].x + transP->POld[k+3].x);
		double ax2 = (3*transP->POld[k].x - 6*transP->POld[k+1].x + 3*transP->POld[k+2].x);
		double ax1 = (-3*transP->POld[k].x + 3*transP->POld[k+2].x);
		double ax0 = (transP->POld[k].x + 4*transP->POld[k+1].x + transP->POld[k+2].x);
		double ay3 = (-transP->POld[k].y + 3*transP->POld[k+1].y - 3*transP->POld[k+2].y + transP->POld[k+3].y);
		double ay2 = (3*transP->POld[k].y - 6*transP->POld[k+1].y + 3*transP->POld[k+2].y);
		double ay1 = (-3*transP->POld[k].y + 3*transP->POld[k+2].y);
		double ay0 = (transP->POld[k].y + 4*transP->POld[k+1].y + transP->POld[k+2].y);
		for(double t=0; t<=1; t=t+0.01){
			double x = (ax3*t*t*t + ax2*t*t + ax1*t + ax0)*mid;
			double y = (ay3*t*t*t + ay2*t*t + ay1*t + ay0)*mid;
			if(t == 0)
				pDC->MoveTo(x,y);
			else
				pDC->LineTo(x,y);
		}
	}
}
