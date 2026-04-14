// 0x80148D28 (16 bytes) - TreeStack::GetMemReserved(void)
// lwz r0,0(r3); lwz r3,4(r3); subf r3,r0,r3; blr

struct TreeStack_GMR {
    int m_start;
    int m_end;

    int GetMemReserved();
};

int TreeStack_GMR::GetMemReserved() {
    return m_end - m_start;
}
