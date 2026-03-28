struct EFile {
    void ReadU32(unsigned int *);
};

struct EIStaticModel;

EFile& operator>>(EFile& s, EIStaticModel*& p) {
    unsigned int tmp;
    s.ReadU32(&tmp);
    p = (EIStaticModel*)tmp;
    return s;
}
