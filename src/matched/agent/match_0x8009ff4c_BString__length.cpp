struct BStringRep {
    char *m_data;
    int m_length;
};

struct BString {
    BStringRep *m_rep;

    int length(void) const;
};

int BString::length(void) const {
    return m_rep->m_length;
}
