#include "conio.h"
#include "Btree.cpp"
#include "iostream"
using namespace std;
void v(BNode<int,char*>*p)
{
	  cout<<"("<<p->getKey()<<","<< p->getElem()<<")";	
}

int main(){
	BTree<int,char*> tree;
	BNode<int,char*> *p;
	//BNode<int,float> *p;
	system("cls");
	tree.insert(100,"100-1");
	tree.insert(80,"80a");
	tree.insert(25,"25x");
	tree.insert(105,"105");
	tree.insert(13,"13");
	tree.insert(120,"120");
	tree.insert(175,"175");
	tree.insert(30,"30x");
	tree.insert(46,"46");
	//tree.preOrder(tree.getRoot(),visit);
	cout<<"\nDuyet cay theo thu tu giua:";	
	tree.inOrder(tree.getRoot(),v);
	
	tree.remove(25);
	cout<<"\n";
	cout<<"\nDuyet cay theo thu tu giua:";	
	tree.inOrder(tree.getRoot(),v);
	   //	cout<<"\n";
   // tree.postOrder(tree.getRoot(),v);
   //tree.remove(150);
    cout<<"\n";
	//tree.inOrder(tree.getRoot(),visit);
	/*p = tree.search(120, tree.getRoot());
	if(p!=NULL)
	  cout<<"Tim thay khoa 120, Co gia tri "<<p->getElem();
	else
	  cout<<"Khong tim thay khoa 120.";
	  
    tree.remove(120);
    //tree.remove(100);
    tree.remove(70);    
    cout<<"\nDuyet cay theo thu tu giua:";
   	tree.inOrder(tree.getRoot(),visit);*/
	getch();
	return 0;
}

