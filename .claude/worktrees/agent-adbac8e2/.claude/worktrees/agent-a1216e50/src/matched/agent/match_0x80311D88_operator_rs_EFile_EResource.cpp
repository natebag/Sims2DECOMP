struct EFile {
    void ReadU32(unsigned int *);
};

struct EResource;

EFile& operator>>(EFile& s, EResource*& p) {
    unsigned int tmp;
    s.ReadU32(&tmp);
    p = (EResource*)tmp;
    return s;
}
