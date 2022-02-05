#include <iostream>
#include<stack>
using namespace std;

int main() {
    int n;
    cin >> n;

    stack<int> s;

    int mid = n / 2;
    //cout<<mid<<endl;
    int ss = n;

    while (n--) {
        int i;
        cin >> i;
        s.push(i);
    }


    for (int i = 0; i < ss; i++) {

        if (i == mid) {
            s.pop();
        } else {
            cout << s.top() << " ";
            s.pop();
        }
    }


}
