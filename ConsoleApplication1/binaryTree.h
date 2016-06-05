#include <iostream>

struct node {
	int data;
	node *left;
	node *right;
};

//binaryTree Class Implementation
class binaryTree{
	public:
		binaryTree();
		~binaryTree();
		void add(int data_value);
		node *find(int data_value);
		void destroy_tree();
		int max_value();
		int min_value();
		void binaryTree::viewItems();
	private:
		node *find(int data_value, node *dal);
		void add(int data_value, node *dal);
		void destroy_tree(node *dal);
		node *kok;
};
