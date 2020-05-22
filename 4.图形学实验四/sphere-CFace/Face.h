// Face.h: interface for the CFace class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_FACE_H__82BF93AE_A82E_407D_AF42_6E6608253C1C__INCLUDED_)
#define AFX_FACE_H__82BF93AE_A82E_407D_AF42_6E6608253C1C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "P3.h"

class CFace  
{
public:
	CFace();
	virtual ~CFace();
	void SetNum(int);
public:
	int vN;          //小面的顶点数
	int *vI;         //小面的顶点索引
};

#endif // !defined(AFX_FACE_H__82BF93AE_A82E_407D_AF42_6E6608253C1C__INCLUDED_)
