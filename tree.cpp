/** 	
　　Singleton模式的实现
　　File		:singleton.cpp 
　　Author		:singmelody 
　　Date		:2012.11.19
*/
#include <iostream>
#include<iostream>
#include<vector>
#include<list>
#include <string.h>
//#include <WinBase.h>
using namespace std;



#if 1
struct node {
	int data;
	node *right, *left;
};

using namespace std;
void findLevelLinkedLists(vector<list<node*> > &res, node* root);
void printLevelLinkedLists(vector<list<node*> > res);

void createMinimalBst(node* &root, int arr[], int start, int end) {
	if (start>end)
		return;
	if (root == NULL) {
		node *ptr = new node;
		int ind = start + (end - start) / 2;
		ptr->data = arr[ind];
		ptr->left = NULL;
		ptr->right = NULL;
		root = ptr;
		createMinimalBst(root->left, arr, start, ind - 1);
		createMinimalBst(root->right, arr, ind + 1, end);
	}
}

void printIfSum(int* arr, int sum, int len) {
	for (int i = 0; i<len; i++) {
		int s = 0;
		for (int j = i; j<len; j++) {
			s += arr[j];
			if (s == sum) {
				for (int k = i; k <= j; k++)
					cout << arr[k] << " ";
				cout << '\n';
			}
		}
	}
}

void print(node *root, int sum, int *path, int level) {
	if (root == NULL) {
		return;
	}
	path[level] = root->data;
	int s = 0;
	for (int i = level; i >= 0; i--) {
		s += path[i];
		if (s == sum) {
			for (int j = level; j >= i; j--)
				cout << path[j] << " ";
			cout << '\n';
		}
	}
	if (root->left)
		print(root->left, sum, path, level + 1);
	if (root->right)
		print(root->right, sum, path, level + 1);
}

int PrintNodeAtLevel(node* root, int level)
{
	if (!root || level < 0)
		return 0;
	else if (level == 0)
	{
		cout << root->data << "  ";
		return 1;
	}
	else
		return PrintNodeAtLevel(root->left, level - 1) + PrintNodeAtLevel(root->right, level - 1);
}
void TranverseTree(node* root)
{
	for (int i = 0; ; ++i)
	{
		if (!PrintNodeAtLevel(root, i))
			break;
		cout << "_____________________________" << endl;
	}
}
int main() {
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	node *root;
	root = NULL;
	createMinimalBst(root, arr, 0, 8);
	cout << "print level start\n";
	int num = PrintNodeAtLevel(root, 2);
	cout << "\n";
	cout << " the number is " << num<<"\n";
	cout << "print level End\n";
	cout << "print tree by level Start\n";
	TranverseTree(root);
	cout << "print tree by level End\n";
	vector<list<node*> > res;
	findLevelLinkedLists(res, root);
	cout << "print tree" << "\n";

	printLevelLinkedLists(res);
	cout << "print tree End" << "\n";
	int path[100];
	print(root, 7, path, 0);
}

void findLevelLinkedLists(vector<list<node*> > &res, node* root) {
	list<node*> li;
	li.push_back(root);
	res.push_back(li);
	int depth = 0;
	while (!res[depth].empty()) {
		list<node*> l;
		list<node*>::iterator iter;
		for (iter = res[depth].begin(); iter != res[depth].end(); iter++) {
			node *ptr = *iter;
			if (ptr->left)
				l.push_back(ptr->left);
			if (ptr->right)
				l.push_back(ptr->right);
		}
		res.push_back(l);
		depth++;
	}
}

void printLevelLinkedLists(vector<list<node*> > res) {
	vector<list<node*> >::iterator iter;
	for (iter = res.begin(); iter != res.end(); iter++) {
		list<node*> li = *iter;
		list<node*>::iterator it;
		for (it = li.begin(); it != li.end(); it++) {
			node* ptr = *it;
			cout << ptr->data << " ";
		}
		cout << '\n';
	}
}