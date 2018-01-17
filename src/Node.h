#ifndef _NODE_H
#define _NODE_H
#include <stdint.h>

typedef struct Node Node;
typedef struct PointNode PointNode;
typedef struct Point Point;
struct PointNode
{
  Node *left;
  Node *right;
  int balanceFactor;
  void *data;
  int type;
};


struct Point
{
  int x,y;
  char *place;
  //double data;
};

struct Node {
  Node *left;
  Node *right;
  int balanceFactor;
  Point *data;
};


typedef struct StringNode StringNode;
struct StringNode {
  StringNode *left;
  StringNode *right;
  int balanceFactor;
  char *str;
};

#endif // _NODE_H
