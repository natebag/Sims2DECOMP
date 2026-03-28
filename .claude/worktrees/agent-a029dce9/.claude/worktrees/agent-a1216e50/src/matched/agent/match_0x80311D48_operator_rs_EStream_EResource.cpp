struct EStream {
    void ReadU32(unsigned int *);
};

struct EResource;

EStream& operator>>(EStream& s, EResource*& p) {
    unsigned int tmp;
    s.ReadU32(&tmp);
    p = (EResource*)tmp;
    return s;
}
