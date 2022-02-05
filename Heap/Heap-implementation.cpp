#include <iostream>
#include <vector>

using namespace std;

class heap {

	vector<int> v;

	void heapify(int index) {
		int maxindex = index;
		int leftindex = 2 * index;

		if (leftindex < v.size() && v[leftindex] > v[maxindex])
		{
			maxindex = leftindex;
		}

		int rightindex = 2 * index + 1;

		if (rightindex < v.size() && v[rightindex] > v[maxindex])
		{
			maxindex = rightindex;
		}

		if (maxindex != index) {
			swap(v[index], v[maxindex]);
			heapify(maxindex);
		}
	}

public:

	heap() {
		v.push_back(0);
	}

	void push(int data) {
		v.push_back(data);
		int childindex = v.size() - 1;
		int parentindex = childindex / 2;

		while (childindex > 1 && v[parentindex] < v[childindex]) {
			swap(v[parentindex], v[childindex]);
			childindex = parentindex;
			parentindex = childindex / 2;
		}
	}

	void pop() {
		swap(v[1], v[v.size() - 1]);
		v.pop_back();
		heapify(1);

	}

	int top() {
		return v[1];
	}

	int size() {
		return v.size() - 1;
	}

	bool empty() {
		return v.size() - 1 == 0 ? true : false;
	}
};

int main() {

	heap maxheap;

	for (int i = 0 ; i <= 10 ; i++) {
		maxheap.push(i);
	}

	cout << "Size : " << maxheap.size();

	cout << endl  << "Top : " << maxheap.top();

	maxheap.pop();

	cout << endl << "Size : " << maxheap.size();

	cout << endl << "Top : " << maxheap.top();


	return 0;
}