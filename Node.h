#pragma once
#include <memory>
#include <string>
#include <ostream>
#ifdef __cpp_lib_experimental_propagate_const
#include <propagate_const>
#else
#include "propagate_const.h"
#endif

using std::experimental::propagate_const;
class Node
{
public:
	class impl;
	friend std::ostream& operator<<(std::ostream& os, const Node& node);
	
	Node() noexcept;
	Node(const Node& node) = delete;
	Node(Node&& node) noexcept;

	~Node() noexcept;
	std::unique_ptr<Node>&& getNext() noexcept;
	std::experimental::propagate_const<std::unique_ptr<impl>>&& 
		getValue() noexcept;
private:
	std::experimental::propagate_const<std::unique_ptr<impl>> pImpl;
	std::unique_ptr<Node> next;
};

