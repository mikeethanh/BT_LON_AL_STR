#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Hashtable {
private:
    struct Node {
        string key;
        string value;
        Node* next;

        Node(string key, string value) : key(key), value(value), next(nullptr) {}
    };

    Node* head = nullptr;

public:
    //nap vao tu file
    void fileToHashTable(const string& filename) {
        ifstream ReadFile(filename);
        if (!ReadFile) {
            cout << "Khong mo duoc file" << endl;
        }
        else {
            string line;
            while (getline(ReadFile, line)) {
                int pos = -1;
                for (int i = 0; i < line.length(); i++) {
                    if (line[i] == ':') {
                        pos = i;
                        break;
                    }
                }               
                    Node* NewNode = new Node(line.substr(0, pos), line.substr(pos + 2));
                    NewNode->next = head;
                    head = NewNode;
            }
            ReadFile.close();

        }
    }

    //find
    void findOnHashTable(const string& word) {
        Node* temp = head;
        bool found = false;
        while (temp != nullptr) {
            if (temp->key == word) {
                cout << temp->key << ": " << temp->value << endl;
                found = true;
                return;
            }
            temp = temp->next;
        }
        if (!found) {
            cout << "Tu khong ton tai trong tu dien" << endl;
        }
    }

    //sua doi value :
    void fixWord(const string& wordNeedFix,const string& wordFix) {
        Node* temp = head;
        bool found = false;
        while (temp != nullptr) {
            if (temp->key == wordNeedFix) {
                temp->value = wordFix;
                found = true;
                cout << "Sua doi thanh cong" << endl;
                return;
            }
            else {
                temp = temp->next;
            }
        }
        if (!found) {
            cout << "Tu khong ton tai trong tu dien" << endl;
        }
    }

    //them tu moi : 
    void addWord(const string& word,const string& meanOfWord) {
        Node* newNode = new Node(word, meanOfWord);
        Node* temp = head;
        while (temp->next = nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;      
    }

    //xoa tu : 
    void removeWord(const string& word) {
        Node* temp = head;
        Node* prev = nullptr;
        while (temp != nullptr && temp->key != word) {
            prev = temp;
            temp = temp->next;
        }
        if (temp == nullptr) {
            cout << "tu khong ton tai trong tu dien";
            return;
        }

        // Nếu nút cần xóa là nút đầu tiên
       if(prev == nullptr) {
            head = temp->next;
            delete temp;
            return;
        }

        Node* RemoveThisNode = temp;
        prev->next = temp->next;
        delete RemoveThisNode;
    }
    
};


int main() {
    Hashtable h;
    h.fileToHashTable("tu_dien_anh_viet.txt");

    h.findOnHashTable("abaft");

    h.fixWord("abaft", "h");
}
