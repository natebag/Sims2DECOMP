struct BStringRep {
    void *m_data;
    int m_length;
    int m_reserve;
    int m_ref_count;
};

class BString2 {
public:
    BStringRep *m_rep;

    int ref_count(void) const;
};

int BString2::ref_count(void) const {
    return m_rep->m_ref_count;
}
