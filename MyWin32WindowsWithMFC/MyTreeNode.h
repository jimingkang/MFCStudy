#pragma once
template<class T>
class TreeNode {
public:
	T value;
	int x, y;
	int spacex=30;
	int spacey = 30;
	TreeNode* left=NULL;
	TreeNode* right=NULL;
	void setLeft(TreeNode*& left) {
		this->left = left;
		this->left->x = this->x - spacex;
		this->left->y = this->y + spacey;
	}

	void setRight(TreeNode*& right) {
		this->right = right;
		this->right->x = this->x + spacex;
		this->right->y = this->y + spacey;
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
		this->left->x = this->x - spacex;
		this->left->y = this->y + spacey;

		this->right->x = this->x + spacex;
		this->right->y = this->y + spacey;

	}
	TreeNode(T val,TreeNode* & left, TreeNode*& right, int x, int y) {
		this->value = val;
		this->left = left;
		this->right = right;
		this->x = x;
		this->y = y;


		this->left->x = this->x - spacex;
		this->left->y = this->y + spacey;

		this->right->x = this->x + spacex;
		this->right->y = this->y + spacey;
	
	}
	void print(CPaintDC* pDC, TreeNode* root) {
		//std::string s = std::to_string(value);
	//	CPen NewPen;
	//	NewPen.CreatePen(PS_SOLID, 6, RGB(255, 0, 0));
	//	CPen* oldPen = pDC->SelectObject(&NewPen);
		

		COLORREF newtextcolour = COLORREF RGB(255, 0, 0);
		pDC->SetTextColor(newtextcolour);

		CString a;
		a.Format(_T("%d"), root->value);
		//��Բ
	//	CPoint point1(x, y);
	//	CPoint point2(x+5,y+5);
		//pDC->Ellipse(CRect(point1, point2));

		pDC->TextOut(root->x - 3, root->y - 10, a);
	//	pDC->SelectObject(&oldPen);
		if (root != NULL && root->left != NULL) {
			CPoint startp(root->x, root->y);
			pDC->MoveTo(startp);
			CPoint endp(root->x - spacex, root->y + spacey);
			pDC->LineTo(endp);
		}
		if (root != NULL && root->right != NULL) {
		CPoint startp2(root->x, root->y);
		pDC->MoveTo(startp2);
		CPoint endp2(root->x + spacex, root->y + spacey);
		pDC->LineTo(endp2);
	}
		
		Sleep(1000);
	}
	void PreOrder(TreeNode* root, CPaintDC* pDC) {
		print(pDC, root);
		if(root!=NULL&&root->left!=NULL)
		PreOrder(root->left, pDC);
	
		if (root != NULL && root->right != NULL)
		PreOrder(root->right, pDC);
	}

	//btstoGst method 1
	TreeNode* btstoGst(TreeNode* root, CPaintDC* pDC) {
	
		if (root == NULL)
			return NULL;
	


		TreeNode* right = btstoGst(root->right, pDC);
	
		

		TreeNode* left = btstoGst(root->left, pDC);
		root->value += left == NULL ? 0 : left->value + right == NULL ? 0 : right->value;
		print(pDC, root);
		
		return root;

		

	}
	// btstoGst method 2
	TreeNode* btstoGst2(TreeNode* root) {
		if (root == NULL)
			return NULL;
		/*if (root != NULL && root->right == NULL && root->left == NULL)
		{
			return root;

		}*/


	
			TreeNode* right = btstoGst(root->right);
			TreeNode* left = btstoGst(root->left);
			
		root->value +=( left == NULL ? 0 : left->value + right == NULL ? 0 : right->value);
		return root;

		//print(pDC, root);

	}

	// btstoGst method 3 ��׼�� //https://juejin.cn/post/6931998186513334286  538
	TreeNode* btstoGst3(TreeNode* root, CPaintDC* pDC) {
		static int preval = 0;
		if (root == NULL)
			return NULL;

		
			TreeNode* right = btstoGst3(root->right, pDC);
			root->value += preval;
				preval=root->value;
		
			TreeNode* left = btstoGst3(root->left, pDC);
			
		

		
		print(pDC, root);
		return root;


	}
	//leetcode 236 leasecommonancestor
	TreeNode* leastcommonancestor(TreeNode* root, int p, int q, CPaintDC* pDC) {
		if (root == NULL)
			return NULL;
		if (root != NULL && (root->value == p|| root->value == q))
			return root;
		TreeNode* left = leastcommonancestor(root->left,  p,  q,pDC);
		TreeNode* right = leastcommonancestor(root->right, p, q, pDC);
		if (left != NULL && right != NULL)
			return root;

		print(pDC, root);
		return left != NULL ? left : right;
	}

	//leetcode 701
	TreeNode* insertBSTNode(TreeNode* root, int p,  CPaintDC* pDC) {
		if (root == NULL)
		{
			TreeNode<int>* newNode = new TreeNode<int>(p);
			return newNode;
		}
		if (root != NULL && (root->value < p))
		{
			TreeNode* right = insertBSTNode(root->right, p, pDC); //�����ﷵ�ؽڵ�9��7��6��4
			root->setRight(right);        //�������Ϸ��أ����������,�ظ�����right�ڵ�,��Ӱ��
		}
		else 	if (root != NULL && (root->value > p))
		{
			TreeNode* left = insertBSTNode(root->left, p, pDC); //�����ﷵ���½ڵ�8
			root->setLeft(left); //�������Ϸ���,����8 ���������,����9�Ľڵ�8����Ϊ8��9����ڵ�
		}
		
		
		//print(pDC, root);
		return root;   //�������Ϸ���9 7 6 4
	}


};

//template<class T>
//inline void TreeNode::print(CPaintDC* pDC) {
//}
