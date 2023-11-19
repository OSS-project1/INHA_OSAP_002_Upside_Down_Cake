/*
File: avl_tree.h
Copyright (c) 2023 김기정

MIT License

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:
The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include <iostream>
#ifndef AVLTREE_H
#define AVLTREE_H

// Define Set
class AVLTree { 
protected:
        // AVL Tree is composed of Nodes
        struct Node {
        public:
                // members
                int key_;
                Node* left_; 
                Node* right_; 
                int height_; 
                int depth_;

                // Node constructor
                Node(int key) {
                        key_ = key;
                        left_ = right_ = NULL;
                        height_ = depth_ = -1;
                }
        };

protected:
		//AVLTree constructor
        AVLTree();
		// insert a node
        Node* insert_Node(Node* cur_node, int key);
		// Find node matcheds a key 
        Node* find_Node(int key); 
		// Get Rank by a given node
        int find_Rank(Node* cur_node);
		// Erase a node matches a given key
        Node* erase(Node* cur_node, int key); 
		// Single righr rotation
        Node* single_Right_Rotation(Node* cur_node);
		// double right rotation
        Node* double_Right_Rotation(Node* cur_node);
		// single left rotation
        Node* single_Left_Rotation(Node* cur_node);
		// double left rotation
        Node* double_Left_Rotation(Node* cur_node);
		// set height of a given node
        void set_Height(Node* cur); 
		// get height of a given node
        int get_Height(Node* cur); 
		// set dpeth of a given node
        void set_Depth(Node* cur); 
		// get depth of a given node
        int get_Depth(Node* cur); 

protected:
        // members
        Node* root_; 
        size_t num_of_nodes_; 
};
#endif
