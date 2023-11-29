#include <iostream>
using namespace std;

// Lớp cây nhị phân:
template<class T>
class BinaryTree {
private:
    // Khai báo một Node:
    struct Node {
        T data;
        Node* left;
        Node* right;

        // Hàm tạo (constructor) để khởi tạo một Node với giá trị `data` và hai con trỏ trỏ đến null.
        Node(T data) : data(data), left(nullptr), right(nullptr) {}
    };

public:
    // Lớp con getter và setter để truy cập và thiết lập các thuộc tính trong Node:
    //phai co ham getter neu muon lay bat cu thuoc tinh nao trong private va dde dam bao tinh dong goi (esclasplism) 

    // Trả về giá trị được lưu trong Node:
    T getData() {
        return data;
    }

    // Trả về địa chỉ con trỏ trỏ đến Node con bên trái:
    Node* getLeft() {
        return left;
    }

    // Trả về địa chỉ con trỏ trỏ đến Node con bên phải:
    Node* getRight() {
        return right;
    }

    // Quy định giá trị của `data`:
    void setData(T data) {
        this->data = data;
    }

    // Quy định địa chỉ Node con bên trái:
    void setLeft(Node* addressVal) {
        this->left = addressVal;
    }

    // Quy định địa chỉ Node con bên phải:
    void setRight(Node* addressVal) {
        this->right = addressVal;
    }

    //tu them han hasleft . hasright vao.
};

int main() {
    BinaryTree<int> tree;
    //co the thay keu int bang cac kieu khac tai v co template <class T> 
}