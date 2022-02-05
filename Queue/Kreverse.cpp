#include <iostream>
#include<queue>
#include<stack>

using namespace std;

queue<int> KReverseQueue(queue<int> q1, int k) {

    if (q1.empty() == true || k > q1.size()) {
        return q1;
    }
    if (k <= 0) {
        return q1;
    }


    stack<int> s;

    // stack push
    for (int i = 0; i < k; i++) {
        s.push(q1.front());
        q1.pop();
    }

    //
    while (!s.empty()) {
        //cout<<s.top()<<" ";
        q1.push(s.top());
        s.pop();
    }
    //cout<<endl;


    for (int i = 0; i < q1.size() - k; i++) {
        q1.push(q1.front());
        q1.pop();
    }

    return q1;
}


void Print(queue<int>& Queue)
{
    while (!Queue.empty()) {
        cout << Queue.front() << " ";
        Queue.pop();
    }
}


int main() {

    //testcase
    int tc;
    cin >> tc;

    queue<int> q;

    while (tc--) {

        int n;
        cin >> n;


        int k;
        cin >> k;

        for (int i = 1; i <= n; i++) {

            q.push(i);
        }

        // Function Calling
        queue<int> res =  KReverseQueue(q, k);
        Print(res);
    }
}
