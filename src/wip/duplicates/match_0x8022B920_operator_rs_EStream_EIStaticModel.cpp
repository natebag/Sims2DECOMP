struct EStream {
    void ReadU32(unsigned int *);
};

struct EIStaticModel;

EStream& operator>>(EStream& s, EIStaticModel*& p) {
    unsigned int tmp;
    s.ReadU32(&tmp);
    p = (EIStaticModel*)tmp;
    return s;
}
