#include "../include/include.h"

bool IsValidParentheses(string input)
{
    stack<char> st;
    for (size_t i = 0; i < input.size(); ++i)
    {
        if (input[i] == '(' || input[i] == '{' || input[i] == '[') st.push(input[i]);
        else
        {
            if (st.empty()) return false;
            if (input[i] == ')' && st.top() != '(') return false;
            if (input[i] == ']' && st.top() != '[') return false;
            if (input[i] == '}' && st.top() != '{') return false;
            st.pop();
        }
    }
    return st.empty();
}

int main()
{
    assert_equal<bool>(IsValidParentheses("()"), true);
    assert_equal<bool>(IsValidParentheses("()[]{}"), true);
    assert_equal<bool>(IsValidParentheses("(]"), false);
    assert_equal<bool>(IsValidParentheses("([)]"), false);
    assert_equal<bool>(IsValidParentheses("{[]}"), true);
    return 0;
}
