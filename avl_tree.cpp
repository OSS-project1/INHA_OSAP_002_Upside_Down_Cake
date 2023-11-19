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

#include "avl_tree.h"

/* AVL Tree basic constructor*/
AVLTree::AVLTree() {
  root_ = NULL;
  num_of_nodes_ = 0;
}

/* single left rotation when cur_node has left child and left granchild */
Node *AVLTree::single_left_rotation(Node *cur_node) {
  Node *left_child = cur_node->left_;
  cur_node->left_ = left_child->right_;
  left_child->right_ = cur_node;
  set_height(cur_node, 3);
  set_height(left_child, 1);
  return left_child;
}

/*
set_hegiht based on calling node's childs
children argument
  3: when calling node has two childs
  2: when calling node has only left child
  1: when calling node has only right child
*/
void AVLTree::set_height(Node *cur_node, int chidren) {
  switch (chidren) {
  case 3:
    if (cur_node->left_->get_height() > cur_node->right_->get_height())
      cur_node->set_height(cur_node->left_->get_height() + 1);
    else
      cur_node->set_height(cur_node->right_->get_height() + 1);
    break;
  case 2:
    if (cur_node->right_->get_height() > cur_node->get_height())
      cur_node->set_height(cur_node->right_->get_height() + 1);
    else
      cur_node->set_height(cur_node->get_height() + 1);
  case 1:
    if (cur_node->left_->get_height() > cur_node->get_height())
      cur_node->set_height(cur_node->left_->get_height() + 1);
    else
      cur_node->set_height(cur_node->get_height() + 1);
  }
}

