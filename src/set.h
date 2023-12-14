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

#ifndef SET_H
#define SET_H

// define set as user interface
template <typename ValType> class Set {
public:
  Set() {}
  // inset node with a given key
  void Insert(ValType);
  // erase node matches a given key
  int Erase(ValType);
  // get minimum key of subtree whose key matches a given key
  int GetMinKey(ValType);
  // get maximum key of subtree whose key matches a given key
  int GetMaxKey(ValType);
  // check if bst is empty
  bool IsEmpty();
  // get the number of nodes in bst
  int GetSize();
  // get depth of node matches a given key
  int GetDepth(ValType);
  // get rank of node matches a given key
  int GetRank(ValType);

private:
  AVLTree<ValType> bst_;
};
#endif