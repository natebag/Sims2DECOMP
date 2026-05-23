struct BStringRep {
    void *m_data;
};

class BString2 {
public:
    BStringRep *m_rep;

    void *point(void);
};

void *BString2::point(void) {
    return m_rep->m_data;
}
