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
END_MESSAGE_MAP()


// MyDlg message handlers


void MyDlg::OnBnClickedButton1()
{
	m_edit.SetWindowTextW(TEXT("edit"));

}
