#include "SymmetricTree.h"


int main() {
	string filename = "../1.txt";
	SymmetricTree *tree = new SymmetricTree();
	tree->GetBinaryTree(filename);
	cout << tree->IsSysmetricTree() << endl;
	cout << tree->GetMaxValue () << endl;
	vector<int> diffValue = tree->GetDiffValue();
	cout << diffValue[0] << "\t" << diffValue[1] << endl;
	return 0;
}