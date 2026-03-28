// 0x802C8610 (28 bytes) - EFixedString::GetBuffer(int)
// lwz r0,4(r3); cmpw r4,r0; ble +12; li r3,0; blr; lwz r3,0(r3); blr

struct EFixedString_GB {
    void* m_buffer;
    int m_capacity;

    void* GetBuffer(int size);
};

void* EFixedString_GB::GetBuffer(int size) {
    if (size > m_capacity) return 0;
    return m_buffer;
}
