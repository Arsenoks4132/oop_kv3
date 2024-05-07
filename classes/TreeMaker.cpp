#include "../headers/TreeMaker.h"
#include "../headers/Block_2.h"
#include "../headers/Block_3.h"
#include "../headers/Block_4.h"
#include "../headers/Block_5.h"
#include "../headers/Block_6.h"
#include <iostream>

TreeMaker :: TreeMaker(TreeMaker* ptr, string nm) : Base(ptr, nm) { };

void TreeMaker :: MakeTree() {
	string tm_Name;
	cin >> tm_Name;
	if (!rename(tm_Name)) {
		return;
	}
	string parent_name, child_name;
	int number;
	
	Base* parent;
	while (cin >> parent_name) {
		if (parent_name == "endtree") {
			break;
		}
		cin >> child_name >> number;
		
		parent = find_coord(parent_name);
		
		if (!parent) {
			cout << "Object tree\n";
			printTree();
			cout << "The head object " << parent_name << " is not found";
			exit(1);
		}
		
		if (parent->getName() == child_name) {
			continue;
		}
		
		if (parent->getLeaf(child_name)) {
			cout << parent_name << "     Dubbing the names of subordinate objects\n";
		}
		else {
			switch (number) {
				case 2:
					new Block_2(parent, child_name);
					break;
				case 3:
					new Block_3(parent, child_name);
					break;
				case 4:
					new Block_4(parent, child_name);
					break;
				case 5:
					new Block_5(parent, child_name);
					break;
				case 6:
					new Block_6(parent, child_name);
					break;
			}
		}
	}
};


int TreeMaker :: Start() {
	cout << "Object tree\n";
	printTree();
	cout << '\n';
	
	
	string command, coordinate;
	Base* current = this;
	Base* obj;
	while (cin >> command) {
		if (command == "SET") {
			cin >> coordinate;
			obj = current->find_coord(coordinate);
			if (obj) {
				current = obj;
				cout << "Object is set: " << current->getName() << '\n';
			}
			else {
				cout << "The object was not found at the specified coordinate: " << coordinate << '\n';
			}
		} else if (command == "FIND") {
			cin >> coordinate;
			obj = current->find_coord(coordinate);
			if (obj) {
				cout << coordinate << "     Object name: " << obj->getName() << '\n';
			}
			else {
				cout << coordinate << "     Object is not found\n";
			}
		} else if (command == "MOVE") {
			cin >> coordinate;
			
			//Убрать
			//cout << '\n';
			
			obj = current->find_coord(coordinate);
			if (!obj) {
				cout << coordinate << "     Head object is not found\n";
				continue;
			}
			if (obj->getLeaf(current->getName())) {
				cout << coordinate << "     Dubbing the names of subordinate objects\n";
				continue;
			}
			bool is_changed = current->change_parent(obj);
			if (is_changed) {
				cout << "New head object: " << obj->getName() << '\n';
			}
			else {
				cout << coordinate << "     Redefining the head object failed\n";
			}
		} else if (command == "DELETE") {
			cin >> coordinate;
			obj = current->getLeaf(coordinate);
			if (obj) {
				current->delete_leaf(coordinate);
				string s = "/" + coordinate;
				while (obj->getRoot()) {
					obj = obj->getRoot();
					s = "/" + obj->getName() + s;
				}
				cout << "The object " << s << " has been deleted\n";
			}
		} else if (command == "END") {
			break;
		}
	}
	
	cout << "Current object hierarchy tree" << endl;
	printTree();
	return 0;
};