#include "MyWin32MFC.h"
#include "MyDlg.h"
#include <afxwin.h>
class MyWin32MFCWindows : public CFrameWnd
{
public:
	CButton* but;
	MyWin32MFCWindows();
	afx_msg void OnButton();
	DECLARE_MESSAGE_MAP()

};
BEGIN_MESSAGE_MAP(MyWin32MFCWindows, CFrameWnd)
	ON_BN_CLICKED(1002, OnButton)
	END_MESSAGE_MAP()
class MyWin32MFC : public CWinApp
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
	HWND btn = ::CreateWindow(TEXT("BUTTON"), TEXT("BUTTON"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 150, 45, 160, 55, this->m_hWnd, (HMENU)1001, AfxGetInstanceHandle(), NULL);

	but = new CButton();
	CRect r(300, 400, 500, 600);
	but->Create(TEXT("btn"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, r, this, 1002);

}

void MyWin32MFCWindows::OnButton() {

	::MessageBoxW(NULL,TEXT("hello"), TEXT("hello"), MB_OK);
	//MyDlg *mg=new MyDlg();
	//mg->DoModal();
	//::DialogBoxParam(AfxGetInstanceHandle(), LPCTSTR(IDD_DIALOG1), NULL, NULL, NULL);
}


MyWin32MFC myapp;

