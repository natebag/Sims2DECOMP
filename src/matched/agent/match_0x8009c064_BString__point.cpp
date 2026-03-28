struct BStringRep {
    char *m_data;
};

struct BString {
    BStringRep *m_rep;

    char *point(void);
};

char *BString::point(void) {
    return m_rep->m_data;
}
