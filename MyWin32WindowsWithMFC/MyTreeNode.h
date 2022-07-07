#pragma once
template<class T>
class TreeNode {
public:
	T value;
	int x, y;
	TreeNode* left=NULL;
	TreeNode* right=NULL;
	void setLeft(TreeNode*& left) {
		this->left = left;
		this->left->x = this->x - 20;
		this->left->y = this->y + 20;
	}

	void setRight(TreeNode*& right) {
		this->right = right;
		this->right->x = this->x + 20;
		this->right->y = this->y + 20;
	}
	TreeNode(T val) {
		this->value = val;
	
	}
	TreeNode(T val,int x,int y) {
		this->value = val;
		this->x = x;
		this->y = y;
	}
	TreeNode(T val, TreeNode*& left, TreeNode*& right) {
		this->value = val;
		this->left = left;
		this->right = right;
		this->left->x = this->x - 20;
		this->left->y = this->y + 20;

		this->right->x = this->x + 20;
		this->right->y = this->y + 20;

	}
	TreeNode(T val,TreeNode* & left, TreeNode*& right, int x, int y) {
		this->value = val;
		this->left = left;
		this->right = right;
		this->x = x;
		this->y = y;


		this->left->x = this->x - 20;
		this->left->y = this->y +20;

		this->right->x = this->x + 20;
		this->right->y = this->y + 20;
	
	}
	void print(CPaintDC* pDC, TreeNode* root) {
		//std::string s = std::to_string(value);
		CString a;
		a.Format(_T("%d"), root->value);
		//»­Ô²
	//	CPoint point1(x, y);
	//	CPoint point2(x+5,y+5);
		//pDC->Ellipse(CRect(point1, point2));

		pDC->TextOut(root->x - 3, root->y - 10, a);
		if (root != NULL && root->left != NULL) {
			CPoint startp(root->x, root->y);
			pDC->MoveTo(startp);
			CPoint endp(root->x - 20, root->y + 20);
			pDC->LineTo(endp);
		}
		if (root != NULL && root->right != NULL) {
		CPoint startp2(root->x, root->y);
		pDC->MoveTo(startp2);
		CPoint endp2(root->x + 20, root->y + 20);
		pDC->LineTo(endp2);
	}
		Sleep(1000);
	}
	void PreOrder(TreeNode* root, CPaintDC* pDC) {
		print(pDC, root);
		if(root!=NULL&&root->left!=NULL)
		PreOrder(root->left, pDC);
		print(pDC, root);
		if (root != NULL && root->right != NULL)
		PreOrder(root->right, pDC);
	}

};

//template<class T>
//inline void TreeNode::print(CPaintDC* pDC) {
//}
