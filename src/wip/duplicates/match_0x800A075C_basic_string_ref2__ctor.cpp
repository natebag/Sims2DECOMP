/* basic_string_ref2::basic_string_ref2(void) at 0x800A075C (20B) */

struct basic_string_ref2 {
    void* m_ptr;
    int m_length;
    int m_reserve;
    int m_refCount;

    basic_string_ref2(void);
};

basic_string_ref2::basic_string_ref2(void) {
    m_refCount = m_refCount + 1;
}
