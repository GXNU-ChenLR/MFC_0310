
// MFC_0310_5View.cpp : CMFC_0310_5View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC_0310_5.h"
#endif

#include "MFC_0310_5Doc.h"
#include "MFC_0310_5View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC_0310_5View

IMPLEMENT_DYNCREATE(CMFC_0310_5View, CView)

BEGIN_MESSAGE_MAP(CMFC_0310_5View, CView)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMFC_0310_5View 构造/析构

CMFC_0310_5View::CMFC_0310_5View()
{
	// TODO: 在此处添加构造代码

}

CMFC_0310_5View::~CMFC_0310_5View()
{
}

BOOL CMFC_0310_5View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC_0310_5View 绘制

void CMFC_0310_5View::OnDraw(CDC* /*pDC*/)
{
	CMFC_0310_5Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CClientDC dc(this);
	dc.Rectangle(pDoc->A);
	dc.Rectangle(pDoc->B);
	dc.Rectangle(pDoc->C);
	// TODO: 在此处为本机数据添加绘制代码
}


// CMFC_0310_5View 诊断

#ifdef _DEBUG
void CMFC_0310_5View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC_0310_5View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC_0310_5Doc* CMFC_0310_5View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC_0310_5Doc)));
	return (CMFC_0310_5Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC_0310_5View 消息处理程序


void CMFC_0310_5View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFC_0310_5Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	int sum = pDoc->a + pDoc->b;
	CString s,aa, bb,ss;
	s = _T("点击无效");
	aa.Format(_T("%d"), pDoc->a);
	bb.Format(_T("%d"), pDoc->b);
	ss.Format(_T("%d"), sum);
	CClientDC dc(this);
	if (point.x > pDoc->A.left&&point.x > pDoc->A.top && point.y < pDoc->A.bottom&&point.y < pDoc->A.right)
		dc.TextOutW(110, 120, aa);
	else if (point.x > pDoc->B.left&&point.x > pDoc->B.top && point.y < pDoc->B.bottom&&point.y < pDoc->B.right)
		dc.TextOutW(310, 320, bb);
	else if (point.x > pDoc->C.left&&point.x > pDoc->C.top && point.y < pDoc->C.bottom&&point.y < pDoc->C.right)
		dc.TextOutW(610, 620, ss);
	else dc.TextOutW(180, 50, s);

	CView::OnLButtonDown(nFlags, point);
}
