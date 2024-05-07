#ifndef __TREEMAKER__H
#define __TREEMAKER__H
#include "Base.h"

class TreeMaker : public Base {
	public:
		TreeMaker(TreeMaker* ptr, string nm = "StandartName");
		void MakeTree();
		int Start();
};

#endif
