
// MFC_0310_5View.h : CMFC_0310_5View ��Ľӿ�
//

#pragma once


class CMFC_0310_5View : public CView
{
protected: // �������л�����
	CMFC_0310_5View();
	DECLARE_DYNCREATE(CMFC_0310_5View)

// ����
public:
	CMFC_0310_5Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMFC_0310_5View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MFC_0310_5View.cpp �еĵ��԰汾
inline CMFC_0310_5Doc* CMFC_0310_5View::GetDocument() const
   { return reinterpret_cast<CMFC_0310_5Doc*>(m_pDocument); }
#endif
