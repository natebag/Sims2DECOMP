/* BString2::length(void) const at 0x800A4858 (12B) */

struct basic_string_ref2 {
    void* m_ptr;
    int m_length;
};

struct BString2 {
    basic_string_ref2* m_ref;

    int length(void) const;
};

int BString2::length(void) const {
    return m_ref->m_length;
}
