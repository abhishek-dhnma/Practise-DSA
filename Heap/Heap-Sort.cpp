#include <iostream>
#include <vector>
using namespace std;

void heapify(int v[], int n,  int index) {
    int maxindex = index;
    int leftindex = 2 * index;

    if (leftindex < n && v[leftindex] > v[maxindex])
    {
        maxindex = leftindex;
    }

    int rightindex = 2 * index + 1;

    if (rightindex < n && v[rightindex] > v[maxindex])
    {
        maxindex = rightindex;
    }

    if (maxindex != index) {
        swap(v[index], v[maxindex]);
        heapify(v, n, maxindex);
    }
}

int main() {

    int v[] = { -1, 6, 8, 3, 5, 4, 9, 7, 2, 0, 1};

    int n = sizeof(v) / sizeof(int);

    int start = n / 2;

    cout << n << " " << start << " " << endl;

    for (int i = start ; i >= 1; i-- ) {
        heapify(v, n, i);
    }


    for (int i = 1; i < n; i++) {
        cout << v[i] << " ";
    }

    cout << endl;


    // Heap Sort

    int headsize = n; // n = including dummy first element
    while (headsize > 1) {
        swap(v[1], v[headsize - 1]);
        headsize--;
        heapify(v, headsize, 1);
    }

    /*
    1. swap(first, last) elements
    2. decrease size of array (headsize--)
    3. call heapify for making max heap properties
    4. Repeat 1 2 3 steps untill (headsize > 1) i.e. 1 is dummy element

    */

    // Printing Array

    for (int i = 1; i < n; i++) {
        cout << v[i] << " ";
    }

}
