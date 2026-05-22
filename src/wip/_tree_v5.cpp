// 0x80147A34 (108B) TreeSimImpl::Reset(Behavior*, short)

class TreeStack {
public:
    char* m_start;
    char* m_end_cap;
    void** m_begin;
    void** m_end;
    void Reset();
};

class Behavior;

class TreeSimImpl {
public:
    char _pad[12];
    TreeStack m_stack;
    char _pad2[24];
    short m_field034;
    void Reset(Behavior* beh, short node);
    void Gosub(Behavior* beh, int* params, short node);
};

void TreeSimImpl::Reset(Behavior* beh, short node) {
    m_stack.Reset();
    if (node != 0) {
        int params[2] = {0, 0};
        Gosub(beh, params, node);
        m_field034 = 0;
    }
}
