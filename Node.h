#pragma once
#include <memory>

#ifdef __cpp_lib_experimental_propagate_const
#include <propagate_const>
#else
#include "propagate_const.h"
#endif

using std::experimental::propagate_const;
class Node
{
	class impl;
	std::experimental::propagate_const<std::unique_ptr<impl>> pImpl;
	std::unique_ptr<Node> next;
public:
	Node() = delete;
	Node(const Node& node) = delete;
	Node(Node&& node) noexcept;
	explicit Node(int v) noexcept;
	~Node() noexcept;
	std::unique_ptr<Node>&& getNext() noexcept;
	std::experimental::propagate_const<std::unique_ptr<impl>>&& 
		getValue() noexcept;
};

