#include "Node.h"

Node::Node() noexcept :
	next(nullptr),
	pImpl(std::make_unique<impl>())
{}

Node::Node(Node&& node) noexcept:
	next(node.getNext()),
	pImpl(node.getValue())
{}

Node::~Node() noexcept {
}

class Node::impl {
public:
	impl() noexcept :
		value("DEAFULT") {
	}
	impl(const impl& imp) noexcept :
		value(imp.value) {
	}
	explicit impl(const std::string& s) noexcept :
		value(s) {
	}

	friend std::ostream& operator<<(std::ostream& os, const impl& imp) {
		os << imp.value;
		return os;
	}
private:
	std::string value;
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

std::ostream& operator<<(std::ostream& os, const Node& node)
{
	return os << *(node.pImpl);
}
