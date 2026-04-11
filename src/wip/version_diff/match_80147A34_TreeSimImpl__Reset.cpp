// 0x80147A34 (108 bytes)
// TreeSimImpl::Reset(Behavior*, short)
// Resets the tree stack, then calls Gosub if node != 0, clears m_field034

class TreeStack {
public:
    char* m_start;       // offset 0
    char* m_end_cap;     // offset 4
    void** m_begin;      // offset 8
    void** m_end;        // offset 12
    void Reset();
};

class Behavior;

class TreeSimImpl {
public:
    char _pad[12];
    TreeStack m_stack;    // offset 12
    char _pad2[24];       // to reach offset 52 = 0x34 (12 + 16 + 24 = 52)
    short m_field034;     // offset 52 = 0x34
    void Reset(Behavior* beh, short node);
    void Gosub(Behavior* beh, int* params, short node);
};

void TreeSimImpl::Reset(Behavior* beh, short node) {
    m_stack.Reset();
    if (node != 0) {
        int params[2] = {0, 0};
        Gosub(beh, params, node);
    }
    m_field034 = 0;
}
