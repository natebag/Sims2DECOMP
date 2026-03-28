struct BStringRep {
    void *m_data;
    int m_length;
};

class BString2 {
public:
    BStringRep *m_rep;

    int length(void) const;
};

int BString2::length(void) const {
    return m_rep->m_length;
}
