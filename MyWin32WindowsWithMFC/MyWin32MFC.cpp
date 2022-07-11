#include "MyWin32MFC.h"
#include "MyDlg.h"
#include "MyTreeNode.h"
#include <afxwin.h>
#include <iostream>
#include <vector>
class MyWin32MFCWindows : public CFrameWnd
{
public:
	TreeNode<int>* root;
	std::vector<TreeNode<int>*> list;
	TreeNode<int>* choosedNode;
	CPaintDC *pdc;
	MyDlg* dlg;
	CButton* but;
	MyWin32MFCWindows();
	afx_msg void OnButton();
	afx_msg void OnPaint();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	DECLARE_MESSAGE_MAP()

};
BEGIN_MESSAGE_MAP(MyWin32MFCWindows, CFrameWnd)
	ON_BN_CLICKED(1002, OnButton)
	ON_WM_PAINT(OnPaint)
	ON_WM_LBUTTONDOWN(OnLButtonDown)
	ON_WM_LBUTTONUP(OnLButtonUp)
	ON_WM_MOUSEMOVE(OnMouseMove)
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

	
	TreeNode<int> * left=new TreeNode<int>(1);
	TreeNode<int>* right = new TreeNode<int>(6);
     root = new TreeNode<int>(4,left,right,700,100);

	 TreeNode<int>* rleft = new TreeNode<int>(5);
	 TreeNode<int>* rright = new TreeNode<int>(7);
	 right->setLeft(rleft);
	 right->setRight(rright);
	 TreeNode<int>* right8 = new TreeNode<int>(9);
		 rright->setRight(right8);
	 TreeNode<int>*left0 = new TreeNode<int>(0);
	 TreeNode<int>* right2 = new TreeNode<int>(2);
	 left->setLeft(left0);
	 left->setRight(right2);

	 TreeNode<int>* right3 = new TreeNode<int>(3);
	 right2->setRight(right3);
	 root->GetList(root, list);
	

}

void MyWin32MFCWindows::OnButton() {

	//::MessageBoxW(NULL,TEXT("hello"), TEXT("hello"), MB_OK);
	//dlg=new MyDlg();
	//dlg->DoModal();
	//::DialogBoxParam(AfxGetInstanceHandle(), LPCTSTR(IDD_DIALOG1), NULL, NULL, NULL);
	
	//root->btstoGst(root,pdc);
	//root->btstoGst(root);
	//root->x = 1000;
	//root->PreOrder(root, pdc);

}
void MyWin32MFCWindows::OnLButtonDown(UINT flag,CPoint p) {

	

	std::vector<TreeNode<int>*>::iterator it;//声明一个迭代器，来访问vector容器，作用：遍历或者指向vector容器的元素 
	for (it = list.begin(); it != list.end(); it++)
	{
		TreeNode<int>* node = (*it);
		std::cout << *it << " ";
		if (abs(node->x - p.x) < 5 && abs(node->y - p.y) < 5)
		{
			CString a;
			a.Format(_T("%d,%d"), node->x, p.x);
			//::AfxMessageBox(a);
			choosedNode = node;
		}


	}



}
void MyWin32MFCWindows::OnLButtonUp(UINT flag, CPoint p) {


	choosedNode->x = p.x;
	choosedNode->y = p.y;
	Invalidate();



}
void MyWin32MFCWindows::OnMouseMove(UINT flag, CPoint p) {

	std::vector<TreeNode<int>*>::iterator it;//声明一个迭代器，来访问vector容器，作用：遍历或者指向vector容器的元素 
	for (it = list.begin(); it != list.end(); it++)
	{
		TreeNode<int>* node = (*it);
		std::cout << *it << " ";
		if (abs(node->x - p.x) < 5 && abs(node->y - p.y) < 5)
		{
			CString a;
			a.Format(_T("%d,%d"), node->x, p.x);
			//::AfxMessageBox(a);
			node->x = p.x;
			node->y = p.y;
		//  	node->resetTree(node);
		}


	}



}

void MyWin32MFCWindows::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 在此处添加消息处理程序代码
					   // 不为绘图消息调用 CDialog::OnPaint()
	 pdc = &dc; 
//在鼠标处画图
	//CPoint curPos;
	//GetCursorPos(&curPos);
	root->PreOrder(root, &dc);
	/*CString a;
	a.Format(_T("%d"), root->heightofTree(root));
	AfxMessageBox(a, MB_OK);*/

	/*CString a;
	a.Format(_T("%d"), root->isValidBST(root)->result);
	AfxMessageBox(a, MB_OK);*/
	

	CString a;
	root->absMinTwoBSTNodes(root);
	a.Format(_T("%d"), root->min);
	AfxMessageBox(a, MB_OK);


	

	//root->btstoGst3(root,&dc);

	 /*TreeNode<int>* ret= root->leastcommonancestor(root, 5, 8, &dc);
	 CString a;
	 a.Format(_T("%d"), ret->value);
	 AfxMessageBox(a, MB_OK);
	 */

	// TreeNode<int>* ret = root->insertBSTNode(root, 8, &dc);
	// root->PreOrder( root, &dc);

	// TreeNode<int>* ret = root->deleteBSTNode(root, 1, &dc);
	// root->PreOrder(root, &dc);

	
}


MyWin32MFC myapp;

