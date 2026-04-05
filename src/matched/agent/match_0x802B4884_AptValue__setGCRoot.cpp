/* AptValue::setGCRoot(unsigned int) at 0x802B4884 (16B) */

struct AptValue {
    unsigned int m_high : 18;
    unsigned int m_gcRoot : 6;
    unsigned int m_low : 8;

    void setGCRoot(unsigned int val);
};

void AptValue::setGCRoot(unsigned int val) {
    m_gcRoot = val;
}
