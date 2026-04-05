/* AptValue::ClearReleaseAtEnd(void) at 0x802B48E4 (16B) */

struct AptValue {
    unsigned int m_data;

    void ClearReleaseAtEnd(void);
};

void AptValue::ClearReleaseAtEnd(void) {
    m_data &= ~0x20000000u;
}
