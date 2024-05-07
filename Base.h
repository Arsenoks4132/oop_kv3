#ifndef __BASE__H
#define __BASE__H
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

class Base {
	public:
		//KV_1_______________________
		Base(Base* header, string l_name = "StandartName");
		~Base();
		
		bool rename(string l_name);
		string getName();
		Base* getRoot();
		Base* getLeaf(string l_name);
		//KV_1_______________________
	
		
		
		//KV_2_______________________
		Base* find_branch(string f_name);
		Base* find_tree(string f_name);
		void printTree();
		void printReady();
		void set_state(int state);
		//KV_2______________________
		
		
		
		//KV_3_____________________
		bool change_parent(Base* p_point);
		void delete_leaf(string l_name);
		Base* find_coord(string coord);
		//KV_3_____________________
	
	protected:
		//KV_1_______________________
		string name;
		Base* root;
		vector <Base*> leaves;
		//KV_1_______________________
		
		
		
		//KV_2______________________
		int state;
		//KV_2______________________
};

#endif
