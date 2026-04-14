/* AptValue::SetReleaseAtEnd(void) at 0x802B48D4 (16B) */

struct AptValue {
    unsigned int m_data;

    void SetReleaseAtEnd(void);
};

void AptValue::SetReleaseAtEnd(void) {
    m_data |= 0x20000000;
}
