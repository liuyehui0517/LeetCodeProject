#include "Tree.h"
#include <stdexcept>

tree::normalNode::normalNode(int index, const std::string& s):
	leftNode(nullptr), rightNode(nullptr), 
	basicNode(index, s)
{
}

tree::normalNode::~normalNode()
{
}

bool tree::normalNode::contains(int index) const
{
	if (index == this->index) return true;
	else if (index > this->index) return
		this->rightNode == nullptr ? false : this->rightNode->contains(index);
	else return
		this->leftNode == nullptr ? false : this->leftNode->contains(index);
}

std::string& tree::normalNode::get(int index)
{
	if (index == this->index) return this->getValue();
	else if (index > this->index) 
			return this->rightNode->get(index);
		else 
			return this->leftNode->get(index);
}

void tree::normalNode::set(int index, const std::string& s)
{
	if (index == this->index)
		this->value = s;
	else if (index < this->index) {
		if (this->leftNode) this->leftNode->set(index, s);
		else this->leftNode = std::make_unique<normalNode>(index, s);
	}
	else {
		if (this->rightNode) this->rightNode->set(index, s);
		else this->rightNode = std::make_unique<normalNode>(index, s);
	}
}

size_t tree::normalNode::size() const
{
	size_t leftH = (!leftNode) ? 0 : leftNode->size();
	size_t rightH = (!rightNode) ? 0 : rightNode->size();
	return leftH + rightH + 1;
}

size_t tree::normalNode::height() const
{
	size_t leftH = 0, rightH = 0;
	if (leftNode)  leftH = leftNode->height();
	if (rightNode)  rightH = rightNode->height();
	return (leftH > rightH) ? leftH + 1 : rightH + 1;
}

tree::BSTree::BSTree(int index, const std::string& s):
	root(std::make_unique<normalNode>(index, s))
{
}

std::string& tree::BSTree::get(int index)
{
	if (contains(index)) return root->get(index);
	else throw std::out_of_range("no elements");
}

tree::RBNode::RBNode(int index, const std::string& s, const COLOR& color) :
	basicNode(index, s), color(color),leftNode(nullptr),rightNode(nullptr)
{
}

std::unique_ptr<tree::RBNode>&& tree::RBTree::set(std::unique_ptr<RBNode>& node,int index, const std::string& s)
{
	if (index == node->index)
		node->value = s;
	else if (index < node->index) {
		if (node->leftNode) node->leftNode = set(node->leftNode, index, s);
		else node->leftNode = std::make_unique<RBNode>(index, s, COLOR::RED);
	}
	else {
		if (node->rightNode) node->rightNode = set(node->rightNode, index, s);
		else node->rightNode = std::make_unique<RBNode>(index, s, COLOR::RED);
	}
	
	if (isRed(node->rightNode) && !isRed(node->leftNode))
		rotateLeft(node);

	if (isRed(node->leftNode) && isRed(node->leftNode->leftNode))
		rotateRight(node);

	if (isRed(node->leftNode) && isRed(node->rightNode))
		node->flipColor();

	return std::move(node);
}

void tree::RBNode::flipColor()
{
	this->color = COLOR::RED;
	this->leftNode->color = COLOR::BLACK;
	this->rightNode->color = COLOR::BLACK;
}

size_t tree::RBNode::size() const
{
	size_t leftH = (!leftNode) ? 0 : leftNode->size();
	size_t rightH = (!rightNode) ? 0 : rightNode->size();
	return leftH + rightH + 1;
}

size_t tree::RBNode::height() const
{
	size_t leftH = 0, rightH = 0;
	if (leftNode)  leftH = leftNode->height();
	if (rightNode)  rightH = rightNode->height();
	return (leftH > rightH) ? leftH + 1 : rightH + 1;
}

bool tree::RBNode::contains(int index) const
{
	if (index == this->index) return true;
	else if (index > this->index) return
		this->rightNode == nullptr ? false : this->rightNode->contains(index);
	else return
		this->leftNode == nullptr ? false : this->leftNode->contains(index);
}

std::string& tree::RBNode::get(int index)
{
	if (index == this->index) return this->getValue();
	else if (index > this->index) 
			return this->rightNode->get(index);
		else 
			return this->leftNode->get(index);
}

void tree::RBTree::rotateLeft(std::unique_ptr<tree::RBNode>& node)
{
	auto x = std::move(node->rightNode);
	node->rightNode = std::move(x->leftNode);
	x->leftNode = std::move(node);
	x->color = x->leftNode->color;
	x->leftNode->color = COLOR::RED;
	node = std::move(x);
}

void tree::RBTree::rotateRight(std::unique_ptr<tree::RBNode>& node)
{
	auto x = std::move(node->leftNode->leftNode);
	node->leftNode = std::move(x->rightNode);
	x->rightNode = std::move(node);
	x->color = x->rightNode->color;
	x->rightNode->color = COLOR::RED;
	node = std::move(x);
}

tree::RBTree::RBTree(int index, const std::string& s):
	root(std::make_unique<RBNode>(index, s, COLOR::BLACK))
{
}

std::string& tree::RBTree::get(int index)
{
	if (contains(index)) return root->get(index);
	else throw std::out_of_range("no elements");
}

bool tree::RBTree::isRed(const std::unique_ptr<RBNode>& node)
{
	if (node == nullptr) return false;
	else return node->color == COLOR::RED;
}

