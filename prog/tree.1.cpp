#include<iostream>
using namespace std;

struct tree {
	int inf;
	tree* right;
	tree* left;
	tree* parent;
};

tree* node(int x) {
	tree* n = new tree;
	n->inf = x;
	n->left = n->right = NULL;
	n->parent = NULL;
	return n;
}

void insert(tree*& tr, int x) {
	tree* n = node(x);
	if (!tr) {
		tr = n;
	}
	else {
		tree* y = tr;
		while (y) {
			if (n->inf > y->inf) {
				if (y->right) y = y->right;
				else {
					n->parent = y;
					y->right = n;
					break;
				}
			}
			else if (n->inf < y->inf) {
				if (y->left) y = y->left;
				else {
					n->parent = y;
					y->left = n;
					break;
				}
			}
			else {
				delete n;
				break;
			}
		}
	}
}

tree* find(tree* tr, int x) {
	if (!tr || x == tr->inf) return tr;
	if (x < tr->inf) return find(tr->left, x);
	else return find(tr->right, x);
}

void findGrChil(tree* root, int x) {
	tree* knotX = find(root, x);
	if (!knotX) {
		cout << "узла" << x << "нет" << endl;
		return;
	}

	bool child = false;
	if (knotX->left) {
		if (knotX->left->left) {
			cout << knotX->left->left->inf << " ";
			child = true;
		}
		if (knotX->left->right) {
			cout << knotX->left->right->inf << " ";
			child = true;
		}
	}

	if (knotX->right) {
		if (knotX->right->left) {
			cout << knotX->right->left->inf << " ";
			child = true;
		}
		if (knotX->right->right) {
			cout << knotX->right->right->inf << " ";
			child = true;
		}
	}
	if (!child) {
		cout << "внуков нет";
	}
	cout << endl;
}

void print(tree* tr, int level = 0) {
	if (!tr) return;
	print(tr->right, level + 1);
	for (int i = 0; i < level; i++) {
		cout << "    ";
	}
	cout << tr->inf << endl;
	print(tr->left, level + 1);
}

int main() {
	setlocale(LC_ALL, "RUS");

	tree* a = NULL;
	int n, x, knot;
	cout << "n = "; cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x;
		insert(a, x);
	}
	print(a);
	cout << endl;
	cout << "значение узла x = "; cin >> knot;
	findGrChil(a, knot);
	return 0;
}