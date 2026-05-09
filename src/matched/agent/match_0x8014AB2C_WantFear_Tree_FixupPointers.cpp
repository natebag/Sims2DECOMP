// 0x8014AB2C WantFear::Tree::FixupPointers(signed char*, WantFear::Node*) (32B)

namespace WantFear {

struct Node {
    char data[32];   // sizeof = 32 (slwi by 5)
};

struct Tree {
    char pad[40];
    Node* m_nodes;       // offset 40 (stored as int index pre-fixup)
    signed char* m_chars;  // offset 44 (stored as int offset pre-fixup)
    void FixupPointers(signed char*, Node*);
};

void Tree::FixupPointers(signed char* charBase, Node* nodeBase) {
    int nodeIdx = (int)m_nodes;
    int charOff = (int)m_chars;
    m_nodes = nodeBase + nodeIdx;
    m_chars = charBase + charOff;
}

}
