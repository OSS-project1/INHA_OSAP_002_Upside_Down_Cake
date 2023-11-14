#include <iostream>
#ifndef AVLTREE_H
#define AVLTREE_H	

// Define Set
class AVLTree { 
private:
	friend class Set;
	// AVL Tree is composed of Nodes
	struct Node {
	public:
		// members
		int key_;
		Node* left_; // left child
		Node* right_; // right child
		int height_; 
		int depth_;

		// Node constructor
		Node(int key) {
			key_ = key;
			left_ = right_ = NULL;
			height_ = depth_ = -1;
		}
	};

private:
	AVLTree();
	Node* Insert_Node(Node* cur_node, int key); // for insert
	Node* Find_Node(int key); // for Get methods except for Get_Size
	Node* Get_Rank(Node* cur_node); // for Get Rank
	Node* Erase(Node* cur_node, int key); // for Erase
	Node* Single_Right_Rotation(Node* cur_node);
	Node* Double_Right_Rotation(Node* cur_node);
	Node* Single_Left_Rotation(Node* cur_node);
	Node* Double_Left_Rotation(Node* cur_node);
	int Set_Height(); // for Erase and Insert to maintain AVL Tree structure
	int Get_Height(); // for Erase and Insert to maintain AVL Tree structure
	int Set_Depth(); // Get rank of node
	int Get_Depth(); // Set rank of node	

private:
	// members
	Node* root_; // root node
	size_t num_of_nodes_; // size of Set
};
#endif


