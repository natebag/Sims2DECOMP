/* BString2::len(void) at 0x800A0188 (12B) */

struct basic_string_ref2 {
    void* m_ptr;
    int m_length;
};

struct BString2 {
    basic_string_ref2* m_ref;

    int* len(void);
};

int* BString2::len(void) {
    return &m_ref->m_length;
}
