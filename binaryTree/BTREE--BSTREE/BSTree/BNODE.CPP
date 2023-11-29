#ifndef NODE_H
#define NODE_H 1
#include"stdio.h"
template <class Keys, class T>
class BNode{
	private:
        Keys key;     
		T elem;
		BNode<Keys,T> *parent;
		BNode<Keys,T> *left;
		BNode<Keys,T> *right;       
	public:
      BNode(){ 
          parent = NULL;
          left = NULL;
          right = NULL;     
      }    
		BNode<Keys,T> *getParent() { return parent;}
		BNode<Keys,T> *getLeft() { return left;}
		BNode<Keys,T> *getRight() { return right;}
		void setLeft(BNode<Keys,T>* p){ left = p;}
		void setRight(BNode<Keys,T>* p) {right = p;}
		void setParent(BNode<Keys,T>* p) {parent= p;}
		int hasLeft()   { return left!=NULL; }
		int hasRight()  { return right!=NULL;}
		T getElem(){ return elem;}
		void setElem(T e)	{ elem =e;}
		Keys getKey(){ return key;}
		void setKey(Keys k){ key = k; }
};
#endif
