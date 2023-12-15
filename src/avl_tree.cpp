/*
File: avl_tree.cpp
Copyright (c) 2023 김기정, 변해광

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

/* AVL Tree basic constructor*/
template <typename ValType> AVLTree<ValType>::AVLTree() {
  root_ = NULL;
  num_of_nodes_ = 0;
}

//* root - left - left */
/* when cur_node's left child has bigger height than right child's height and
   inserted node has smaller key than left child's one */
template <typename ValType>
Node<ValType> *AVLTree<ValType>::SingleRightRotation(Node<ValType> *cur_node) {
  Node<ValType> *left_child = cur_node->left_;
  cur_node->left_ = left_child->right_;
  left_child->right_ = cur_node;
  SetHeight(cur_node, cur_node->left_, cur_node->right_);
  cur_node->size_ = GetSize(cur_node->left_) + GetSize(cur_node->right_) + 1;
  SetHeight(left_child, left_child->left_, cur_node);
  left_child->size_ = GetSize(left_child->left_) + cur_node->size_ + 1;
  return left_child;
}

/* root - right - right */
/* when cur_node's right child has bigger height than left child's height and
 * newly insterted node has bigger key than right child's one */
template <typename ValType>
Node<ValType> *AVLTree<ValType>::SingleLeftRotation(Node<ValType> *cur_node) {
  Node<ValType> *right_child = cur_node->right_;
  cur_node->right_ = right_child->left_;
  right_child->left_ = cur_node;
  SetHeight(cur_node, cur_node->left_, cur_node->right_);
  cur_node->size_ = GetSize(cur_node->left_) + GetSize(cur_node->right_) + 1;
  SetHeight(right_child, right_child->right_, cur_node);
  right_child->size_ = GetSize(right_child->right_) + cur_node->size_ + 1;
  return right_child;
}

/* root - left - right */
/* when cur_node's left child has bigger height than right child's height and
 * newly inserted node has bigger key than left child's one */
template <typename ValType>
Node<ValType> *AVLTree<ValType>::DoubleRightRotation(Node<ValType> *cur_node) {
  cur_node->left_ = SingleLeftRotation(cur_node->left_);
  cur_node = SingleRightRotation(cur_node);
  return cur_node;
}

/* root- right - left */
/* when cur_node's left child has bigger height than right child's height and
 * newly inserted node has bigger key than left child's one */
template <typename ValType>
Node<ValType> *AVLTree<ValType>::DoubleLeftRotation(Node<ValType> *cur_node) {
  cur_node->right_ = SingleRightRotation(cur_node->right_);
  cur_node = SingleLeftRotation(cur_node);
  return cur_node;
}

/* difference between heights have to be less than 2 to be balanced. */
template <typename ValType>
bool AVLTree<ValType>::IsBalanced(Node<ValType> *child_1,
                                  Node<ValType> *child_2) {
  return (GetHeight(child_1) - GetHeight(child_2) < 2);
}

/* find a node whose key matches a given key */
template <typename ValType>
Node<ValType> *AVLTree<ValType>::FindNode(Node<ValType> *cur_node,
                                          ValType key) {
  if (cur_node == NULL) {
    return NULL;
  } else if (cur_node->key_ == key) {
    return cur_node;
  } else if (cur_node->left_ != NULL && cur_node->key_ > key) {
    return FindNode(cur_node->left_, key);
  } else if (cur_node->right_ != NULL && cur_node->key_ < key) {
    return FindNode(cur_node->right_, key);
  } else {
    return NULL;
  }
}

// set height of a given node
template <typename ValType>
void AVLTree<ValType>::SetHeight(Node<ValType> *cur_node, Node<ValType> *left_node, Node<ValType> *right_node) {
  if(GetHeight(left_node) > GetHeight(right_node)){
    cur_node->height_ = GetHeight(left_node) + 1;
  }
  else {
    cur_node->height_ = GetHeight(right_node) + 1;
  }
}

/* returns -1 if cur_node is NULL, else height member */
template <typename ValType>
int AVLTree<ValType>::GetHeight(Node<ValType> *cur_node) {
  if (cur_node == NULL) {
    return -1;
  } else {
    return cur_node->GetHeight();
  }
}

// get Size of subtree
template <typename ValType>
int AVLTree<ValType>::GetSize(Node<ValType> *cur_node) {
  if (cur_node == NULL) {
    return 0;
  } else {
    return cur_node->size_;
  }
}

/* find a node which has a smallest key in subtree whose root is a give node. */
template <typename ValType>
Node<ValType> *AVLTree<ValType>::FindMinNodeOfSubtree(Node<ValType> *cur_node) {
  if (cur_node == NULL) {
    return NULL;
  } else if (cur_node->left_ == NULL) {
    return cur_node;
  } else {
    return FindMinNodeOfSubtree(cur_node->left_);
  }
}

/* find a node which has a biggest key in subtree whose root is a give node. */
template <typename ValType>
Node<ValType> *AVLTree<ValType>::FindMaxNodeOfSubtree(Node<ValType> *cur_node) {
  if (cur_node == NULL) {
    return NULL;
  } else if (cur_node->right_ == NULL) {
    return cur_node;
  } else {
    return FindMaxNodeOfSubtree(cur_node->right_);
  }
}
// get Balance of a given node for erase
template <typename ValType>
int AVLTree<ValType>::GetBalance(Node<ValType> *cur_node) {
  if (cur_node == NULL)
    return 0;
  return GetHeight(cur_node->left_) - GetHeight(cur_node->right_);
}

// get Rank of a given node
template <typename ValType>
int AVLTree<ValType>::FindRank(Node<ValType> *cur_node, ValType key) {
  if (cur_node == NULL) {
    return 0;
  } else if (cur_node->key_ > key) {
    return FindRank(cur_node->left_, key);
  } else {
    return GetSize(cur_node->left_) + FindRank(cur_node->right_, key) + 1;
  }
}

// get Depth of a given node
template <typename ValType>
int AVLTree<ValType>::FindDepth(Node<ValType> *cur_node, ValType key,
                                int depth) {
  if (cur_node == NULL) {
    return 0;
  } else if (cur_node->key_ == key) {
    return depth;
  } else if (cur_node->left_ != NULL && cur_node->key_ > key) {
    return FindDepth(cur_node->left_, key, depth + 1);
  } else if (cur_node->right_ != NULL && cur_node->key_ < key) {
    return FindDepth(cur_node->right_, key, depth + 1);
  } else {
    return 0;
  }
}

template class AVLTree<int>;
template class Node<int>;