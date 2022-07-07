// MyDlg.cpp : implementation file
//

//#include "pch.h"
#include "afxdialogex.h"
#include "MyDlg.h"


// MyDlg dialog

IMPLEMENT_DYNAMIC(MyDlg, CDialog)

MyDlg::MyDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG1, pParent)
{

}

MyDlg::~MyDlg()
{
}

void MyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_edit);
}


BEGIN_MESSAGE_MAP(MyDlg, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &MyDlg::OnBnClickedButton1)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// MyDlg message handlers


void MyDlg::OnBnClickedButton1()
{
	m_edit.SetWindowTextW(TEXT("edit"));

}


void MyDlg::OnPaint()
{
//	CPaintDC dc(this); // device context for painting
//					   // TODO: 在此处添加消息处理程序代码
//					   // 不为绘图消息调用 CDialog::OnPaint()
//
////在鼠标处画图
//	CPoint curPos;
// 	//GetCursorPos(&curPos);
//
//	CPoint point1(0, 0);
//	point1.x = 300 - 50;
//	point1.y = 400 - 50;
//
//	CPoint point2(0, 0);
//	point2.x = 300 + 50;
//	point2.y = 400 + 50;
//
//	//画圆
//	dc.Ellipse(CRect(point1, point2));
	//CStatic::OnLButtonDblClk(nFlags, point);
}
