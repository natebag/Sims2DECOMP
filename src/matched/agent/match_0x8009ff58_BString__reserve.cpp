struct BStringRep {
    char *m_data;
    int m_length;
    int m_reserve;
};

struct BString {
    BStringRep *m_rep;

    int reserve(void) const;
};

int BString::reserve(void) const {
    return m_rep->m_reserve;
}
