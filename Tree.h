#pragma once
#include <memory>
#include <string>
#include <stdexcept>
namespace tree {
	class TreeNode
	{
	public:	
		friend class BSTree;
		TreeNode() = delete;

		explicit TreeNode(int index, const std::string& s);
		~TreeNode();
		inline std::string& getValue() { return value; }
		inline int getIndex() { return index; }
		
		std::unique_ptr<TreeNode> leftNode;
		std::unique_ptr<TreeNode> rightNode;
	private:
		int index;
		std::string value;
		size_t size();	
		size_t height();
		bool contains(int index);
		std::string& get(int index);
		void set(int index, const std::string& s);
	};

	class BSTree {
	public:
		BSTree() = delete;
		explicit BSTree(int index = 0, const std::string& s = "");
		
		inline size_t size() { return root.size(); }
		inline size_t height() { return root.height(); }
		inline bool contains(int index) { return root.contains(index); }
		std::string& get(int index);
		void set(int index, const std::string& s);
	private:
		TreeNode root;
	};
	
}
