/*
File: set.h
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

#ifndef SET_H
#define SET_H

// Define Set
class Set {
public:
  // Set constructor
  Set();
  // insert a node has a given key
  int insert(int key);
  // erase a node has a given key
  int erase(int key);
  // find depth of a node has a given key
  int find(int key);
  // get a rank of a node has a given key
  int get_rank(int key);
  // get a node which has a minimum key of subtree where its root has a given
  // key
  int get_min_key(int key);
  // get a node which has a maximum key of subtree wh`ere its root has a given
  // key
  int get_max_key(int key);
  // get a size of a whole avl tree
  int get_size();
  // return whether avl tree is emptry or not
  bool is_empty();
};
#endif
