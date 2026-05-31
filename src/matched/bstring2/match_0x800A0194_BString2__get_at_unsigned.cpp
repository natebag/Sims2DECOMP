/* BString2::get_at(unsigned int) const - 0x800A0194 (100 bytes) */

struct BString2Rep {
    unsigned short *m_data;
    int m_length;
};

struct BString2 {
    BString2Rep *m_rep;

    int length(void) const;
    unsigned short *data(void) const { if (length() != 0) return m_rep->m_data; return 0; }
    unsigned short get_at(unsigned int idx) const;
};

extern void basic_string_ref2__throwrange(void);

unsigned short BString2::get_at(unsigned int idx) const {
    if (idx >= (unsigned int)length())
        basic_string_ref2__throwrange();
    return data()[idx];
}
