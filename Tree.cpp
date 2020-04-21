#include "Tree.h"

tree::TreeNode::TreeNode(int index, const std::string& s):
	leftNode(nullptr), rightNode(nullptr), 
	value(s),index(index)
{
}

tree::TreeNode::~TreeNode()
{
}

bool tree::TreeNode::contains(int index)
{
	if (index == this->index) return true;
	else if (index > this->index) return
		this->rightNode == nullptr ? false : this->rightNode->contains(index);
	else return
		this->leftNode == nullptr ? false : this->leftNode->contains(index);
}

std::string& tree::TreeNode::get(int index)
{
	if (index == this->index) return this->getValue();
	else if (index > this->index) 
			return this->rightNode->get(index);
		else 
			return this->leftNode->get(index);
}

void tree::TreeNode::set(int index, const std::string& s)
{
	if (index == this->index)
		this->value = s;
	else if (index < this->index) {
		if (this->leftNode) this->leftNode->set(index, s);
		else this->leftNode = std::make_unique<TreeNode>(index, s);
	}
	else {
		if (this->rightNode) this->rightNode->set(index, s);
		else this->rightNode = std::make_unique<TreeNode>(index, s);
	}
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

tree::BSTree::BSTree(int index, const std::string& s):root(index, s)
{
}

std::string& tree::BSTree::get(int index)
{
	if (contains(index)) return root.get(index);
	else throw std::out_of_range("no elements");
}

void tree::BSTree::set(int index, const std::string& s)
{
	root.set(index, s);
}


