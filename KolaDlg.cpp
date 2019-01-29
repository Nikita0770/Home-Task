// KolaDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Program.h"
#include "ProgramDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// KolaDlgDlg dialog



CKolaDlg::CKolaDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_PROGRAM_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CKolaDlg::DoDataExchange(CDataExchange* pDX)
{
	fg = true;

	SetWindowTextW(L"Program");

	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CKolaDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()


// CProgramDlg message handlers

BOOL CKolaDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

									// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CKolaDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{


		CClientDC dc(this);
		GetClientRect(&rc);

		dc.FillSolidRect(&rc, RGB(255, 255, 255));

		cf = RGB(0, 0, 0);
		hPenOxy = CreatePen(PS_SOLID, 3, cf);
		hOldPen = (HPEN)SelectObject(dc, hPenOxy);

		int d = 140;
		dx = 120; dy = 120;

		x1 = 140;
		y1 = 90;

		for (k = 0; k < 4; k++)
		{
			for (i = 0; i < 5; i++)
			{
				//dc.Ellipse(x1 + i * dx, y1 + k * dx, x1 + i * dx + d, y1 + k * dx + d);
				Circl(x1 + i * dx, y1 + k * dx, d);
			}
		}

		SelectObject(dc, hOldPen);
		DeleteObject(hPenOxy);

		CDialog::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CKolaDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

afx_msg void CKolaDlg::Circl(int X, int Y, int D)
{
	CClientDC dc(this);
	cf = RGB(0, 0, 0);
	hPenOxy = CreatePen(PS_SOLID, 3, cf);
	hOldPen = (HPEN)SelectObject(dc, hPenOxy);

	double xf, yf, f;
	f = 0;

	dc.MoveTo(X + D / 2, Y);

	do
	{
		xf = D / 2 * cos(f);
		yf = D / 2 * sin(f);
		//dc.SetPixel(xf+X, yf+Y, cf);
		dc.LineTo(xf + X, yf + Y);
		f += 0.09;
	} while (f <= 360);
}