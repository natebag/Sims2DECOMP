/* 0x8009C0C8 (76 bytes) - BString::operator[](unsigned int) const */

struct BStringRep {
    char *m_data;
    int m_length;
};

struct BString {
    BStringRep *m_rep;

    int length(void) const;
    char *data(void) const;
    char operator[](unsigned int idx) const;
};

char BString::operator[](unsigned int idx) const {
    if (idx < length())
        return data()[idx];
    return 0;
}
