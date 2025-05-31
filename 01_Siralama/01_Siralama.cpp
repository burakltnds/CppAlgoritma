#include <iostream>
using namespace std;

//----------BUBBLE----------

void bubbleSort(int dizi [] ,int boyut ) {
	
	for (int i = 0 ; i < boyut-1 ; i++) {
		for (int j = 0; j < boyut - 1 - i; j++) {
			if (dizi[j] > dizi[j + 1])
			{
				int temp;
				temp = dizi[j];
				dizi[j] = dizi[j + 1];
				dizi[j + 1] = temp;
			}
		}
	}
	
	
}

//----------QUİCK----------

void quickSort(int dizi[], int sol, int sag) {
	if (sol >= sag) return;
    int pivot = dizi[sol]; 
    int i = sol + 1;
    int j = sag;

    while (i <= j) {
        while (i <= sag && dizi[i] <= pivot) i++;
        while (dizi[j] > pivot) j--;

        if (i < j) {
            int temp = dizi[i];
            dizi[i] = dizi[j];
            dizi[j] = temp;
        }
    }

    int temp = dizi[sol];
    dizi[sol] = dizi[j];
    dizi[j] = temp;

    quickSort(dizi, sol, j - 1);
    quickSort(dizi, j + 1, sag);
}

//----------Selection----------

void selectionSort(int dizi[], int boyut) {
    for (int i = 0; i < boyut - 1; i++) {
        int minIndex = i;

        for (int j = i + 1; j < boyut; j++) {
            if (dizi[j] < dizi[minIndex]) {
                minIndex = j;
            }
        }

        if (minIndex != i) {
            int temp = dizi[i];
            dizi[i] = dizi[minIndex];
            dizi[minIndex] = temp;
        }
    }
}

//----------Merge----------

void merge(int dizi[], int sol, int orta, int sag) {
    int n1 = orta - sol + 1;
    int n2 = sag - orta;

    int* solDizi = new int[n1];
    int* sagDizi = new int[n2];

    for (int i = 0; i < n1; i++)
        solDizi[i] = dizi[sol + i];
    for (int j = 0; j < n2; j++)
        sagDizi[j] = dizi[orta + 1 + j];

    int i = 0, j = 0, k = sol;

    while (i < n1 && j < n2) {
        if (solDizi[i] <= sagDizi[j]) {
            dizi[k++] = solDizi[i++];
        }
        else {
            dizi[k++] = sagDizi[j++];
        }
    }

    while (i < n1)
        dizi[k++] = solDizi[i++];
    while (j < n2)
        dizi[k++] = sagDizi[j++];

    delete[] solDizi;
    delete[] sagDizi;
}

void mergeSort(int dizi[], int sol, int sag) {
    if (sol < sag) {
        int orta = sol + (sag - sol) / 2;

        mergeSort(dizi, sol, orta);
        mergeSort(dizi, orta + 1, sag);
        merge(dizi, sol, orta, sag);
    }
}

//----------Insertion----------

void insertionSort(int dizi[], int boyut) {
    if (boyut <= 1)
        return;

    insertionSort(dizi, boyut - 1);

    int son = dizi[boyut - 1];
    int j = boyut - 2;

    while (j >= 0 && dizi[j] > son) {
        dizi[j + 1] = dizi[j];
        j--;
    }

    dizi[j + 1] = son;
}

//----------Radix----------

void radixSort(int dizi[], int boyut) {
    int maks = dizi[0];
    for (int i = 1; i < boyut; i++)
        if (dizi[i] > maks)
            maks = dizi[i];

    for (int exp = 1; maks / exp > 0; exp *= 10) {
        int output[100]; 
        int count[10] = { 0 };

        for (int i = 0; i < boyut; i++)
            count[(dizi[i] / exp) % 10]++;

        for (int i = 1; i < 10; i++)
            count[i] += count[i - 1];

        for (int i = boyut - 1; i >= 0; i--) {
            int basamak = (dizi[i] / exp) % 10;
            output[count[basamak] - 1] = dizi[i];
            count[basamak]--;
        }

        for (int i = 0; i < boyut; i++)
            dizi[i] = output[i];
    }
}




int main()
{
	int dizi[] = { 0,8,2,6,4,9};
	int dizi1[] = { 0,7,3,9,1,4 };
	int dizi2[] = { 9,4,6,3,15,7};
    int dizi3[] = { 10,3,8,5,24,7 };
    int dizi4[] = { 12,4,9,1,19,8 };
    int dizi5[] = { 11,5,2,7,28,14 };
	int boyut = 6;
	
	//---BUBBLE---

	bubbleSort(dizi, boyut);
	cout << "Bubble Sort Sirali Dizi: ";

	for (int i = 0; i < boyut; i++)
	{
		cout << dizi[i] << " ";
	}
	cout << endl;

	//---QUICK---

	quickSort(dizi1, 0, boyut - 1);
	cout << "Quick Sort Sirali Dizi: ";
	for (int i = 0; i < boyut; i++)
	{
		cout << dizi1[i] << " ";
	}
	cout << endl;

	//---SELECTION---
	
    selectionSort(dizi2 ,boyut);
	cout << "Selection Sort Sirali Dizi: ";
	for (int i = 0; i < boyut; i++) {
		cout << dizi2[i] << " ";
	}
	cout << endl;

    //---MERGE---

    mergeSort(dizi3, 0,boyut-1);
    cout << "Merge Sort Sirali Dizi: ";
    for (int i = 0; i < boyut; i++) {
        cout << dizi3[i] << " ";
    }
    cout << endl;

    //---INSERTION---

    cout << "Insertion Sort Sirali Dizi: ";
    insertionSort(dizi4, boyut);
    for (int i = 0; i < boyut; i++) {
        cout << dizi4[i] << " ";
    }
    cout << endl;

    //---Radix---

    cout << "Radix Sort Sirali Dizi: ";
    insertionSort(dizi5, boyut);
    for (int i = 0; i < boyut; i++) {
        cout << dizi5[i] << " ";
    }
    cout << endl;
}