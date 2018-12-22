#ifndef OJ6_SYMMETRICTREE_H
#define OJ6_SYMMETRICTREE_H

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <cassert>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

class SymmetricTree {
public:

	vector<int> GetBinaryTree(string filename);//用vector装树结构
	bool IsSysmetricTree(); //判断数是否对称
	int GetMaxValue(); //获得数里面节点的最大值
	vector<int> GetDiffValue(); //输出一个大小为2的vector，代表不相等的一对 值，按从小到大输出
private:
	vector<int> tree;//存储树结构
	vector<int> diff;// 根据需要自行添加成员变量
};

vector<int> SymmetricTree::GetBinaryTree(string filename) {
	ifstream infile(filename, ios::in|ios::binary);
	if (infile.fail())
		assert(false);
	int temp;
	while (true) {
		infile.read((char *)&temp, sizeof(int));\
		if (infile.fail())
			break;
		tree.emplace_back(temp);
	}
	return tree;
}

bool SymmetricTree::IsSysmetricTree() {
	if (tree.empty())
		return false;
	int count = (int)pow(2, floor(log(tree.size())/log(2)) + 1);
	while (tree.size() < count - 1)
		tree.emplace_back(-1);

	int idx = 0, length = 1;
	while (idx < tree.size() - 1) {
		int p = idx, q = idx + length - 1;
		assert(q < tree.size());
		while (p < q) {
			if (tree[p] != tree[q]) {
				diff.emplace_back(tree[p]);
				diff.emplace_back(tree[q]);
				sort(diff.begin(), diff.end());
				return false;
			}
			++p;
			--q;
		}

		idx += length;
		length *= 2;
	}
	diff.emplace_back(0);
	diff.emplace_back(0);
	return true;
}

int SymmetricTree::GetMaxValue() {
	return *max_element(tree.begin(), tree.end());
}

vector<int> SymmetricTree::GetDiffValue() {
	return diff;
}


#endif
