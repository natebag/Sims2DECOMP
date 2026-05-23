struct BStringRep {
    char pad[0x04];
    int m_length;
};

struct BString {
    BStringRep *m_rep;

    int *len(void);
};

int *BString::len(void) {
    return &m_rep->m_length;
}
