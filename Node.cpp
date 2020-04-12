#include "Node.h"

Node::Node(Node&& node) noexcept:
	next(node.getNext()),
	pImpl(node.getValue())
{

}

Node::Node(int v) noexcept :
	pImpl(std::make_unique<impl>(v)),
	next(nullptr)
{
}
Node::~Node() noexcept {
}

class Node::impl {
public:
	impl(int v):
		value(v) {
		;
	}
private:
	int value;
};

std::unique_ptr<Node>&& Node::getNext() noexcept
{
	return std::move(next);
}

std::experimental::propagate_const
<std::unique_ptr<Node::impl>>&& 
Node::getValue() noexcept
{
	return std::move(pImpl);
}