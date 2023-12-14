/*
File: insert.cpp
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

/*
    insert a node storing a given key to AVL tree
    1. this function traverse nodes recursively from root untill it meets
   NULL(leaf).
    2. then, check if tree is balanced at each node this function traversed.
*/

template <typename ValType>
Node<ValType> *AVLTree<ValType>::InsertNode(Node<ValType> *cur_node,
                                            ValType key) {

  /* if meets leaf(NULL), make a new node */
  if (cur_node == NULL) {
    cur_node = new Node<ValType>(key);
  }

  /* if new key is smaller than current node's key, become a left child */
  else if (cur_node->key_ > key) {
    cur_node->left_ = InsertNode(cur_node->left_, key);
    /* balancing */
    if (!IsBalanced(cur_node->left_, cur_node->right_)) {
      if (cur_node->left_->key_ > key) {
        cur_node = SingleRightRotation(cur_node);
      } else {
        cur_node = DoubleRightRotation(cur_node);
      }
    }
  }

  /* if new key is bigger than current node's key, become a right child */
  else {
    cur_node->right_ = InsertNode(cur_node->right_, key);
    if (!IsBalanced(cur_node->right_, cur_node->left_)) {
      if (cur_node->right_->key_ < key) {
        cur_node = SingleLeftRotation(cur_node);
      } else {
        cur_node = DoubleLeftRotation(cur_node);
      }
    }
  }

  /* set height of current node */
  SetHeight(cur_node, 3);
  cur_node->size_ = GetSize(cur_node->left_) + GetSize(cur_node->right_) + 1;
  return cur_node;
}

template class AVLTree<int>;
template class Node<int>;