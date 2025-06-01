#include <iostream>
using namespace std;

class LinkedHashEntry {
    int key;
    int value;
    LinkedHashEntry* next;

public:
    LinkedHashEntry(int k, int v) : key(k), value(v), next(nullptr) {}

    int getKey() { return key; }
    int getValue() { return value; }
    void setValue(int v) { value = v; }
    LinkedHashEntry* getNext() { return next; }
    void setNext(LinkedHashEntry* n) { next = n; }
};

class HashMap {
    static const int TABLE_SIZE = 128;
    LinkedHashEntry** table;

    int hashFunction(int key) {
        return key % TABLE_SIZE;
    }

public:
    HashMap() {
        table = new LinkedHashEntry * [TABLE_SIZE];
        for (int i = 0; i < TABLE_SIZE; i++) {
            table[i] = nullptr;
        }
    }

    ~HashMap() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            LinkedHashEntry* entry = table[i];
            while (entry != nullptr) {
                LinkedHashEntry* prev = entry;
                entry = entry->getNext();
                delete prev;
            }
        }
        delete[] table;
    }

    int get(int key) {
        int hash = hashFunction(key);
        LinkedHashEntry* entry = table[hash];
        while (entry != nullptr && entry->getKey() != key) {
            entry = entry->getNext();
        }
        if (entry == nullptr) return -1; 
        else return entry->getValue();
    }

    void put(int key, int value) {
        int hash = hashFunction(key);
        if (table[hash] == nullptr) {
            table[hash] = new LinkedHashEntry(key, value);
        }
        else {
            LinkedHashEntry* entry = table[hash];
            LinkedHashEntry* prev = nullptr;
            while (entry != nullptr && entry->getKey() != key) {
                prev = entry;
                entry = entry->getNext();
            }
            if (entry == nullptr) {
              
                prev->setNext(new LinkedHashEntry(key, value));
            }
            else {
               
                entry->setValue(value);
            }
        }
    }

    void remove(int key) {
        int hash = hashFunction(key);
        if (table[hash] == nullptr) return;

        LinkedHashEntry* entry = table[hash];
        LinkedHashEntry* prev = nullptr;

        while (entry != nullptr && entry->getKey() != key) {
            prev = entry;
            entry = entry->getNext();
        }

        if (entry == nullptr) return;

        if (prev == nullptr) {
           
            table[hash] = entry->getNext();
        }
        else {
            prev->setNext(entry->getNext());
        }
        delete entry;
    }

    void display() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            LinkedHashEntry* entry = table[i];
            if (entry == nullptr) continue;
            cout << i << " --> ";
            while (entry != nullptr) {
                cout << "[" << entry->getKey() << ": " << entry->getValue() << "] ";
                entry = entry->getNext();
            }
            cout << endl;
        }
    }
};

int main() {
    HashMap map;
    map.put(1, 100);
    map.put(129, 200);
    map.put(257, 300); 

    map.display();

    cout << "Key 129 value: " << map.get(129) << endl;

    map.remove(129);
    cout << "129 key removed." << endl;

    map.display();

    return 0;
}
