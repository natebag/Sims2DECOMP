// 0x801490D0 (52 bytes)
// TreeStack::GetNthFrame(int) — explicit goto + lwzx operand swap
// ASMPROC_swap_operands: match="lwzx 3,9,11" pos=1,2

class TreeStack {
public:
    char _pad[8];
    void** m_begin;
    void** m_end;
    void* GetNthFrame(int n);
};

void* TreeStack::GetNthFrame(int n) {
    if (n < 0) goto null_path;
    {
        int size = (int)(m_end - m_begin);
        if ((unsigned)n < (unsigned)size) goto valid_path;
    }
null_path:
    return 0;
valid_path:
    return m_begin[n];
}
