#include<iostream>
#include<queue>
using namespace std;
class StackUsingQueue{
    queue<int>q;
   public:
   void push(int x){
    int n=q.size();
    q.push(x);

    for(int i=0;i<n;i++){
        q.push(q.front());
        q.pop();
    }
   }
   void pop(){
    if(q.empty()){
        cout<<"stack underflow"<<endl;
        return;
    }q.pop();
   }
   int top(){
    if(q.empty()){
        cout<<"stack is empty"<<endl;
        return -1;
    }
    return q.front();
   }
   bool empty(){
    return q.empty();
   }
   int size(){
    q.size();
   }
};

int main() {
    StackUsingQueue st;

    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Top element: " << st.top() << endl;   // 30
    cout << "Stack size: " << st.size() << endl;   // 3

    st.pop();
    cout << "After pop, top: " << st.top() << endl; // 20

    st.pop();
    st.pop();
    cout << "Is stack empty? " << (st.empty() ? "Yes" : "No") << endl;

    st.pop(); // extra pop to test underflow

    return 0;
}