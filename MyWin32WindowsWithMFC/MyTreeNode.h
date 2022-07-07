#pragma once
template<class T>
class TreeNode {
public:
	T value;
	int x, y;
	TreeNode* left;
	TreeNode* right;
	TreeNode(T val,int x,int y) {
		this->value = val;
		this->x = x;
		this->y = y;
	}
	TreeNode(T val,TreeNode* & left, TreeNode*& right, int x, int y) {
		this->value = val;
		this->left = left;
		this->right = right;
		this->x = x;
		this->y = y;
	}
	void print(CPaintDC* pDC) {
		//std::string s = std::to_string(value);
	CString a;
		a.Format(_T("%d"), value);
		//»­Ô²
	//	CPoint point1(x, y);
	//	CPoint point2(x+5,y+5);
		//pDC->Ellipse(CRect(point1, point2));

		pDC->TextOut(x-3, y-10, a);

		CPoint startp(x, y);
		pDC->MoveTo(startp);
		CPoint endp(x - 20, y + 20);
		pDC->LineTo(endp);

		CPoint startp2(x, y);
		pDC->MoveTo(startp2);
		CPoint endp2(x + 20, y + 20);
		pDC->LineTo(endp2);
	}

};
//template<class T>
//inline void TreeNode::print(CPaintDC* pDC) {
//}
