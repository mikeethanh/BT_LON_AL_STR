#include<iostream>
using namespace std;

template<class T>
//xay dung class Node : 
class Node {
private:
    T data;
    Node* prev;
    Node* next;
public:
    //Constructor :
    Node() : prev(nullptr) ,next(nullptr) {};

    Node(T data) : data(data), prev(nullptr), next(nullptr) {}

    //getter va setter : lay ra cac thuoc tinh va dinh dang cac thuoc tinh
    T getData() {
        return data;
    }

    Node* getPrev() {
        return prev;
    }

    Node* getNext() {
        return next;
    }

    void setData(T data) {
        this->data = data;
    }

    void setNext(Node* next) {
        this->next = next;
    }

    void setPrev(Node* prev) {
        this->prev = prev;
    }
};

//xay dung doubly Linked list:
template<class T>
class DbLinkedList {
private:
    //lay ra Node dau va Node cuoi
    Node<T>* head;
    Node<T>* tail;
    //size:
    int n;

public:
//ham khoi tao 1 list;
    DbLinkedList() {
        head = nullptr;
        tail = nullptr;
        n = 0;
    }
    //getter va setter: lay ra va dinh dang node dau vao node cuoi 
    Node<T>* getHead() {
        return head;
    }
    Node<T>* getTail() {
        return tail;
    }

    void setTail(Node<T>* tail) {
        this->tail = tail;
    }

    void setHead(Node<T>* head) {
        this->head = head;
    }

    //them Node vao cuoi danh sach 
    void insertInLast(T data) {
        //tao ra Node moi
        Node<T>* newNode = new Node<T>(data);

        //xu li truong hop neu Node o dau danh sach
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
           newNode->setPrev(tail);
            tail->setNext(newNode);
            tail = newNode;
        }
        //tang size;
        n++;
    }
    //them Node vao dau danh sach:
    void insertInFirst(T data) {
         Node<T>* newNode = new Node<T>(data);

        if (head != nullptr) {
            newNode->setNext(head);
            head->setPrev(newNode);
        }
        head = newNode;

        //neu danh sanh dang rong
        if (tail == nullptr) {
            tail = newNode;
        }

        n++;
    }

    //xoa Node o dau danh sach
    void eraseFirstNode() {
        if (head != nullptr) {
            Node<T>* eraseThisNode = head;
            head = head->getNext();
            if (head != nullptr) {
                head->setPrev(nullptr);
            }
            //xu ly truong hop danh sach rong 
             else {
                tail = nullptr;
            }
            delete eraseThisNode;
            n--;
         }
    }
    //Xoa Node o cuoi danh sach:
    void eraseLastNode() {
        if (head != nullptr) {
            Node<T>* temp = tail;
            tail = tail->getPrev();
            if (tail != nullptr) {
                tail->setNext(nullptr);
            } else {
                head = nullptr;
            }
            delete temp;
            n--;
        }
    }
    //XAY DUNG LOP ITERATOR :
    class Iterator {
    public:
    //XET Node hien tai:
        Node<T>* current;

        //ham tao chuyen vao Node hien tai
        Iterator(Node<T>* node) : current(node) {}

        //Tra ve giu lieu duoc luu o Node
        //nap chong toan tu * 
        T operator*() {
            return current->getData();
        }

        //Toán tử ++ và ++ postfix trong lớp Iterator được nạp chồng để cung cấp sự linh hoạt trong việc sử dụng iterator và cho phép người lập trình sử dụng cả hai cách tùy thuộc vào nhu cầu cụ thể.

        //tien to : di chuyen den phan tu tien theo va tra ve phan tu do (++it)
        Iterator& operator++() {
            current = current->getNext();
            return *this;
        }
        //hau to di chuyen den phan tu tiep theo va tra ve phan tu truoc do , 
        Iterator operator++(T) {
            Iterator temp = *this;
            current = current->getNext();
            return temp;
        }

        //di chuyen den Node truoc day va tra ve Node truoc day (toan tu tien to)
        Iterator& operator--() {
            current = current->getPrev();
            return *this;
        }
        //hau to di chuyen den node truoc day va tra ve node dang xet
        Iterator operator--(T) {
            Iterator temp = *this;
            current = current->getPrev();
            return temp;
        }

        //dung const vi chuyen tham chieu tranh bi thay doi du lieu khi chuyen
        //nap chong toan tu bang bang de so sanh toan tu dang xet voi toan tu khac:
        bool operator==(const Iterator& other) const {
            return current == other.current;
        }

        //nap chong toan tu != de so sanh toan tu dang xet voi toan tu khac
        bool operator!=(const Iterator& other) const {
            return current != other.current;
        }
    };
    
    //cac phuong thuc nay cua lop DblinkedList ; 
    //khong lien quan gi den lop Iterator;

    //tra ve Node dau tien :
    Iterator begin() {
        return Iterator(getHead());
    }

    //tra ve Node cuoi cung 
    Iterator end() {
        return Iterator(nullptr);
    }

    Iterator rbegin() {
        return Iterator(getTail());
    }

    Iterator rend() {
        return Iterator(nullptr);
    }
};

int main() {
    //tap ra mot doi tuong moi trong lop doubly Links list
    DbLinkedList<int> db;

    db.insertInFirst(3);
    db.insertInLast(5);
    db.insertInLast(8);
    db.insertInFirst(2);
    db.insertInLast(7);
    db.insertInLast(9);

    db.eraseFirstNode();
    db.eraseLastNode();

    //duyet xuoi 
    for (auto it = db.begin(); it != db.end();++it) {
        cout << *it<< " ";
    }
    cout << endl;

    //duyet nguoc :
    for (auto it = db.rbegin(); it != db.rend(); --it) {
        cout << *it << " ";
    }
    cout << endl;
    return 0;
}
