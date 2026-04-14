/* 0x8009C020 (68 bytes) - BString::data(void) const */

struct BStringRep {
    char *m_data;
    int m_length;
};

struct BString {
    BStringRep *m_rep;

    int length(void) const;
    char *data(void) const;
};

char *BString::data(void) const {
    if (length() != 0)
        return m_rep->m_data;
    return 0;
}
