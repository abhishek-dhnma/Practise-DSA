#include <iostream>
#include <queue>
using namespace std;

void print(priority_queue<int, vector<int> , greater<int> > min_heap) {

    while (!min_heap.empty()) {
        cout << min_heap.top() << " ";
        min_heap.pop();
    }
}

int main() {

    priority_queue<int, vector<int> , greater<int> > min_heap;

    int k;
    cin >> k;

    // First k elements in the min_heap
    for (int i = 0; i < k; i++)
    {   int x;
        cin >> x;
        min_heap.push(x);
    }

    int data;

    while (true) {

        cin >> data;

        if (data == -1) {
            print(min_heap);
        }
        else {
            if (data > min_heap.top()) {
                min_heap.pop();
                min_heap.push(data);
            }

        }
    }
}
