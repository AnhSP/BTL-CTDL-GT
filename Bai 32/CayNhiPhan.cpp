#include<iostream>
using namespace std;
struct Node {
    int value;
    Node* left;
    Node* right;
};
class BinaryTree {
private:
    Node* root;
	
	Node* createNode(int val); 
	Node* buildTree(int start, int end);
	int calculateSize(Node* node);
	int calculateHeight(Node* node);
	int calculateHeightFromValue(int value);
	void findLeafsFromX(Node* tmp, int n, int a[], int& index);
	void printTree(Node* tmp);
public:
    BinaryTree(int n) {
        this->root = NULL;
        if (n < 1 || n > 100) {
            cout << "Gia tri n da vuot qua nguong cho phep(1<= n<= 100)!  Mac dinh se chuyen n=11\n";
            n = 11;
        } else if (n % 2 == 0) {
            cout << "Vui long nhap n la 1 so le!!!(n la so chan se duoc mac dinh tru di 1)\n";
            n--;
            cout << "Hien tai: n= " << n << endl;
        }
        root = buildTree(1, n);
    }
    void print();
    int size();
    int height();
    Node* findByValue(Node* tmp, int n, int x);
    bool canSecondPlayerWin(int x);
};
Node* BinaryTree::createNode(int val) {
    Node* newNode = new Node;
    newNode->value = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* BinaryTree::buildTree(int start, int end) {
    if (start > end) {
        return NULL;
    }
    Node* newNode = createNode(start);
    newNode->left = buildTree(start * 2, end);
    newNode->right = buildTree(start * 2 + 1, end);
    return newNode;
}
void BinaryTree::printTree(Node* tmp){
   if (tmp != NULL) {
        cout << tmp->value << " ";
        printTree(tmp->left);
        printTree(tmp->right);
    }
}

void BinaryTree::print(){
	cout<<"Cac gia tri co trong cay la: \n";
	printTree(this->root);
	cout<<endl;
}
int BinaryTree::calculateSize(Node* tmp) {
    if (tmp == NULL) {
        return 0;
    }
    return calculateSize(tmp->left) + calculateSize(tmp->right) + 1;
}
int BinaryTree::size(){
	return this->calculateSize(this->root);
}
int BinaryTree::calculateHeight(Node* tmp) {
    if (tmp == NULL) {
        return 0;
    } else {
        int leftHeight = calculateHeight(tmp->left);
        int rightHeight = calculateHeight(tmp->right);
        return 1 + max(leftHeight, rightHeight);
    }
}
int BinaryTree::height(){
	return this->calculateHeight(this->root);
}
int BinaryTree::calculateHeightFromValue(int value) {
    int depth = 0;
    int nodes = 0;
    while (nodes < value) {
        nodes = nodes * 2 + 1;
        depth++;
    }
    return depth;
}
void BinaryTree::findLeafsFromX(Node* tmp, int n, int a[], int& index) {
    if (tmp == NULL) {
        return;
    }

    if (tmp->left == NULL && tmp->right == NULL) {
        int leafDepth = this->calculateHeightFromValue(tmp->value);
        a[index++] = leafDepth;
        return;
    }

    findLeafsFromX(tmp->left, n, a, index);
    findLeafsFromX(tmp->right, n, a, index);
}

Node* BinaryTree::findByValue(Node* tmp, int n, int value) {
    if (tmp == NULL || tmp->value == value) {
        return tmp;
    }

    Node* leftResult = findByValue(tmp->left, n, value);
    Node* rightResult = findByValue(tmp->right, n, value);
    if (leftResult == NULL) {
        return rightResult;
    }
    if (rightResult == NULL) {
        return leftResult;
    }
    if (leftResult->value != value && rightResult->value != value) {
        return (leftResult->value < rightResult->value) ? leftResult : rightResult;
    }
    return (leftResult->value == value) ? leftResult : rightResult;
}

bool BinaryTree::canSecondPlayerWin(int x) {
    int n = size();
    if (n == 0) {
        cout << "Cay dang rong!\n";
        return false;
    }
	int a[n]={ }, index=0;
    if (x >= 1 && x <= n) {
        int h = height();
        Node* xInTree= this->findByValue(root, n, x);
        
		findLeafsFromX(xInTree, n, a, index);
		
        int maxHeightOfX = a[0];
        if(x!=this->root->value){
            for (int i=1; i<index; i++) {
                maxHeightOfX= max(maxHeightOfX, a[i]);
            }
		}else{
			for (int i=1; i<index; i++) {
                maxHeightOfX = min(maxHeightOfX, a[i]);
            }
		}
        return (maxHeightOfX < h);
    } else {
        cout << "Gia tri x khong hop le!\n";
        return false;
    }
}
