#include "Rotate.h"
#include "stdio.h"


Node *rotateRight(Node *node){
Node *root;
root = node->left;
node->left = node->left->right;
root->right = node;
return root;
}


Node *rotateLeft(Node *node){
  Node *root;
  root = node->right;
  node->right = node->right->left;
  root->left = node;
  return root;
}

Node *rotateLeftRight(Node *node){
  Node *root;
  node->left =rotateLeft(node->left);
  root = rotateRight(node);
  return root;
}

Node *rotateRightLeft(Node *node){
  Node *root;
  node->right = rotateRight(node->right);
  root = rotateLeft(node);
  return root;
}

int avlBalanceRightTree(Node **rootPtr){
  int bf;
  Node *node = *rootPtr;
  Node *child = node->right;
  if((bf = child->balanceFactor)==0){
    node->balanceFactor = 1;
    child->balanceFactor -= 1;
                                    }
  else if((bf = child->balanceFactor)==1){
    node->balanceFactor = 0;
    child->balanceFactor = 0;
                                          }
    *rootPtr = rotateLeft(*rootPtr);
    return 0;
}

int avlBalanceLeftTree(Node **rootPtr){
  int bf;
  Node *node = *rootPtr;
  Node *child = node->left;
  if((bf = child->balanceFactor)==0){
    node->balanceFactor = -1;
    child->balanceFactor = 1;
                                    }
  else if((bf = child->balanceFactor)==-1){
    node->balanceFactor = 0;
    child->balanceFactor = 0;
                                          }
    *rootPtr = rotateRight(*rootPtr);
    return 0;
}

int avlBalanceRightTreeV1(Node **rootPtr){
  int bf;
  Node *node = *rootPtr;
  Node *child = node->right;
  Node *grandchild = node->right->left;
  if((bf = child->balanceFactor)==-1){
    if((bf = grandchild->balanceFactor)==-1){
      node->balanceFactor = 0;
      child->balanceFactor = 1;
      grandchild->balanceFactor = 0;
                                            }
    else if((bf = grandchild->balanceFactor)==0){
      node->balanceFactor = 0;
      child->balanceFactor = 0;
      grandchild->balanceFactor = 0;
                                                }
    else if((bf = grandchild->balanceFactor)==1){
      node->balanceFactor = -1;
      child->balanceFactor = 0;
      grandchild->balanceFactor = 0;
                                                }
      *rootPtr = rotateRightLeft(*rootPtr);
       return 0;
                                    }

  else if((bf = child->balanceFactor)==0){
    node->balanceFactor = 1;
    child->balanceFactor -= 1;
                                          }
  else if((bf = child->balanceFactor)==1){
    node->balanceFactor = 0;
    child->balanceFactor = 0;
                                          }
    *rootPtr = rotateLeft(*rootPtr);
     return 0;
}

int avlBalanceLeftTreeV1(Node **rootPtr){
  int bf;
  Node *node = *rootPtr;
  Node *child = node->left;
  Node *grandchild = node->left->right;
  if((bf = child->balanceFactor)==1){
    if((bf = grandchild->balanceFactor)==1){
      node->balanceFactor = 0;
      child->balanceFactor = -1;
      grandchild->balanceFactor = 0;
                                            }
    else if((bf = grandchild->balanceFactor)==0){
      node->balanceFactor = 0;
      child->balanceFactor = 0;
      grandchild->balanceFactor = 0;
                                                }
    else if((bf = grandchild->balanceFactor)==-1){
      node->balanceFactor = 1;
      child->balanceFactor = 0;
      grandchild->balanceFactor = 0;
                                                  }
     *rootPtr = rotateLeftRight(*rootPtr);
      return 0;
                                     }
  else if((bf = child->balanceFactor)==0){
    node->balanceFactor = -1;
    child->balanceFactor = 1;
                                          }
  else if((bf = child->balanceFactor)==-1){
    node->balanceFactor = 0;
    child->balanceFactor = 0;
  }
    *rootPtr = rotateRight(*rootPtr);
     return 0;
}
