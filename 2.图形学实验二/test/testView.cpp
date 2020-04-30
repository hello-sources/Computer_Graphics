// testView.cpp : implementation of the CTestView class
//

#include "stdafx.h"
#include "test.h"

#include "testDoc.h"
#include "testView.h"


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
	pDC->SetMapMode(MM_ANISOTROPIC);//����ӳ��ģʽ
	pDC->SetWindowExt(rect.Width(),rect.Height());//���ô���
	pDC->SetViewportExt(rect.Width(),-rect.Height());//��������:x��ˮƽ���ң�y�ᴹֱ����
	pDC->SetViewportOrg(rect.Width()/2,rect.Height()/2);//�ͻ�������Ϊ����ϵԭ��
	//����������
	CPen NewPen,*pOldPen;
	NewPen.CreatePen(PS_SOLID,1,RGB(128,128,128));
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
	CTransform trans;//����һ��Transform����

	CRect rect;
	GetClientRect(&rect);
	pDC->SetMapMode(MM_ANISOTROPIC);//����ӳ��ģʽ
	pDC->SetWindowExt(rect.Width(),rect.Height());//���ô���
	pDC->SetViewportExt(rect.Width(),-rect.Height());//��������:x��ˮƽ���ң�y�ᴹֱ����
	pDC->SetViewportOrg(rect.Width()/2,rect.Height()/2);//�ͻ�������Ϊ����ϵԭ��

	trans.num=4;//�任�����
	CP2* PArray=new CP2[trans.num];  
	PArray[0].x=50;PArray[0].y=50;
	PArray[1].x=100;PArray[1].y=50;
	PArray[2].x=100;PArray[2].y=100;
	PArray[3].x=50;PArray[3].y=100;
	//������
	trans.POld=PArray;
	DrawRectangle(pDC,&trans);

	//trans.Translate(-75,-75);
	for(int i=0;i<12;i++){
	trans.Rotate(30);//�任
	trans.Scale(1.1,1.1);
	//trans.Translate(75,75);
	Sleep(1000);
	//RedrawWindow();//����

	DrawRectangle(pDC,&trans);
	}
	ReleaseDC(pDC);
	delete []PArray;

}

void CTestView::DrawRectangle(CDC* pDC,CTransform *transP)
{
	pDC->MoveTo(transP->POld[0].x, transP->POld[0].y);
	for ( int i=1; i<transP->num; i++)
	{
		pDC->LineTo(transP->POld[i].x, transP->POld[i].y);
	}
	pDC->LineTo(transP->POld[0].x, transP->POld[0].y);
}

void CTestView::OnMdraw1() 
{
	// TODO: Add your command handler code here
		CDC* pDC=GetDC();
	CTransform trans;//����һ��Transform����

	CRect rect;
	GetClientRect(&rect);
	pDC->SetMapMode(MM_ANISOTROPIC);//����ӳ��ģʽ
	pDC->SetWindowExt(rect.Width(),rect.Height());//���ô���
	pDC->SetViewportExt(rect.Width(),-rect.Height());//��������:x��ˮƽ���ң�y�ᴹֱ����
	pDC->SetViewportOrg(rect.Width()/2,rect.Height()/2);//�ͻ�������Ϊ����ϵԭ��

	trans.num=4;//�任�����
	CP2* PArray=new CP2[trans.num];  
	PArray[0].x=50;PArray[0].y=50;
	PArray[1].x=100;PArray[1].y=50;
	PArray[2].x=100;PArray[2].y=100;
	PArray[3].x=50;PArray[3].y=100;
	
	CP2* PArray1=new CP2[1];
	PArray1[0].x=75;PArray1[0].y=75;

	//������
	trans.POld=PArray;
	DrawRectangle(pDC,&trans);

	//trans.Translate(-75,-75);
	for(int i=0;i<40;i++){
	trans.Rotate(3,PArray1[0]);//�任
	trans.Translate(-10,0);
	Sleep(100);
	PArray1[0].x=PArray1[0].x-10;
	//RedrawWindow();//����
	DrawRectangle(pDC,&trans);
	
	}
	ReleaseDC(pDC);
	delete []PArray;
	delete []PArray1;

}
