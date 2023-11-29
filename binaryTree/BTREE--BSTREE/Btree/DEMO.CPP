#include "conio.h"
#include"stdio.h"
#include"iostream"
#include "Btree.cpp"
using namespace std;
void pri(BTreeNode<int> *p){
     cout<<p->getElem()<<" ";
}
float t;
void tinhtong(BTreeNode<int> *p){
	t = t + p->getElem();
}	
int main(){	 
	  BTree<int> tree;
      BTreeNode<int> *p;
	  //Tao cay
	  tree.insert(NULL, 100);
	  p = tree.insert(tree.getRoot(), 10);
	  tree.insert(p, 8);
	  tree.insert(p, 6);
      p = tree.insert(tree.getRoot(), 20);
      tree.insert(p,5);
      tree.insert(p, 30);
	  //Duyet cay
	  cout<<"\n Duyet theo thu tu truoc:";
	  tree.preOrder(tree.getRoot(),pri);
	  cout<<"\n Duyet theo thu tu giua:";
	  tree.inOrder(tree.getRoot(), pri);
	  cout<<"\n Duyet theo thu tu sau:";
	  tree.postOrder(tree.getRoot(),pri);
	  //Tinh tong tat ca cac nut tren cay
	  t=0;
	  tree.postOrder(tree.getRoot(),tinhtong);
	  cout<<"\n Tong cua cac nut tren cay = "<<t;
     getch(); 
     return 0;
}
 