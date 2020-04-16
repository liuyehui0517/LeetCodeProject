#include "Tree.h"

tree::TreeNode::TreeNode(int v):
	leftNode(nullptr), rightNode(nullptr), 
	value(v)
{
}

tree::TreeNode::~TreeNode()
{
}

size_t tree::TreeNode::size()
{
	size_t leftH = (!leftNode) ? 0 : leftNode->size();
	size_t rightH = (!rightNode) ? 0 : rightNode->size();
	return leftH + rightH + 1;
}

size_t tree::TreeNode::height()
{
	size_t leftH = 0, rightH = 0;
	if (leftNode)  leftH = leftNode->height();
	if (rightNode)  rightH = rightNode->height();
	return (leftH > rightH) ? leftH + 1 : rightH + 1;
}

tree::BSTree::BSTree(int v):root(v)
{
}
