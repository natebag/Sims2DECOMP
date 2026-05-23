struct BStringRep {
    char pad[0x0C];
    int m_refCount;
};

struct BString {
    BStringRep *m_rep;

    int ref_count(void) const;
};

int BString::ref_count(void) const {
    return m_rep->m_refCount;
}
