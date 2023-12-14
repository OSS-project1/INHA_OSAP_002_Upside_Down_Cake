/*
File: insert.cpp
Copyright (c) 2023 변해광

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
#include "avl_tree.h"

// Deletes a node from the AVL tree
template<typename ValType>
Node<ValType> *AVLTree<ValType>::EraseNode(Node<ValType> *cur_node, ValType key) {
  // If the element is not found, return NULL
  if (cur_node == NULL) {
	return NULL;
  }

	// If the key is smaller than the node's key, go to the left child
  else if (key < cur_node->key_) {
	cur_node->left_ = EraseNode(cur_node->left_, key);
  }
	// If the key is greater than the node's key, go to the right child
  else if (key > cur_node->key_) {
	cur_node->right_ = EraseNode(cur_node->right_, key);
  }

	// When the key is found and the node has two children
  else if (cur_node->right_ && cur_node->left_) {
	Node<ValType> *temp = FindMinNodeOfSubtree(cur_node->right_);
	cur_node->key_ = temp->key_;
	cur_node->right_ = EraseNode(cur_node->right_, cur_node->key_);
  }

	// When the key is found and the node has one or zero child
  else {
	Node<ValType> *temp = cur_node;
	if (cur_node->left_ == NULL) {
	  cur_node = cur_node->right_;
	} else if (cur_node->right_ == NULL) {
	  cur_node = cur_node->left_;
	}
	free(temp);
  }

  // If the current node is NULL after deletion, return NULL
  if (cur_node == NULL) {
	return NULL;
  }

  // Update the height and size of the current node
  set_height(cur_node, 3);
  cur_node->size_ = GetSize(cur_node->left_) + GetSize(cur_node->right_) + 1;

  // Get the balance factor of the current node to check whether
  // this node became unbalanced
  int balance = GetBalance(cur_node);

  // If this node becomes unbalanced, then there are 4 cases

  // Left-Left Case
  if (balance > 1 && GetBalance(cur_node->left_) >= 0) {
	return single_right_rotation(cur_node);
  }

	// Left-Right Case
  else if (balance > 1 && GetBalance(cur_node->left_) < 0) {
	return double_right_rotation(cur_node);
  }

	// Right-Right Case
  else if (balance < -1 && GetBalance(cur_node->right_) <= 0) {
	return single_left_rotation(cur_node);
  }

	// Right-Left Case
  else if (balance < -1 && GetBalance(cur_node->right_) > 0) {
	return double_left_rotation(cur_node);
  }

  return cur_node;
}


template <typename ValType> class AVLTree;
template <typename ValType> class Node;