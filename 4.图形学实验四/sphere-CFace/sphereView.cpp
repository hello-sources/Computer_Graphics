// sphereView.cpp : implementation of the CSphereView class
//

#include "stdafx.h"
#include "sphere.h"

#include "sphereDoc.h"
#include "sphereView.h"
#include "math.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSphereView

IMPLEMENT_DYNCREATE(CSphereView, CView)

BEGIN_MESSAGE_MAP(CSphereView, CView)
	//{{AFX_MSG_MAP(CSphereView)
	ON_COMMAND(ID_GRIDSPHERE, OnGridSphere)
	ON_COMMAND(ID_FILLSHERE, OnFillShere)
	ON_COMMAND(ID_DISPPOLY, OnDisppoly)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSphereView construction/destruction

CSphereView::CSphereView()
{
	// TODO: add construction code here
	TR=1000,d=1000,Phi=120,Theta=60;
	
Tk[1]=sin(PI*Theta/180);
Tk[2]=sin(PI*Phi/180);
Tk[3]=cos(PI*Theta/180);
Tk[4]=cos(PI*Phi/180);
Tk[5]=Tk[2]*Tk[3];
Tk[6]=Tk[2]*Tk[1];
Tk[7]=Tk[4]*Tk[3];
Tk[8]=Tk[4]*Tk[1];
ViewPointx=TR*Tk[6];
ViewPointy=TR*Tk[4];
ViewPointz=TR*Tk[5];

Ia=255;
Ip=255;
ka=0.2;
kd=0.5;
ks=0.7;
ns=50;
LPx=(1-LPy/d)*TR*cos(PI*45/180);
LPy=TR*cos(PI*45/180);
LPz=(1-LPy/d)*TR*sin(PI*45/180);
	
}

CSphereView::~CSphereView()
{
}

BOOL CSphereView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CSphereView drawing

void CSphereView::OnDraw(CDC* pDC)
{
	CSphereDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CSphereView printing

BOOL CSphereView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CSphereView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CSphereView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CSphereView diagnostics

#ifdef _DEBUG
void CSphereView::AssertValid() const
{
	CView::AssertValid();
}



void CSphereView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSphereDoc* CSphereView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSphereDoc)));
	return (CSphereDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSphereView message handlers


void CSphereView::HideSphere(CDC* pDC, float R,float h)
{
float x[4],y[4],z[4];
float x1[4],y1[4],z1[4];
double a1,a2;
float u1,u2;
int i,j,k;
float sx[4],sy[4];
double xn,yn,zn,vn,xv,yv,zv,costheta,mv;

//����۲�任����
for(Phi=0;Phi<=628;Phi+=10)
{
Tk[1]=sin(PI*Theta/180);
Tk[2]=sin(PI*Phi/180);
Tk[3]=cos(PI*Theta/180);
Tk[4]=cos(PI*Phi/180);
Tk[5]=Tk[2]*Tk[3];
Tk[6]=Tk[2]*Tk[1];
Tk[7]=Tk[4]*Tk[3];
Tk[8]=Tk[4]*Tk[1];

for (j=0;j<h;j=j+10)//������alpha��ɢ������Ϊѭ������
{//����������ɢ�����������Ϊ5��
u1=j;//��������alpha
u2=j+10;
  for (i=0;i<360;i=i+5) //������beta��ɢ������Ϊѭ������
  {
   a1=i*PI/180;//��������beta
   a2=(i+5)*PI/180;
   x[0]=(1-u1/h)*R*cos(a1);//���������巽�̼�������ı��ε��ĸ���������
   y[0]=u1;
   z[0]=(1-u1/h)*R*sin(a1);
   x[1]=(1-u1/h)*R*cos(a2);
   y[1]=u1;
   z[1]=(1-u1/h)*R*sin(a2);
   x[2]=(1-u2/h)*R*cos(a2);
   y[2]=u2;
   z[2]=(1-u2/h)*R*sin(a2);
   x[3]=(1-u2/h)*R*cos(a1);
   y[3]=u2;
   z[3]=(1-u2/h)*R*sin(a1);
 
  
   xn=(y[1]-y[0])*(z[2]-z[0])-(y[2]-y[0])*(z[1]-z[0]);//���������ı����ⷨ����
   yn=(x[2]-x[0])*(z[1]-z[0])-(x[1]-x[0])*(z[2]-z[0]);
   zn=(x[1]-x[0])*(y[2]-y[0])-(x[2]-x[0])*(y[1]-y[0]);
   vn=sqrt(xn*xn+yn*yn+zn*zn);//�ⷨ������ģ
   xn=xn/vn;//����ⷨ����
   yn=yn/vn; 
   zn=zn/vn;
   xv=ViewPointx-x[0];//������
   yv=ViewPointy-y[0];
   zv=ViewPointz-z[0];
   mv=sqrt(xv*xv+yv*yv+zv*zv);
   xv=xv/mv;//���������
   yv=yv/mv;
   zv=zv/mv;
   costheta=xn*xv+yn*yv+zn*zv;
   if (costheta>0)//���ݺ����б�ʵ������,cos��>=0�򻭳�С�ı���
   {
  for (k=0;k<4;k++)//���й۲�任
   {
	x1[k]=x[k]*Tk[3]-z[k]*Tk[1];//�۲�����ϵ��ά����
	y1[k]=-x[k]*Tk[8]+y[k]*Tk[2]-z[k]*Tk[7];
	z1[k]=-x[k]*Tk[6]-y[k]*Tk[4]-z[k]*Tk[5]+TR;
	//sx[k]=d*x1[k]/z1[k];//��Ļ��ά����ϵ
	//sy[k]=d*y1[k]/z1[k];

     sx[k]=x1[k];
     sy[k]=y1[k];
   }
    pDC->MoveTo(sx[0],sy[0]);
    pDC->LineTo(sx[1],sy[1]);
    pDC->LineTo(sx[2],sy[2]);
    pDC->LineTo(sx[3],sy[3]);
    pDC->LineTo(sx[0],sy[0]);
   }
  }//for (i=0;i<360;i=i+5) 
}//for (j=0;j<180;j=j+5)
Sleep(100);
RedrawWindow();
}
}//HideSphere

void CSphereView::OnGridSphere() 
{
	// TODO: Add your command handler code here
	CDC* pDC=GetDC();
	CRect rect;//����ͻ���
	GetClientRect(&rect);//��ÿͻ����Ĵ�С
	pDC->SetMapMode(MM_ANISOTROPIC);//pDC�Զ�������ϵ
	pDC->SetWindowExt(rect.Width(),rect.Height());//���ô��ڷ�Χ
	pDC->SetViewportExt(rect.Width(),-rect.Height());//x��ˮƽ���ң�y�ᴹֱ����
	pDC->SetViewportOrg(rect.Width()/2,rect.Height()/2);//��Ļ����Ϊԭ��
	
	
	HideSphere(pDC, 400,400);

	ReleaseDC(pDC);//�ͷ�DC
	
	
}

void CSphereView::OnFillShere() 
{
	// TODO: Add your command handler code here
	CDC* pDC=GetDC();
	CRect rect;//����ͻ���
	GetClientRect(&rect);//��ÿͻ����Ĵ�С
	pDC->SetMapMode(MM_ANISOTROPIC);//pDC�Զ�������ϵ
	pDC->SetWindowExt(rect.Width(),rect.Height());//���ô��ڷ�Χ
	pDC->SetViewportExt(rect.Width(),-rect.Height());//x��ˮƽ���ң�y�ᴹֱ����
	pDC->SetViewportOrg(rect.Width()/2,rect.Height()/2);//��Ļ����Ϊԭ��

	
	FillSphere(pDC, 400,400);

	ReleaseDC(pDC);//�ͷ�DC	
}



void CSphereView::FillSphere(CDC* pDC, float R,float h)
{
CPoint rgnpoints[4];
COLORREF fillColor;
CBrush brush;
CPen NewPen;
float sx[4],sy[4];

float x[4],y[4],z[4];
float x1[4],y1[4],z1[4];
double a1,a2;
float u1,u2;
int i,j,k;
double xn,yn,zn,vn,xv,yv,zv,costheta,mv;
double Ie,Id,Is,costhita1,cosphi,hx,hy,hz,lx,ly,lz;
int C=0;

Ie=Ia*ka;//���������

for (j=0;j<h;j=j+10)//������alpha��ɢ������Ϊѭ������
{//����������ɢ�����������Ϊ5��
u1=j;//��������alpha
u2=j+10;
  for (i=0;i<360;i=i+5) //������beta��ɢ������Ϊѭ������
  {
   a1=i*PI/180;//��������beta
   a2=(i+5)*PI/180;
   x[0]=(1-u1/h)*R*cos(a1);//���������巽�̼�������ı��ε��ĸ���������
   y[0]=u1;
   z[0]=(1-u1/h)*R*sin(a1);
   x[1]=(1-u1/h)*R*cos(a2);
   y[1]=u1;
   z[1]=(1-u1/h)*R*sin(a2);
   x[2]=(1-u2/h)*R*cos(a2);
   y[2]=u2;
   z[2]=(1-u2/h)*R*sin(a2);
   x[3]=(1-u2/h)*R*cos(a1);
   y[3]=u2;
   z[3]=(1-u2/h)*R*sin(a1);

  
   xn=(y[1]-y[0])*(z[2]-z[0])-(y[2]-y[0])*(z[1]-z[0]);//���������ı����ⷨ����
   yn=(x[2]-x[0])*(z[1]-z[0])-(x[1]-x[0])*(z[2]-z[0]);
   zn=(x[1]-x[0])*(y[2]-y[0])-(x[2]-x[0])*(y[1]-y[0]);
   vn=sqrt(xn*xn+yn*yn+zn*zn);//�ⷨ������ģ
   xn=xn/vn;//�ⷨ�������
   yn=yn/vn; 
   zn=zn/vn;
   xv=ViewPointx-x[0];//������
   yv=ViewPointy-y[0];
   zv=ViewPointz-z[0];
   mv=sqrt(xv*xv+yv*yv+zv*zv);
   xv=xv/mv;//���������
   yv=yv/mv;
   zv=zv/mv;
   costheta=xn*xv+yn*yv+zn*zv;//���������������ļн�����
   if (costheta>=0)//���ݺ����б�ʵ������,cos��>=0�򻭳�С�ı���
   {	
	   lx=LPx-x[0];ly=LPy-y[0];lz=LPz-z[0];//��Դ����
	   mv=sqrt(lx*lx+ly*ly+lz*lz);
	   lx=lx/mv;ly=ly/mv;lz=lz/mv;//��񻯹�Դ����
	   
	   costhita1=xn*lx+yn*ly+zn*lz;//���������Դ�����ļн�����
	   hx=lx+xv;hy=ly+yv;hz=lz+zv;//���������Դ�����ĺ�
	   mv=sqrt(hx*hx+hy*hy+hz*hz);
	   hx=hx/mv;hy=hy/mv;hz=hz/mv;	
	   cosphi=xn*hx+yn*hy+zn*hz;//���淴������������ļн�
	   if (costhita1>0)
			Id=Ip*kd*costhita1;
	   else
		   Id=0;
	   if (cosphi>0)
			Is=Ip*ks*pow(cosphi,ns);	
	   else
			Is=0;

	   C=(int)(Ie+Id+Is);
	   if (C>255) C=255;

		for (k=0;k<4;k++)//���й۲�任
		{
			x1[k]=x[k]*Tk[3]-z[k]*Tk[1];//�۲�����ϵ��ά����
			y1[k]=-x[k]*Tk[8]+y[k]*Tk[2]-z[k]*Tk[7];
			z1[k]=-x[k]*Tk[6]-y[k]*Tk[4]-z[k]*Tk[5]+TR;

			rgnpoints[k].x=x1[k];
			rgnpoints[k].y=y1[k];
		}
        fillColor=RGB(C,0,0);
        if (!brush.CreateSolidBrush(fillColor)) return;
        if (!NewPen.CreatePen(PS_SOLID,1,fillColor)) return;  
        pDC->SelectObject(&NewPen);
        pDC->SelectObject(&brush);
        pDC->Polygon(rgnpoints,4);
        brush.DeleteObject();
        NewPen.DeleteObject();
   }
  }//for (i=0;i<360;i=i+5) 
}//for (j=0;j<180;j=j+5)	

}//HideSphere

  

void CSphereView::OnDisppoly() 
{
	// TODO: Add your command handler code here
	
}
