// 0x803A5210 WantFear::Tree::GetNodeById(short) const (16B)
namespace WantFear {

struct Node {
    char pad[32];
};

struct Tree {
    char pad[40];
    Node* m_nodes;  // +40
    Node* GetNodeById(short id) const;
};

Node* Tree::GetNodeById(short id) const {
    return &m_nodes[id];
}

}
