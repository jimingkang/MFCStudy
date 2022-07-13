#include "MyWin32MFC.h"
#include "MyDlg.h"
#include "MyTreeNode.h"
#include <afxwin.h>
#include "numofisland.h"
class MyWin32MFCWindows : public CFrameWnd
{
public:
	TreeNode<int>* root;
	MyDlg* dlg;
	CButton* but;
	MyWin32MFCWindows();
	afx_msg void OnButton();
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()

};
BEGIN_MESSAGE_MAP(MyWin32MFCWindows, CFrameWnd)
	ON_BN_CLICKED(1002, OnButton)
	ON_WM_PAINT(OnPaint)
	END_MESSAGE_MAP()
class MyWin32MFC : public CWinApp,CStatic
{
public:

	virtual BOOL InitInstance();
	
};

BOOL MyWin32MFC::InitInstance() {
	MyWin32MFCWindows *mainWindow = new MyWin32MFCWindows();
	mainWindow->ShowWindow(m_nCmdShow);
	mainWindow->UpdateWindow();
	this->m_pMainWnd = mainWindow;  //把MyWin32MFCWindows指针送给APP保存
	return TRUE;

}

MyWin32MFCWindows::MyWin32MFCWindows() {
	Create(NULL, TEXT("test"));
	

	//::CreateWindow是操作系统的API，里面要求指定btn父类窗口句柄，这里为this->m_hWnd，也即是MyWin32MFCWindows类里面对应的句柄（MyWin32MFCWindows是MFC类，它里面保存（绑定）了一个wndow操作系统的窗口的句柄m_hWnd）
	//HWND btn = ::CreateWindow(TEXT("BUTTON"), TEXT("BUTTON"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 150, 45, 160, 55, this->m_hWnd, (HMENU)1001, AfxGetInstanceHandle(), NULL);


	//第二种是用MFC的CButton产生按钮，并保存于MyWin32MFCWindows指针变量but中
	but = new CButton();
	CRect r(50, 100, 100, 150);
	but->Create(TEXT("btn"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, r, this, 1002);
     root = new TreeNode<int>(1,700,100);

}

void MyWin32MFCWindows::OnButton() {

	//::MessageBoxW(NULL,TEXT("hello"), TEXT("hello"), MB_OK);
	//dlg=new MyDlg();
	//dlg->DoModal();
	//::DialogBoxParam(AfxGetInstanceHandle(), LPCTSTR(IDD_DIALOG1), NULL, NULL, NULL);

}

void MyWin32MFCWindows::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 在此处添加消息处理程序代码
					   // 不为绘图消息调用 CDialog::OnPaint()

//在鼠标处画图
	//CPoint curPos;
	//GetCursorPos(&curPos);

	//root->print(&dc);
	/*int M[][COL] = {{ 1, 1, 0, 0, 0 },
					{ 0, 1, 0, 0, 1 },
					{ 1, 0, 0, 1, 1 },
					{ 0, 0, 0, 0, 0 },
					{ 1, 0, 1, 0, 1 } };*/
	int M[][COL] = { { 0, 1, 0, 0 },
					 { 0, 1, 0, 0 },
					 { 0, 0, 0, 1 },
					 { 1, 0, 0, 0 } };
	CString a;


	CRect		rect(100,120,150,200);

	// current bounding rectangle of entire client area...

	for (size_t i = 0; i < ROW; i++)
	{
		for (size_t j = 0; j < COL; j++)
		{/*
			a.Format(_T("%d"), M[i][j]);
			rect.top = 200 + i * 20 - 20;
			rect.left = 100 + j * 20 - 20;

			rect.bottom = 200 + i * 20;
			rect.right = 100 + j * 20;
			dc.DrawText(a, -1, &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);*/

		}

	}
//	a.Format(_T("%d"), countIslands(M, &dc,&rect));
//	::AfxMessageBox(a);

     a.Format(_T("%d"), maxAreaOfIslands(M, &dc,&rect));
     ::AfxMessageBox(a);

	
	
}


MyWin32MFC myapp;

