#include "Node.h"

Node::Node() noexcept :
	next(nullptr),
	pImpl(std::make_unique<impl>())
{}

Node::Node(Node&& node) noexcept:
	next(std::move(node.next)),
	pImpl(node.getValue())
{}

Node::~Node() noexcept {
}

class Node::impl {
public:
	impl() noexcept :
		stringValue("DEAFULT"), 
		indexValue(0) {
	}
	impl(const impl& imp) noexcept :
		stringValue(imp.stringValue),
		indexValue(imp.indexValue){
	}

	friend std::ostream& operator<<(std::ostream& os, const impl& imp) {
		os << imp.stringValue << '|' << imp.indexValue;
		return os;
	}
private:
	std::string stringValue;
	int indexValue;
};


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
