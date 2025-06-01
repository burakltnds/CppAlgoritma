#include <iostream>
using namespace std;

int binarySearch(int arr[], int size, int x) {
    int low = 0;
    int high = size - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == x)
            return mid;  
        else if (arr[mid] < x)
            low = mid + 1;  
        else
            high = mid - 1; 
    }
    return -1; 
}
int main() {
    int dizi[] = { 5,6,7,2,4,35,14,96,57};
    cout << "Arananin Index : " << binarySearch(dizi, 9, 14);

    return 0;
}
