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

#include "node.h"
#include <iostream>
#ifndef AVLTREE_H
#define AVLTREE_H

template<typename ValType>
class Set;


// Define AVLTree
template <typename ValType> class AVLTree {
  friend class Set<ValType>;
private:
  AVLTree();
  // AVLTree constructor
  // insert a node
  Node<ValType> *InsertNode(Node<ValType> *, ValType);
  // delete a node
  Node<ValType> *EraseNode(Node<ValType> *, ValType);
  // Single righr rotation
  Node<ValType> *SingleRightRotation(Node<ValType> *);
  // single left rotation
  Node<ValType> *SingleLeftRotation(Node<ValType> *);
  // double right rotation
  Node<ValType> *DoubleRightRotation(Node<ValType> *);
  // double left rotation
  Node<ValType> *DoubleLeftRotation(Node<ValType> *);
  // get Balance of a given node for erase
  int GetBalance(Node<ValType> *);
  // get Rank of a given node
  int FindRank(Node<ValType> *, ValType);
  // Find node matcheds a key
  Node<ValType> *FindNode(Node<ValType> *, ValType);
  // find a node which has a smallest key in subtree whose root is a give node.
  Node<ValType> *FindMinNodeOfSubtree(Node<ValType> *);
  // find a node which has a biggest key in subtree whose root is a give node.
  Node<ValType> *FindMaxNodeOfSubtree(Node<ValType> *);
  // get Depth of a given node
  int FindDepth(Node<ValType> *, ValType, int);
  // check if AVL tree is balanced
  bool IsBalanced(Node<ValType> *, Node<ValType> *);
  // set height of a given node
  void SetHeight(Node<ValType> *, int);
  // get height of a given node
  int GetHeight(Node<ValType> *);
  // get Size of subtree
  int GetSize(Node<ValType> *);

  private:
  // members
  Node<ValType> *root_;
  size_t num_of_nodes_;
};
#endif
