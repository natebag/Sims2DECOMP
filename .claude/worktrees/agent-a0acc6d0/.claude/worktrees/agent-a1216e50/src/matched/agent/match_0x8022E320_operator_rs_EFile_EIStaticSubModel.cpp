struct EFile {
    void ReadU32(unsigned int *);
};

struct EIStaticSubModel;

EFile& operator>>(EFile& s, EIStaticSubModel*& p) {
    unsigned int tmp;
    s.ReadU32(&tmp);
    p = (EIStaticSubModel*)tmp;
    return s;
}
