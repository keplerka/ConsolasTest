
// ChildView.cpp : implementation of the CChildView class
//

#include "stdafx.h"
#include "ConsolasTestI.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
END_MESSAGE_MAP()



// CChildView message handlers

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(NULL, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), NULL);

	return TRUE;
}

void CChildView::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here
	
	// Do not call CWnd::OnPaint() for painting messages
	CString text("Consolas Test");
	CRect rect(0, 0, 100, 20);
	COLORREF rgbPrev = dc.SetTextColor(RGB(0, 0, 0));

	LOGFONT lfc = { 0 };
	lfc.lfHeight = 0;// -16;
	lfc.lfCharSet = DEFAULT_CHARSET;
	wcscpy_s(lfc.lfFaceName, L"Consolas");

	CFont font;
	//font.CreatePointFont(120, L"Consolas", &dc);
	font.CreatePointFontIndirect(&lfc, &dc);

	HGDIOBJ prevFont = dc.SelectObject(font);
	LOGFONT lf = { 0 };
	font.GetLogFont(&lf);

	std::wstringstream str;
	int erg = dc.DrawTextEx(text, &rect, DT_CALCRECT | DT_INTERNAL | DT_LEFT /*| DT_NOCLIP*/, NULL);
	str << L"DrawTextEx/I liefert: " << erg << L"\n";
	erg = dc.DrawTextEx(text, &rect, /*DT_CALCRECT |*/ DT_INTERNAL | DT_LEFT /*| DT_NOCLIP*/, NULL);
	str << L"DrawTextEx/II liefert: " << erg << L"\n";
	//str << lf << L"\n";
	OutputDebugString(str.str().c_str());

	dc.Draw3dRect(&rect, RGB(0, 255, 0), RGB(0, 0, 255));

	dc.SetTextColor(rgbPrev);
	dc.SelectObject(prevFont);
}

