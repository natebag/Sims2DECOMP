/* BString2::reserve(void) const at 0x800A4864 (12B) */

struct basic_string_ref2 {
    void* m_ptr;
    int m_length;
    int m_reserve;
};

struct BString2 {
    basic_string_ref2* m_ref;

    int reserve(void) const;
};

int BString2::reserve(void) const {
    return m_ref->m_reserve;
}
