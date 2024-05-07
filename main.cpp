#include <stdlib.h>
#include <stdio.h>
#include "TreeMaker.h"

int main()
{
	TreeMaker tree_maker(nullptr);
	tree_maker.MakeTree();
	return tree_maker.Start();
}
