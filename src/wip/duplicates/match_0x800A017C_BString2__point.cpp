/* BString2::point(void) at 0x800A017C (12B) */

struct basic_string_ref2 {
    void* m_ptr;
};

struct BString2 {
    basic_string_ref2* m_ref;

    void* point(void);
};

void* BString2::point(void) {
    return m_ref->m_ptr;
}
