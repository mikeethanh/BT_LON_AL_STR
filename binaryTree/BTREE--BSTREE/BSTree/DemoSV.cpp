#include "conio.h"
#include "Btree.cpp"
#include "iostream"
using namespace std;
class Student
{
	private:
		int masv;
		char hodem[30];
		char ten[10];
		char gioi[4];
	public:
	    int getMaSV(){ return masv;}
	    char* getHodem(){ return hodem;}   
	    char* getTen(){ return ten;}   
	    char* getGioi(){ return gioi;}   
		friend istream & operator >>(istream &is, Student &s);
		friend ostream & operator <<(ostream &os, Student s);
};
istream & operator >>(istream &is, Student &s)
{
	 cout<<"\nNhap ma sv:";
	 is>>s.masv;
	 cout<<"Nhap ho dem:";
	 is.ignore(1);
	 is.get(s.hodem,30);
	 cout<<"Nhap ten:";
	 is.ignore(1);
	 is.get(s.ten,10);
	 cout<<"Nhap gioi tinh:";
	 is.ignore(1);
	 is.get(s.gioi,4);
	 return is;
}
ostream & operator <<(ostream &os, Student s)
{
	os<<s.masv<<"\t"<<s.hodem<< " " <<s.ten<<"\t" <<s.gioi;
	return os;
}

void v(BNode<int,Student>*p)
{
	  cout<<"\n"<<p->getKey()<<","<< p->getElem();	
}

int main(){
	BTree<int,Student> tree;
	Student s;
	for(int i=0;i<3;i++)
	{
		cout<<"Nhap sinh vien thu:"<<i<<"\n";
		cin>>s;
		tree.insert(s.getMaSV(), s);
	}
	tree.preOrder(tree.getRoot(),v);
}
	
	
