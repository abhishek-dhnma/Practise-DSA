#include <iostream>
#include <queue>

using namespace std;

int main() {

	priority_queue<int> maxheap;

	// priority_queue<int , vector<int> , less<int>> maxheap;

	for (int i = 0 ; i <= 10 ; i++) {
		maxheap.push(i);
	}

	cout << "Size : " << maxheap.size();

	cout << endl  << "Top : " << maxheap.top();

	maxheap.pop();

	cout << endl << "Size : " << maxheap.size();

	cout << endl << "Top : " << maxheap.top();

}
