/*
File: avl_tree.cpp
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

#include "avl_tree.h"

/* AVL Tree basic constructor*/
AVLTree::AVLTree() {
  root_ = NULL;
  num_of_nodes_ = 0;
}

/* root - left - left */
/* when cur_node's left child has bigger height than right child's height and
 * newly insterted node has smaller key than left child's one */
Node *AVLTree::single_right_rotation(Node *cur_node) {
  Node *left_child = cur_node->left_;
  cur_node->left_ = left_child->right_;
  left_child->right_ = cur_node;
  set_height(cur_node, 3);
  set_height(left_child, 1);
  return left_child;
}

/* root - right - right */
/* when cur_node's right child has bigger height than left child's height and
 * newly insterted node has bigger key than right child's one */
Node *AVLTree::single_left_rotation(Node *cur_node) {
  Node *right_child = cur_node->right_;
  cur_node->right_ = right_child->left_;
  right_child->left_ = cur_node;
  set_height(cur_node, 3);
  set_height(right_child, 2);
  return right_child;
}

/* root - left - right */
/* when cur_node's left child has bigger height than right child's height and
 * newly inserted node has bigger key than left child's one */
Node *AVLTree::double_right_rotation(Node *cur_node) {
  cur_node->left_ = single_left_rotation(cur_node->left_);
  cur_node = single_right_rotation(cur_node);
  return cur_node;
}

/* root- right - left */
/* when cur_node's left child has bigger height than right child's height and
 * newly inserted node has bigger key than left child's one */
Node *AVLTree::double_left_rotation(Node *cur_node) {
  cur_node->right_ = single_right_rotation(cur_node->right_);
  cur_node = single_left_rotation(cur_node);
  return cur_node;
}

/* difference between heights have to be less than 2 to be balanced. */
bool AVLTree::is_balanced(Node *child_1, Node *child_2) {
  return (get_height(child_1) - get_height(child_2) < 2);
}

/*
set_hegiht based on calling node's childs
children argument
  3: compare two children
  2: compare right child to calling node's height
  1: compare left child to calling node's height
*/
void AVLTree::set_height(Node *cur_node, int chidren) {
  switch (chidren) {
  case 3:
    if (get_height(cur_node->left_) > get_height(cur_node->right_))
      cur_node->set_height(get_height(cur_node->left_) + 1);
    else
      cur_node->set_height(get_height(cur_node->right_) + 1);
    break;
  case 2:
    if (get_height(cur_node->right_) > get_height(cur_node))
      cur_node->set_height(get_height(cur_node->right_) + 1);
    else
      cur_node->set_height(get_height(cur_node) + 1);
  case 1:
    if (get_height(cur_node->left_) > get_height(cur_node))
      cur_node->set_height(get_height(cur_node->left_) + 1);
    else
      cur_node->set_height(get_height(cur_node) + 1);
  }
}

/* returns -1 if cur_node is NULL, else height member */
int AVLTree::get_height(Node *cur_node) {
  if (cur_node == NULL)
    return -1;
  else
    return cur_node->get_height();
}

Node *AVLTree::find_node(Node *cur_node, int key) {
  if (cur_node == NULL)
    return NULL;
  else if (cur_node->key_ == key)
    return cur_node;
  else if (cur_node->key_ > key)
    return find_node(cur_node->left_, key);
  else if (cur_node->key_ < key)
    return find_node(cur_node->right_, key);
}
