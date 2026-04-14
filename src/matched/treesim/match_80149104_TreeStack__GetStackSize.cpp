// 0x80149104 (20 bytes)
// TreeStack::GetStackSize(void)
// lwz r0, 8(r3); lwz r3, 12(r3); subf r3, r0, r3; srawi r3, r3, 2; blr
// subf r3, r0, r3 = r3 - r0; srawi r3, r3, 2 = /4
// Returns (field12 - field8) >> 2 = (end - begin) / sizeof(int)

class TreeStack {
public:
    char _pad0[8];
    int* m_begin;  // offset 8
    int* m_end;    // offset 12
    int GetStackSize();
};

int TreeStack::GetStackSize() {
    return (int)(m_end - m_begin);
}
