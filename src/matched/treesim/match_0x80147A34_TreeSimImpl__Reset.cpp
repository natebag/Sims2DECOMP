// 0x80147A34 (108B) TreeSimImpl::Reset(Behavior*, short)

class Behavior;

class TreeStack {
public:
    void Reset();
};

class TreeSimImpl {
public:
    char m_pad0[12];
    TreeStack m_stack;
    char m_pad13[52 - 12 - 1];
    short m_34;
    void Reset(Behavior* b, short arg);
    void Gosub(Behavior* b, short* localPtr, short arg);
};

void TreeSimImpl::Reset(Behavior* b, short arg) {
    m_stack.Reset();
    if (arg != 0) {
        int local[2] = {0, 0};
        Gosub(b, (short*)local, arg);
        m_34 = 0;
    }
}
