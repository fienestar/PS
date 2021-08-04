/*
    트리 순회
    https://www.acmicpc.net/problem/1991
*/
#include <iostream>

using namespace std;

struct Node{
    char r,l;
};

static Node Nodes[26];

#define GetNodeFromChar(Char) (Nodes[Char-'A'])
#define GetCharFromNode(Node) (char)('A'+(&Node-Nodes))
#define GetFirstNode() Nodes[0]
/// A B C
/// B A C
/// B C A
void tf(Node& node)
{
    cout<<GetCharFromNode(node);
    if(node.r!='.')tf(GetNodeFromChar(node.r));
    if(node.l!='.')tf(GetNodeFromChar(node.l));
}

void ts(Node& node)
{
    if(node.r!='.')ts(GetNodeFromChar(node.r));
    cout<<GetCharFromNode(node);
    if(node.l!='.')ts(GetNodeFromChar(node.l));
}

void tt(Node& node)
{
    if(node.r!='.')tt(GetNodeFromChar(node.r));
    if(node.l!='.')tt(GetNodeFromChar(node.l));
    cout<<GetCharFromNode(node);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    size_t N;
    char c,r,l;
    cin >> N;
    while(N--){
        cin >> c >> r >> l;
        GetNodeFromChar(c).r = r;
        GetNodeFromChar(c).l = l;
    }
    tf(GetFirstNode());
    cout << "\n";
    ts(GetFirstNode());
    cout << "\n";
    tt(GetFirstNode());
    return 0;
}
