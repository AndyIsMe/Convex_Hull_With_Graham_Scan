# Convex_Hull_With_Graham_Scan
Convex Hull is the intersection of all convex sets containing X or as the set of all
convex combinations of points in X.
A set of points is stated to be convex if it contains the line segments connecting each pair of its points.
The convex hull of a given set X may be defined as :

    1.The (unique) minimal convex sets containing X
    2.The intersection of all convex sets containing X
    3.The set of all convex combinations of points in X
    4.The union of all simplices with vertices in X

The algorithm used for solving this Convex Hull is Graham Scan Algorithm

# Graham_Scan_Algorithm
Avl Tree will be used to sort out according to the lowest X coordinate and will be
used to compare with the next 2 lowest X coordinate since Convex Hull is only possible
if there are at least 3 coordinates to determine the convexity.

# Coding_Methodology
The orientation among 3 points will be found through this function :

    int orientation(Point *p,Point *q,Point *r);

Convex Hull of the top part among the points will be be printed out through :

    Point *TopHalf(Node **root,int n,int m);

In this function , a search function along with a compare function will be implemented to find the smallest X coordinate : \n

    Node *SearchMinX(Node **rootPtr);
      int CompareX(Point *p, Node *refNode);

Right after the it is found , the node will be remove so that the next smallest X coordinate can be found.

Convex Hull of the bottom part among the points will be found in the form of linked list through :

    LinkedList *BottomHalf(Point root[],int n);

# References
https://en.wikipedia.org/wiki/Convex_hull
