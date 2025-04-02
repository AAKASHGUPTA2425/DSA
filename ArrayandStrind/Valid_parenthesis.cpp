#include <iostream>
#include <stack>
#include <string>
using namespace std;
bool Valid_parenthesis(string s)
{
    stack<char> sta;
    for (char ch : s)
    {
        if (ch == '(' || ch == '{' || ch == '[')
        {
            sta.push(ch);
        }
        else
        {
           if(sta.empty()) return false;
        }

        char top = sta.top();
        if (ch == ')' && top == '(' || ch == '}' && top == '{' || ch == ']' && top == '[')
        {
            sta.pop();
        }
    }

    if (sta.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    string s = "()";
   bool result= Valid_parenthesis(s);
   cout<<result;
    return 0;
}