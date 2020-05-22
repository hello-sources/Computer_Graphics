### 计算机图形学实验四

> 实现一个三维形体的网格状消隐显示及动画显示  

### 1 在观察变换下，如何实现多面体网格显示（非消隐）？

在观察变换下，实现多面体网格显示包括以下步骤。

（1）定义视点参数（R，theta, phi)（式6-44，P174)

例如：TR=1000,d=1000,Phi=30,Theta=60;

（2）计算观察变换矩阵（式6-45至6-47）

```c++
InitParameter()

{

Tk[1]=sin(PI*Theta/180);

Tk[2]=sin(PI*Phi/180);

Tk[3]=cos(PI*Theta/180);

Tk[4]=cos(PI*Phi/180);

Tk[5]=Tk[2]*Tk[3];

Tk[6]=Tk[2]*Tk[1];

Tk[7]=Tk[4]*Tk[3];

Tk[8]=Tk[4]*Tk[1];

}
```



（3）定义多面体的顶点表和面表

在view类.h文件中加全局变量声明：

  **CP3 V[nV];//nV顶点数**

**CFace F[nF];//nF面数**

在view类.h文件最前面定义常量

  **\#define nV 8**

**\#define nF 6**

在view类加入ReadVertex()和ReadFace()函数，将其定义改为要显示的多面体；

（4）添加显示函数, 显示函数有算法如下

```c++
 TR=1000;Phi=30;Theta=60;

InitParameter();

   ReadVertex();

   ReadFace();

   For (iFace=0; iFace<nF; iFace++)

{//对面的循环

(消隐判断加于此）

for (iVrtx=0; iVrtx<F[iFace].vN; iVrtx++)

{//对面中顶点的循环，顶点号pIdx=F[iFace].vI[iVrtx];

//顶点坐标V[pIdx].x, V[pIdx].y, V[pIdx].z;

对每个顶点进行观察变换；

用变换结果的xy坐标画出每条边； }

画出最后一条边；

   }
```



### 2 在观察变换下，如何实现多面体网格划分显示（非消隐）？

对曲面体两个参数离散化，作为循环变量，每变量相邻两组参数构成四个点，形成一个小四边形，曲面体被划分成多个小四边形；画出每个小四边形，则实现了曲面体的显示。

(1)定义视点参数（R，theta, phi)（式6-44，P174)

```c++
TR=1000,d=1000,Phi=30,Theta=60;
```



(2)计算观察变换矩阵（式6-45至6-47）

//计算观察变换矩阵

```c++
 Tk[1]=sin(PI*Theta/180);
Tk[2]=sin(PI*Phi/180);
Tk[3]=cos(PI*Theta/180);
Tk[4]=cos(PI*Phi/180);
Tk[5]=Tk[2]*Tk[3];
Tk[6]=Tk[2]*Tk[1];
Tk[7]=Tk[4]*Tk[3];
Tk[8]=Tk[4]*Tk[1];
```



(3)曲面体显示

```c++
for (j=0;j<180;j=j+5)//将参数alpha离散化，作为循环变量

{//将曲面体离散化，参数间隔为5度

a1=j*PI/180;//相邻两个alpha

a2=(j+5)*PI/180;

 for (i=0;i<360;i=i+5) //将参数beta离散化，作为循环变量

 {

  b1=i*PI/180;//相邻两个beta

  b2=(i+5)*PI/180;

  x[0]=R*sin(a1)*sin(b1);//根据曲面体方程计算出多四边形的四个顶点坐标，R为球体半径

  y[0]=R*cos(a1);

  z[0]=R*sin(a1)*cos(b1);

  x[1]=R*sin(a2)*sin(b1);

  y[1]=R*cos(a2);

  z[1]=R*sin(a2)*cos(b1);

  x[2]=R*sin(a2)*sin(b2);

  y[2]=R*cos(a2);

  z[2]=R*sin(a2)*cos(b2);

  x[3]=R*sin(a1)*sin(b2);

  y[3]=R*cos(a1);

  z[3]=R*sin(a1)*cos(b2);

 

 for (k=0;k<4;k++)//进行观察变换

  {

​    x1[k]=x[k]*Tk[3]-z[k]*Tk[1];//观察坐标系三维坐标

   y1[k]=-x[k]*Tk[8]+y[k]*Tk[2]-z[k]*Tk[7];

​    z1[k]=-x[k]*Tk[6]-y[k]*Tk[4]-z[k]*Tk[5]+TR;

 

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
```

 

###   3 在观察变换下，在非消隐曲面体网格显示中，加入哪些代码会实现消隐显示？

```c++
xn=(y[1]-y[0])*(z[2]-z[0])-(y[2]-y[0])*(z[1]-z[0]);//计算网格四边形外法向量

  yn=(x[2]-x[0])*(z[1]-z[0])-(x[1]-x[0])*(z[2]-z[0]);

 

 zn=(x[1]-x[0])*(y[2]-y[0])-(x[2]-x[0])*(y[1]-y[0]);

  vn=sqrt(xn*xn+yn*yn+zn*zn);//外法向量的模

  xn=xn/vn;//规格化外法向量

  yn=yn/vn; 

  zn=zn/vn;

  xv=ViewPointx-x[0];//视向量

  yv=ViewPointy-y[0];

  zv=ViewPointz-z[0];

  mv=sqrt(xv*xv+yv*yv+zv*zv);

  xv=xv/mv;//规格化视向量

  yv=yv/mv;

  zv=zv/mv;

costheta=xn*xv+yn*yv+zn*zv;

if (costheta>=0)//¸

  {

显示多边形；

｝

### 4 在观察变换下，加入哪些代码能实现可实现多面体网格消隐显示？

每面取第0-2个点

x[0]=V[F[iFace].vI[0]].x; y[0]=V[F[iFace].vI[0]].y; z[0]=V[F[iFace].vI[0]].z; 

x[1]=V[F[iFace].vI[1]].x; y[1]=V[F[iFace].vI[1]].y; z[1]=V[F[iFace].vI[1]].z; 

x[2]=V[F[iFace].vI[2]].x; y[2]=V[F[iFace].vI[2]].y; z[2]=V[F[iFace].vI[2]].z; 
```



其余代码与第3题曲面体相同

### 5 如何将8-9题中的网格化及消隐显示算法推广到圆柱面、圆锥面、圆环面？

在球体显示程序中需要修改以下部分

```c++
for (j=0;j<180;j=j+5)//此处改为其他曲面体的第一个参数

{

a1=j*PI/180;//相邻两个参数

a2=(j+5)*PI/180;

 for (i=0;i<360;i=i+5) //此处改为其他曲面体的第二个参数

 {

  b1=i*PI/180;//相邻两个参数

  b2=(i+5)*PI/180;

  x[0]=R*sin(a1)*sin(b1);//根据曲面体方程计算出多四边形的四个顶点坐标，这里改为相应的曲面体方程，注意V0,V1,V2,V3为逆时针方向

  y[0]=R*cos(a1);

  z[0]=R*sin(a1)*cos(b1);

  x[1]=R*sin(a2)*sin(b1);

  y[1]=R*cos(a2);

  z[1]=R*sin(a2)*cos(b1);

  x[2]=R*sin(a2)*sin(b2);

  y[2]=R*cos(a2);

  z[2]=R*sin(a2)*cos(b2);

  x[3]=R*sin(a1)*sin(b2);

  y[3]=R*cos(a1);

  z[3]=R*sin(a1)*cos(b2);

//其余代码不变

}

}
```



对于圆柱体和圆锥体，需要用三角形划分底面（或顶面）。

 