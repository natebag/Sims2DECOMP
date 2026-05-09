// 0x8014AB4C WantFear::Tree::GetNthChildOfNode(WantFear::Node*, short) const (36B)

namespace WantFear {

struct Node {
    char pad[10];
    short m_childOffset;
    char pad2[20];
};

struct Tree {
    char pad[40];
    Node* m_nodes;
    signed char* m_chars;
    Node* GetNthChildOfNode(Node* node, short n) const;
};

Node* Tree::GetNthChildOfNode(Node* node, short n) const {
    int off = node->m_childOffset + n;
    return m_nodes + ((short*)m_chars)[off];
}

}
