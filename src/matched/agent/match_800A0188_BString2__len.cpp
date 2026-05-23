struct BStringRep {
    void *m_data;
    int m_length;
};

class BString2 {
public:
    BStringRep *m_rep;

    int *len(void);
};

int *BString2::len(void) {
    return &m_rep->m_length;
}
