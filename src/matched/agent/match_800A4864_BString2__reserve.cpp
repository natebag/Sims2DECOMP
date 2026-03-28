struct BStringRep {
    void *m_data;
    int m_length;
    int m_reserve;
};

class BString2 {
public:
    BStringRep *m_rep;

    int reserve(void) const;
};

int BString2::reserve(void) const {
    return m_rep->m_reserve;
}
