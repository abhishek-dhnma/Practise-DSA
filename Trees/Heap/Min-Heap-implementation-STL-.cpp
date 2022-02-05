#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {

	// Default Arguments

	priority_queue<int, vector<int>, greater<int> > minheap;

	for (int i = 0 ; i <= 12 ; i++) {
		minheap.push(i);
	}

	cout << "Size : " << minheap.size();

	cout << endl  << "Top : " << minheap.top();

	minheap.pop();

	cout << endl << "Size : " << minheap.size();

	cout << endl << "Top : " << minheap.top();

	cout << endl;

	while (!minheap.empty()) {
		cout << minheap.top() << " ";
		minheap.pop();
	}

}
