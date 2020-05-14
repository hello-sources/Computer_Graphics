# 图形学实验三内容
1. Bezier曲线与B样条曲线图形显示
> 图形：苹果，树叶，花朵，汽车等（图形实例见后面）,通过B-B.rar中的软件确定曲线的顶点,算法：基于一般的根据方程画曲线的算法
2. 样条曲线图形动画
>对控制点进行二维变换，变换后重画曲线，在循环中显示图形、延时和清屏；
**Bezier曲线算法如下所示，B样条曲线自己实现**
``` c++
float px[...]={};
float py[...]={};//顶点xy坐标

for(k=0; k<10-3; k=k+3)//10是控制点个数{
	//X(t)的系数，px[k]:p0(x),…px[k+3]:p3(x);
	ax3=-px[k]+3*px[k+1]-3*px[k+2]+px[k+3];
	ax2=3*px[k]-6*px[k+1]+3*px[k+2];
	ax1=-3*px[k]+3*px[k+1];
	ax0=px[k];
	ay3=-py[k]+3*py[k+1]-3*py[k+2]+py[k+3];
	ay2=3*py[k]-6*py[k+1]+3*py[k+2];
	ay1=-3*py[k]+3*py[k+1];
	ay0=py[k];
	for(t=0;t<=1;t=t+0.01)	{
	x=ax3*t*t*t+ax2*t*t+ax1*t+ax0;
 	y= ay3*t*t*t+ay2*t*t+ay1*t+ay0;
 	if (t==0)
     	 pDC->moveto(x,y);
	else
    	 pDC->lineto(x,y);
	}
}

