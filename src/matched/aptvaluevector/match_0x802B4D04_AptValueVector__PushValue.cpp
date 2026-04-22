// 0x802B4D04 (56B) AptValueVector::PushValue(AptValue*)

struct AptValue {
    unsigned int m_bits;
};

struct AptValueVector {
    int m_capacity;
    int m_size;
    AptValue** m_data;

    void PushValue(AptValue* val);
};

void AptValueVector::PushValue(AptValue* val) {
    if (m_size >= m_capacity) {
        val->m_bits &= ~0x20000000u;
    } else {
        int idx = m_size;
        m_data[idx] = val;
        m_size = idx + 1;
    }
}
