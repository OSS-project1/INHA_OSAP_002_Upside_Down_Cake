#include "avl_tree.h"

#ifndef SET_H
#define SET_H

// Define Set
class Set { 

public:
	Set(); // Set constructor
	int Insert(int key);// insert a node storing key and print depth of it
	int Erase(int key); // erase a node storing key and print depth of it 
	int Find(int key); // print depth of a node storing key
	int Get_Rank(int key); // print rank and depth of a node storing key
	int Get_Min_Key(int key); // get a min key of node from a subtree whose root is a node storing key
	int Get_Max_Key(int key); // get a max key of node from a subtree whose root is a node storing key
	int Get_Size(); // get the number of nodes in Set
	bool Is_Empty(); // get true if Set is empty

private:
	// members
	AVLTree avl_tree_;
};
#endif

