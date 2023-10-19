
#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <locale>
using namespace std;
//const : tranh bi thay doi value khi tham chieu
class HashTable {
private:
    map<string, string> mp;
public:
    // Nạp từ điển từ file vào bảng băm
    void fileToHashTable(const string& filename) {
        ifstream Readfile(filename);

        if (!Readfile) {
            cout << "khong the mo file" << endl;
            return;
        }

        string line;
        while (getline(Readfile, line)) {
            string key, value;
            int pos = -1;
            for (int i = 0; i < line.length(); i++) {
                if (line[i] == ':') {
                    pos = i;
                    break;
                }
            }
            
                key = line.substr(0, pos);
                value = line.substr(pos + 2);
                mp[key] = value;
            
        }
        for (auto it : mp) {
            cout << it.first << ": " << it.second << endl;
        }
        Readfile.close();
    }

    //tim kiem bang phuong phap tim kiem trong bang bam 
    void findOnHashtable(const string& word) {      
        if (mp.find(word) != mp.end()) {
            cout << mp[word] << endl;
        }
        else {
            cout << "Tu khong ton tai trong tu dien";
        }
    }

    //sua doi cac tu :
    void fixWord(const string& wordNeedFix,const string& fixWord) {
        
        if (mp.find(wordNeedFix) != mp.end()) {
            mp[wordNeedFix] = fixWord;
            cout << "Sua tu thanh cong";
        }
        else {
            cout << "Tu khong ton tai trong tu dien";
        }
        //check
        cout << mp[wordNeedFix] << endl;
    }

    //them tu moi:
    void addWord(const string& word,const string& mean) {
        mp[word] = mean;
        //check 
        for (auto it : mp) {
            cout << it.first << ": " << it.second << endl;
        }
    }

    //xoa tu:
    void removeWord(const string& word) {
        if (mp.find(word) != mp.end()) {
            mp.erase(word);
            cout << "Xoa tu thanh cong";
        }
        else {
            cout << "Tu khong ton tai trong tu dien";
        }
    }

    //luu tu dien vao file : 
    void saveDicInFile(const string& filename) {
        ofstream WriteFile(filename);
        if (!WriteFile) {
            cout << "khong the mo file";
        }
        else {
            for (auto it : mp) {
                WriteFile << it.first << ": " << it.second << endl;
            }
            WriteFile.close();
        }
    }
};


int main() {
    HashTable hashtable;
    //chuyen ten file
    hashtable.fileToHashTable("tu_dien_anh_viet.txt");

    //chuyen tu can tim
    hashtable.findOnHashtable("abaft");

    //chuyen tu can sua va sua tu 
    hashtable.fixWord("abaft","da sua");

    //chuyen tu va nghia cua tu
    hashtable.addWord("hello","xin chao");

    //chuyen tu can xoa
    hashtable.removeWord("abaft");

    //chuyen file can save
    hashtable.saveDicInFile("tu_dien_anh_viet(wfile).txt");
}
