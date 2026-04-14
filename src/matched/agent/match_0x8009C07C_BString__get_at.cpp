/* 0x8009C07C (76 bytes) - BString::get_at(unsigned int) const */

struct BStringRep {
    char *m_data;
    int m_length;
};

struct BString {
    BStringRep *m_rep;

    int length(void) const;
    char *data(void) const;
    char get_at(unsigned int idx) const;
};

extern void basic_string_ref__throwrange(void);

char BString::get_at(unsigned int idx) const {
    if (idx >= length())
        basic_string_ref__throwrange();
    return data()[idx];
}
