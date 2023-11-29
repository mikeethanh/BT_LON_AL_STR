#ifndef BTREENODE_CPP 
#define BTREENODE_CPP 1
#include"iostream"
using namespace std;
template <class T>
class BTreeNode{
    private:
       T elem;
	   BTreeNode *parent,*left,*right ;
	public:
	   BTreeNode( )
	   {
		  parent = NULL ;
		  left = NULL ;
		  right = NULL ;
		}
	   BTreeNode(T e)
	   {
		  parent = NULL ;
		  left = NULL ;
		  right = NULL ;
		  elem = e;
		}
		BTreeNode *getParent(){	return parent;}
		BTreeNode *getLeft(){return left;}
		BTreeNode *getRight(){ return right;}
		void setParent(BTreeNode *p){ parent = p;}
		void setLeft(BTreeNode *p){ left = p;}
		void setRight(BTreeNode *p){ right = p; }
		void setElem(T element){ elem = element; }
		T getElem(){ return elem;}
		int hasLeft(){ return left != NULL;   }
        int hasRight(){ return right != NULL; } 
 };
#endif
