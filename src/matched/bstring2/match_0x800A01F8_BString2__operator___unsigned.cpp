/* BString2::operator[](unsigned int) const - 0x800A01F8 (104 bytes) */

struct BString2Rep {
    unsigned short *m_data;
    int m_length;
};

struct BString2 {
    BString2Rep *m_rep;

    int length(void) const;
    unsigned short *data(void) const { if (length() != 0) return m_rep->m_data; return 0; }
    unsigned short operator[](unsigned int idx) const;
};

unsigned short BString2::operator[](unsigned int idx) const {
    if (idx < (unsigned int)length())
        return data()[idx];
    return 0;
}
