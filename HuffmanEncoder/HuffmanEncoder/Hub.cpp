#include "Classes.h"

void Hub::buildMaps()
{
	int size = input.tellSize();
	int pos = 0;
	while (pos < size)
	{
		mDiv.insertMapChar(input.tellChar(pos), pos);
		mDiv.insertMapWeight(input.tellWeight(pos), pos);
		++pos;
	}
	// destroy input
}

void Hub::buildTree()
{

	while (mDiv.tellWeightMapSize() > 1 )
	{
		//elem-1 
		int w0 = mDiv.tellWeghtMap().begin()->first; // weight
		int n0 = mDiv.tellMapChar().begin()->second;// position
		mDiv.eraseMapWeightBeg();
		//elem-2 
		int w1 = mDiv.tellWeghtMap().begin()->first; // weight
		int n1 = mDiv.tellMapChar().begin()->second;// position
		mDiv.eraseMapWeightBeg();

		//insert in tree
		node nd(n0, n1);
		tree->push_back(nd);

		tree->at(n0).setParent(tree->size() - 1);
		tree->at(n0).setBranch(false);
		tree->at(n1).setParent(tree->size() - 1);
		tree->at(n1).setBranch(true);
		mDiv.insertSortedWeight(make_pair(w0 + w1, tree->size() - 1));
	}

}

