/*
    Flow Graph Complexity
    https://www.acmicpc.net/problem/14748
*/
#include <bits/stdc++.h>

using namespace std;

#define expect(expression, more_info)                                           \
    do                                                                          \
    {                                                                           \
        if (!(expression))                                                      \
        {                                                                       \
            cout << "-1";                                                       \
            if (false)                                                          \
                cout << #expression << " is false on line " << __LINE__ << "\n" \
                     << more_info << "\n";                                      \
            exit(0);                                                            \
        }                                                                       \
    } while (0)

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);

    string first_line;
    getline(cin, first_line);

    int W;
    istringstream(first_line) >> W;

    string P;
    getline(cin, P);

    int EF = 0, EB = 0, V = 0;
    stack<char> s;
    s.push('\0');
    char before = ',';
    for (size_t i = 0; i != P.size(); ++i)
    {
        char c = P[i];
        switch (c)
        {
        case ',':
            expect(before == ']' || before == ')' || before == 'S', P.c_str() + i);
            break;
        case ' ':
            continue;
        case '(':
        case '[':
            s.push(c);
            expect(before == 'L' || before == 'B', P.c_str() + i);
            break;
        case ')':
        case ']':
            expect(before == 'S' || before == ')' || before == ']', P.c_str() + i);
            if (c == ')')
                expect(s.top() == '(', P.c_str() + i);
            else
                expect(s.top() == '[', P.c_str() + i);

            s.pop();
            break;
        case 'S':
            expect(before == ',' || before == '(' || before == '[', before);
            ++V;
            ++EF;
            break;
        case 'L':
            expect(before == ',' || before == '(' || before == '[', P.c_str() + i);
            V += 2;
            EF += 2;
            ++EB;
            break;
        case 'B':
            expect(before == ',' || before == '(' || before == '[', P.c_str() + i);
            V += 2;
            EF += 3;
            break;
        default:
            expect(false, c);
        }
        before = c;
    }

    expect(before == 'S' || before == ')' || before == ']', "last ch");
    expect(s.size() == 1, "stack is full on exit");

    --EF;
    cout << EF + W * EB - V + 2;
}