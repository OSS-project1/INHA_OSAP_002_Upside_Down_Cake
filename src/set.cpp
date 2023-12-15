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

#include "set.h"

// get minimum key of subtree whose key matches a given key
template <typename ValType> int Set<ValType>::GetMinKey(ValType key) {
  Node<ValType> *sub_root = bst_.FindNode(bst_.root_, key);
  if (sub_root == NULL) {
    return 0;
  } else {
    return bst_.FindMinNodeOfSubtree(sub_root)->key_;
  }
}
// get maximum key of subtree whose key matches a given key
template <typename ValType> int Set<ValType>::GetMaxKey(ValType key) {
  Node<ValType> *sub_root = bst_.FindNode(bst_.root_, key);
  if (sub_root == NULL) {
    return 0;
  } else {
    return bst_.FindMaxNodeOfSubtree(sub_root)->key_;
  }
}
// check if bst is empty
template <typename ValType> bool Set<ValType>::IsEmpty() {
  return (bst_.num_of_nodes_ == 0);
}
// get the number of nodes in bst`
template <typename ValType> int Set<ValType>::GetSize() {
  return bst_.num_of_nodes_;
}
// get depth of node matches a given key
template <typename ValType> int Set<ValType>::GetDepth(ValType key) {
  Node<ValType> *cur_node = bst_.FindNode(bst_.root_, key);
  if (cur_node == NULL) {
    return 0;
  } else {
    return bst_.FindDepth(bst_.root_, key, 0);
  }
}
// inset node with a given key
template <typename ValType> void Set<ValType>::Insert(ValType key) {
  bst_.num_of_nodes_++;
  bst_.root_ = bst_.InsertNode(bst_.root_, key);
}

// erase node matches a given key
template <typename ValType> int Set<ValType>::Erase(ValType key) {
  if (bst_.FindNode(bst_.root_, key) == NULL) {
    return 0;
  } else {
    int depth = bst_.FindDepth(bst_.root_, key, 0);
    bst_.num_of_nodes_--;
    bst_.root_ = bst_.EraseNode(bst_.root_, key);
    return depth;
  }
}
// get rank of node matches a given key
template <typename ValType> int Set<ValType>::GetRank(ValType key) {
  if (bst_.FindNode(bst_.root_, key) == NULL) {
    return 0;
  } else {
    return bst_.FindRank(bst_.root_, key);
  }
}

template class AVLTree<int>;
template class Node<int>;
template class Set<int>;