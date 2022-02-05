#include <iostream>
#include <vector>
using namespace std;

void heapify(vector<int> v, int n,  int index) {
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

    vector<int> v = { -1, 6, 8, 3, 5, 4, 9, 7, 2, 0, 1};
    int n = v.size();

    int start = n / 2;

    cout << n << " " << start << " " << endl;

    for (int i = start ; i >= 1; i-- ) {
        heapify(v, n, i);
    }


    for (int i = 1; i < n; i++) {
        cout << v[i] << " ";
    }

}
