
// MFC_0310_5View.cpp : CMFC_0310_5View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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

// CMFC_0310_5View ����/����

CMFC_0310_5View::CMFC_0310_5View()
{
	// TODO: �ڴ˴���ӹ������

}

CMFC_0310_5View::~CMFC_0310_5View()
{
}

BOOL CMFC_0310_5View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC_0310_5View ����

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
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMFC_0310_5View ���

#ifdef _DEBUG
void CMFC_0310_5View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC_0310_5View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC_0310_5Doc* CMFC_0310_5View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC_0310_5Doc)));
	return (CMFC_0310_5Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC_0310_5View ��Ϣ�������


void CMFC_0310_5View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CMFC_0310_5Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	int sum = pDoc->a + pDoc->b;
	CString s,aa, bb,ss;
	s = _T("�����Ч");
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
