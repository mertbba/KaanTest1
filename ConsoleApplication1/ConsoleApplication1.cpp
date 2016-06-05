// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "binaryTree.h"


int _tmain(int argc, _TCHAR* argv[])
{
	binaryTree binTree = binaryTree();

	binTree.add(1);
	binTree.add(2);
	binTree.add(3);

	binTree.viewItems();

	node n;
	n = *binTree.find(2);

	std::cout << "2 = " << n.data << std::endl;

	int max = binTree.max_value();
	std::cout << "3 = " << max << std::endl;

	int min = binTree.min_value();
	std::cout << "1 = " << min << std::endl;

	binTree.destroy_tree();

	return 0;
}

