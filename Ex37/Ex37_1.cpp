#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include<sstream>
#include<algorithm>

using namespace std;

//xay dung lop Ho so sinh vien
class Student {
private:
    string ten;
    string lop;
    string sdt;
    float dtb;
public:
    //Constructor:
    Student() {};

    Student(string ten, string lop, string sdt, float dtb)
        : ten(ten), lop(lop), sdt(sdt), dtb(dtb) {}

    // Getter:lay ra cac thuoc tinh cua class Student
    string getTen() const {
        return ten;
    }

    string getLop() const {
        return lop;
    }

    string getSdt() const {
        return sdt;
    }

    float getDtb() const {
        return dtb;
    }

    // Setter:kiem tra xem nguoi dung co nhap dung dinh dang hay khong
    
    //kiem tra xem co de trong ten hay khong
    void setTen(const string& ten) {
        if (!ten.empty()) {
            this->ten = ten;
        }
        else {
            cout << "Ten khong duoc de trong." << endl;
        }
    }

    //kiem tra xem lop co de trong hay khong
    void setLop(const string& lop) {
        if (!lop.empty()) {
            this->lop = lop;
        }
        else {
            cout << "Lop khong duoc de trong" << endl;
        }
    }

    void setSdt(const string& sdt) {
        this->sdt = sdt;
    }

    //kem tra xem diem co nhap tu 1 - 10 hay khong 
    void setDtb(float dtb) {
        if (dtb < 0 || dtb > 10) {
            cout << "Diem trung binh khong hop le" << endl;
        }
        else {
            this->dtb = dtb;
        }
    }
};

//Xay ung 1 class quan ly danh sach sinh vien bang Node
//dung const de tranh bi thay doi du lieu khi chuyen tham chieu 

class studentList {
private:
    struct Node {
        Student data;
        Node* next;
        //Constructor:
        Node(const Student& data) : data(data), next(nullptr) {}
    };
    //Noed dau tien:
    Node* head = nullptr;

public:
    //Nhap danh sach ti File
    void FileToList(const string& filename) {
        ifstream readFile(filename);
        if (!readFile) {
            cout << "Khong mo duoc file!" << endl;
            return;
        }

        string name;
        string lop;
        string sdt;
        float dtb;

        while (getline(readFile, name)) {
            getline(readFile, lop);
            getline(readFile, sdt);
            readFile >> dtb;
            readFile.ignore(); // Loai bo ky tu newline '\n'
            readFile.ignore(); // Loai bo 1 dong trong

            //khoi tao 1 doi tuong 
            Student student(name, lop, sdt, dtb);

            Node* newNode = new Node(student);
            //them doi tuong vao cuoi danh sach

            //neu danh sach hoc sinh dang trong:
            if (head == nullptr) {
                head = newNode;
            }
            //neu khong trong:
            else {
                Node* temp = head;
                while (temp->next != nullptr) {
                    temp = temp->next;
                }
                temp->next = newNode;
            }
        }

        //check:
        Node* temp1 = head;
         while (temp1 != nullptr) {
             cout << "Ten: " << temp1->data.getTen() << endl;
             cout << "Lop: " << temp1->data.getLop() << endl;
             cout << "So dien thoai: " << temp1->data.getSdt() << endl;
             cout << "Diem trung binh: " << temp1->data.getDtb() << endl;
             cout << endl;

             temp1 = temp1->next;
         }
    }

    //Nhap danh sach tu ban phim:
    void inputStudentList() {
        int n;
        cout << "Nhap vao tong so sinh vien: ";
        cin >> n;
        cin.ignore(); // Loai bo ky tu newline

        for (int i = 0; i < n; i++) {
            cout << "STT: " << i + 1 << endl;

            string ten;
            string lop;
            string sdt;
            float dtb;

            cout << "- Nhap ten: ";
            getline(cin, ten);
            cout << "- Nhap lop: ";
            getline(cin, lop);
            cout << "- Nhap so dien thoai: ";
            getline(cin, sdt);
            cout << "- Nhap diem trung binh: ";
            cin >> dtb;
            cin.ignore(); // Loai bo ky tu newline

            // Tạo một đối tượng sinh viên và sử dụng setter để đặt giá trị cho từng thuộc tính
            Student student;
            student.setTen(ten);
            student.setLop(lop);
            student.setSdt(sdt);
            student.setDtb(dtb);

            //them do tuong vao cuoi danh sach
            Node* newNode = new Node(student);
            if (head == nullptr) {
                head = newNode;
            }
            else {
                Node* temp = head;
                while (temp->next != nullptr) {
                    temp = temp->next;
                }
                temp->next = newNode;
            }
        }
    }

    //in ra ten va xep hang theo diem trung binh:
    void printNameandRank() {
        cout << "DANH SACH SINH VIEN BAO GOM TEN VA XEP LOAI:\n";
        Node* temp = head;
        int i = 1; //STT
        while (temp != nullptr) {
            cout << "STT:" << i << endl;
            cout << "Ten:" << temp->data.getTen() << endl;
            cout << "XepLoai";
            if (temp->data.getDtb() > 0 && temp->data.getDtb() <= 5) {
                cout << "TRUNG BINH" << endl;
            }
            else if (temp->data.getDtb() >5 && temp->data.getDtb() <= 8) {
                cout << "KHA" << endl;
            }
            else {
                cout << "GIOI" << endl;
            }
            i++;
            temp = temp->next;
        }
    }

    //in ra danh sach hoc sinh gom cac thong tin day du: 
    void printAll() {
        Node* temp = head;
        int i = 1;
        while (temp != nullptr) {
            cout << "STT" << i << endl;
            cout << " +Ten: " << temp->data.getTen() << endl;
            cout << " +Lop: " << temp->data.getLop() << endl;
            cout << " +So dien thoai: " << temp->data.getSdt() << endl;
            cout << " +Dtb: " << temp->data.getDtb() << endl;
            temp = temp->next;
            i++;
        }
    }

    //nhap tu ban phim ten hoc sinh va ten lop , tim xem hox sinh co trong lop do khong
    void findStudent(const string& student,const string& classroom) {
        //chuyen ten hoc sinh vua nhap vao thanh viet hoa chu ca dau :
        stringstream ss(student);
        string tmp;
        string resName = "";
        while (ss >> tmp) {
            //ham viet hoa cac chu cai dau
            tmp[0] = toupper(tmp[0]);
            resName = resName + tmp + " ";
        }

       
        //chuyen lop vua nhap vao thanh viet hoa het
        string resClass = "";
        for (char c : classroom) {
            c = toupper(c);
            resClass += c;
        }
           
        //duyet tu dau node den cuoi node
        Node* temp = head;
        while(temp != nullptr) { 
            if (temp->data.getTen() == resName && temp->data.getLop() == resClass) {
                cout << "So ddien thoai sinh vien vua tim duoc la :";
                cout << temp->data.getSdt() << endl;
                return;
            }
            temp = temp->next;
        }
        if (temp == nullptr) {
            cout << "Khong tm thay sinh vien!" << endl;
        }
    }

    //nhap ho so hoc sinh moi tu ban phim , bo sung hoc sinh do vao danh sanh
    void addStudent() {
        string name;
        string classroom;
        string phoneNumber;
        float dtb;

        cout << "Them sinh ven moi:" << endl;
        cout << "Nhap ten sinh vien: ";
        getline(cin, name);
        cout << "Nhap lop: ";
        getline(cin, classroom);
        cout << "Nhap so dien thoai:";
        getline(cin, phoneNumber);
        cout << "Nhap dien trung binh:";
        cin >> dtb;

        Student student(name, classroom, phoneNumber, dtb);
        
        student.setTen(name);
        student.setLop(classroom);
        student.setSdt(phoneNumber);
        student.setDtb(dtb);
        
        //bo sung vao cuoi danh sach
        Node* newNode = new Node(student);
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
        cout << "Them sinh ven thanh cong ";

        //check xem them vao thanh cong hay chua
        Node* temp1 = head;
        while (temp1 != nullptr) {
            cout << "Ten: " << temp1->data.getTen() << endl;
            cout << "Lop: " << temp1->data.getLop() << endl;
            cout << "So dien thoai: " << temp1->data.getSdt() << endl;
            cout << "Diem trung binh: " << temp1->data.getDtb() << endl;
            cout << endl;

            temp1 = temp1->next;
        }
    }

    //Nhap vao tu ban phim ten 1 lop , loai bo tat ca hoc snh cua lop do ra khoi danh sach:
    void delStudent(const string& classroom) {
        //chuyen classroom ve dung dinh dang:
        string resClass = "";
        for (char c : classroom) {
            c = toupper(c);
            resClass += c;
        }

        Node* current = head;
        Node* prev = nullptr;

        while (current != nullptr) {
            if (current->data.getLop() == resClass) {
                if (prev == nullptr) {
                    head = current->next;
                    delete current;
                    current = head;
                }
                else {
                    prev->next = current->next;
                    delete current;
                    current = prev->next;
                }
            }
            else {
                prev = current;
                current = current->next;
            }
        }
        cout << "Da xoa thanh cong" << endl;

        //check xem xoa thanh cong hay chua:
        Node* temp1 = head;
        while (temp1 != nullptr) {
            cout << "Ten: " << temp1->data.getTen() << endl;
            cout << "Lop: " << temp1->data.getLop() << endl;
            cout << "So dien thoai: " << temp1->data.getSdt() << endl;
            cout << "Diem trung binh: " << temp1->data.getDtb() << endl;
            cout << endl;

            temp1 = temp1->next;
        }
    }

    //sap xep theo thu tu giam dan cua diem trung binh:
    void sortDecending() {
        //su dung bubble sort doi cho thanh phan data tong cac Node
        for(Node* temp1 = head; temp1 != nullptr; temp1 = temp1->next) {
            for (Node* temp2 = temp1->next; temp2 != nullptr; temp2 = temp2->next) {
                if (temp1->data.getDtb() < temp2->data.getDtb()) {
                    swap(temp1->data, temp2->data);
                }
            }
       }
        //check xem da sap sep chua : 
        Node* temp1 = head;
        while (temp1 != nullptr) {
            cout << "Ten: " << temp1->data.getTen() << endl;
            cout << "Lop: " << temp1->data.getLop() << endl;
            cout << "So dien thoai: " << temp1->data.getSdt() << endl;
            cout << "Diem trung binh: " << temp1->data.getDtb() << endl;
            cout << endl;

            temp1 = temp1->next;
        }
    }

    //Nhap vao ho so mot hoc snh mo tu ban phim , chen ma khong lam thay doi
    //thu tu da sap xep
  void addAndSort() {
        string name;
        string classroom;
        string phoneNumber;
        float dtb;

        cout << "Them sinh vien moi:" << endl;
        cout << "Nhap ten sinh vien: ";
        getline(cin, name);
        cout << "Nhap lop: ";
        getline(cin, classroom);
        cout << "Nhap so dien thoai:";
        getline(cin, phoneNumber);
        cout << "Nhap dien trung binh:";
        cin >> dtb;

        Student student(name, classroom, phoneNumber, dtb);

        student.setTen(name);
        student.setLop(classroom);
        student.setSdt(phoneNumber);
        student.setDtb(dtb);

        Node* newNode = new Node(student);
        
        //neu ho sinh duoc them vao co diem cao nhat hoac la danh danh dang rong 
        if (head == nullptr || dtb >= head->data.getDtb()) {
            newNode->next = head;
            head = newNode;           
        } else {
            Node* current = head;
            Node* prev = nullptr;
            while (newNode->data.getDtb() <= current->data.getDtb()) {
                prev = current;
                current = current->next;
             }
            prev->next = newNode;
            newNode->next = current;
        }
        //check:
        Node* temp1 = head;
        while (temp1 != nullptr) {
            cout << "Ten: " << temp1->data.getTen() << endl;
            cout << "Lop: " << temp1->data.getLop() << endl;
            cout << "So dien thoai: " << temp1->data.getSdt() << endl;
            cout << "Diem trung binh: " << temp1->data.getDtb() << endl;
            cout << endl;

            temp1 = temp1->next;
        }
    }

    
    //luu lai tren dia khi da thay 
    void saveToFile(const string& filename) { 
        ofstream WriteFile(filename);
        if(!WriteFile) { 
            cout << "Khong mo duoc file!"<<endl;
            return;
        }
        Node* temp = head;
        //STT
        int i = 1 ; 
        while(temp != nullptr) { 
            WriteFile << "STT" << i << endl;
            WriteFile << " +Ten: " << temp->data.getTen() << endl;
            WriteFile << " +Lop: " << temp->data.getLop() << endl;
            WriteFile << " +So dien thoai: " << temp->data.getSdt() << endl;
            WriteFile << " +Dtb: " << temp->data.getDtb() << endl;
            temp = temp->next;
            i++;
        }

        WriteFile.close();
    }
};

int main() {
    studentList sl;
    //nhap danh sach tu file
    sl.FileToList("studentList.txt");
    
    //nhap danh sach tu ban phim
    sl.inputStudentList();
    

    //in ra ten va xep hang
    sl.printNameandRank();
    
    //in ra day du thong tin cua hoc sinh
    sl.printAll();
    
    //tim sinh vien , nhap vao ten va lop
    sl.findStudent("tai thanh", "cnttva2");
   
    //them 1 sinh vien moi
    sl.addStudent();
    
    //xoa sinh vien voi lop
    sl.delStudent("cnttva2");
    
    //sap xep giam dan
    sl.sortDecending();
    
    //them sinh vien moi va sap xep
    sl.addAndSort();
    
    //luu vao file
    sl.saveToFile("studentList_output.txt");
}
