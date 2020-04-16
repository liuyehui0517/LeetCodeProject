#pragma once
#include <memory>
namespace tree {
	class TreeNode
	{
	public:	
		friend class BSTree;
		TreeNode() = delete;

		explicit TreeNode(int v);
		~TreeNode();
		inline int getValue() { return value; }

		std::unique_ptr<TreeNode> leftNode;
		std::unique_ptr<TreeNode> rightNode;

	private:
		int value;
		size_t size();	
		size_t height();
	};

	class BSTree {
	public:
		BSTree() = delete;
		explicit BSTree(int v);
		
		inline size_t size() { return root.size(); }
		inline size_t height() { return root.height(); }
	private:
		TreeNode root;
	};
	
}
