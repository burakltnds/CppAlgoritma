#include <iostream>
using namespace std;

void hanoi(int n, char kaynak, char hedef, char yardimci) {
    if (n == 1) {
        cout << "Diski 1 " << kaynak << " -> " << hedef << endl;
        return;
    }

    
    hanoi(n - 1, kaynak, yardimci, hedef);

    
    cout << "Diski " << n << " " << kaynak << " -> " << hedef << endl;

    
    hanoi(n - 1, yardimci, hedef, kaynak);
}

int main() {
    int diskSayisi = 3;
    hanoi(diskSayisi, 'A', 'C', 'B'); 
    return 0;
}
