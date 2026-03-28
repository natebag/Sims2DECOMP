/* BString2::ref_count(void) const at 0x800A0170 (12B) */

struct basic_string_ref2 {
    void* m_ptr;
    int m_length;
    int m_reserve;
    int m_refCount;
};

struct BString2 {
    basic_string_ref2* m_ref;

    int ref_count(void) const;
};

int BString2::ref_count(void) const {
    return m_ref->m_refCount;
}
