#include "MyWin32MFC.h"
#include "MyDlg.h"
#include "MyTreeNode.h"
#include <afxwin.h>
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

	TreeNode<int>* lleft = new TreeNode<int>(4);
	TreeNode<int>* lright = new TreeNode<int>(5);
	TreeNode<int> * left=new TreeNode<int>(2);
	TreeNode<int>* right = new TreeNode<int>(3);
     root = new TreeNode<int>(1,left,right,700,100);
	 left->setLeft(lleft);
	 left->setRight(lright);
	

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
	root->PreOrder(root, &dc);
	//root->print(&dc);
}


MyWin32MFC myapp;

