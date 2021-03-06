/*
Write your Rope implementation in this file. 
You do not have to keep any of the code that is already in this file.
Functions that are required that you have not implemented have an assert 0
meaning they will always crash. This should help you make sure you implement
everything.
*/

#include <cassert>
#include "Rope.h"

//Should advance to the next Node using in-order traversal
//It can point at any Node, not just leaves
rope_iterator &rope_iterator::operator++() {
  // if i have right subtree, find left most element of those
  if (ptr_->right != nullptr) {
    ptr_ = ptr_->right;
    while (ptr_->left != nullptr) {
      ptr_ = ptr_->left;
    }
  } else {
    // Find the parent that I am on its left
    while (ptr_->parent && ptr_->parent->right == ptr_)
      ptr_ = ptr_->parent;

    if (ptr_->parent == nullptr) {
      // reach the root and this should be the end
      ptr_ = nullptr;
      return *this;
    }

    ptr_ = ptr_->parent;
  }

  return *this;
}

//Point to the first Node for in-order traversal
rope_iterator Rope::begin() const {
  return rope_iterator(Node::go_left_leaf(root));
}

// Go to the last node on the left
Node *Node::go_left_leaf(Node *begin) {
  if (begin) {
    while (begin->left != nullptr) {
      begin = begin->left;
    }
  }

  return begin;
}

Rope::Rope() {
  size_ = 0;
  root = nullptr;
}

// Calculate the sum of leaf over each nodes
int Node::sum(Node *n) {
  if (n != nullptr) {
    return n->weight + sum(n->right);
  }

  return 0;
}

// Get char from given index
char Node::getChar(unsigned int i) const {
  if (value.size() > i) {
    return value[i];
  } else {
    std::cerr << "Error when fetching char" << std::endl;
    return '\0';
  }
}

//Should make the root = p and adjust any member variables
//This should not make a copy of the rope with root at p,
//it should just "steal" the Node*
Rope::Rope(Node *p) {
  root = p;
  root->parent = nullptr;
  size_ = Node::sum(p);
}

// Deep copy the node
Node *Rope::copy_node(Node *n) {
  if (n != nullptr) {
    // Copy the node
    Node *tmp = new Node();
    tmp->weight = n->weight;
    if (!n->value.empty()) {
      tmp->value = n->value;
    }

    // Assign members
    tmp->left = copy_node(n->left);
    tmp->right = copy_node(n->right);
    if (tmp->left) {
      tmp->left->parent = tmp;
    }
    if (tmp->right) {
      tmp->right->parent = tmp;
    }

    return tmp;
  }

  return nullptr;
}

Rope::~Rope() {
  clear();
}


void Rope::clear() {
  if (root != nullptr) {
    delete_node(root);
    root = nullptr;
    size_ = 0;
  }
}

void Rope::delete_node(Node *n) {
  if (n != nullptr) {
    delete_node(n->left);
    delete_node(n->right);
    delete n;
    size_--;
  }
}

Rope::Rope(const Rope &r) {
  clear();
  root = copy_node(r.root);
  size_ = r.size_;
}

Rope &Rope::operator=(const Rope &r) {
  if (this != &r) {
    clear();
    root = copy_node(r.root);
    size_ = Node::sum(root);
  }

  return *this;
}

//MUST BE ITERATIVE
//Get a single character at index i
bool Rope::index(int i, char &c) const {
  // Not a valid index
  if (i >= size() || i < 0) {
    return false;
  }

  Node *n = root;
  // Go deep into the leaf
  while (!is_leaf(n)) {
    if (i < n->weight) {
      // On the left
      n = n->left;
    } else {
      //i >= n->weight
      i = i - n->weight;
      n = n->right;
    }
  }

  c = n->getChar(i);

  return true;
}

//Add the other rope (r)'s string to the end of my string
void Rope::concat(const Rope &r) {
  Rope *rhs = new Rope(r);

  // Create a new Node as root
  Node *new_root = new Node();
  new_root->left = root;
  new_root->right = rhs->root;
  new_root->weight = Node::sum(root);

  // Adjust root
  root = new_root;
  if (root->left) {
    root->left->parent = root;
  }
  if (root->right) {
    root->right->parent = root;
  }
  size_ += rhs->size_;

  // Avoid de-constructor
  rhs->root = nullptr;
  delete rhs;
}


// Similar to concat, but not copying
void Rope::move(Node *n) {
  // The Rope ptr maybe nullptr
  if (n) {
    if (root) {
      Node *new_root = new Node();
      new_root->left = root;

      root->parent = new_root;
      new_root->right = n;
      n->parent = new_root;
      new_root->weight = size_;

      root = new_root;
    } else {
      // We just set this as our new root
      root = n;
    }

    size_ += Node::sum(n);
  } else {
    std::cerr << "Trying to move nullptr!" << std::endl;
  }
}

//Get a substring from index i to index j.
//Includes both the characters at index i and at index j.
//String can be one character if i and j match
//Returns true if a string was returned, and false otherwise
//Function should be written with efficient running time.
bool Rope::report(int i, int j, std::string &s) const {
  if (j >= size() || i > j || i < 0) {
    return false;
  }

  s = "";
  for (; i <= j; i++) {
    char c;
    index(i, c);
    s += c;
  }

  return true;
}

// Used to Split a Node at given index
void Node::split(int index) {
  if (index != 0 && index < value.size()) {
    // Create new Node
    Node *l = new Node();
    Node *r = new Node();

    l->value = value.substr(0, index);
    l->weight = l->value.size();
    r->value = value.substr(index, value.size());
    r->weight = r->value.size();

    // Connect Nodes
    left = l;
    right = r;
    l->parent = this;
    r->parent = this;

    // Adjust members
    weight = l->weight;
    value = "";
  } else {
    std::cerr << "Out of bound when splitting Node" << std::endl;
  }
}

//The first i characters should stay in the current rope, while a new
//Rope (rhs) should contain the remaining size_-i characters.
//A valid split should always result in two ropes of non-zero length.
//If the split would not be valid, this rope should not be changed,
//and the rhs rope should be an empty rope.
//The return value should be this rope (the "left") part of the string
//This function should move the nodes to the rhs instead of making new copies.
Rope &Rope::split(int i, Rope &rhs) {
  // Not a valid split
  if (i >= size() || i <= 0) {
    // Invalid index
    rhs = Rope();
    return *this;
  }

  // First, we need to find where the index is.
  Node *n = root;
  int left_size = i;

  while (!is_leaf(n)) {
    if (i < n->weight) {
      // On the left
      n = n->left;
    } else {
      //i >= n->weight
      i = i - n->weight;
      n = n->right;
    }
  }

  // If this is not the ending of a node, we need to split this node into two part
  if (i != 0) {
    n->split(i);
    n = n->right;
  }

  Node *parent_final = nullptr;

  rhs = Rope();
  if (n->parent) {
    // We should have a parent
    if (n->parent->left == n) {
      // We are on the left
      // Find the first parent on its right
      while (n->parent && n->parent->right != n) {
        n = n->parent;
      }

      // Cut the right
      parent_final = n->parent;
      rhs.move(n);
      parent_final->right = nullptr;
    } else {
      // We are on the right
      // We need to cut ourselves directly
      parent_final = n->parent;
      rhs.move(n);
      parent_final->right = nullptr;
    }
  } else {
    std::cerr << "Position should not be the root node" << std::endl;
    return *this;
  }

  // For the rest of the right, cut and move
  if (parent_final) {
    while (parent_final->parent) {
      Node *tmp = parent_final->parent;
      if (tmp && tmp->right != parent_final) {
        // Move to the parent first
        parent_final = tmp;
        if (parent_final->right) {
          rhs.move(parent_final->right);
        }
        parent_final->right = nullptr;
        // Re-calculate member
        parent_final->weight = Node::sum(parent_final->left);
      } else {
        parent_final = tmp;
      }
    }
  }

  // Adjust left tree's member
  size_ = left_size;
  root->weight = Node::sum(root->left);
  return *this;
}
