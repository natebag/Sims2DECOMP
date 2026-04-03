struct EStream {
    void ReadU32(unsigned int *);
};

struct EIStaticSubModel;

EStream& operator>>(EStream& s, EIStaticSubModel*& p) {
    unsigned int tmp;
    s.ReadU32(&tmp);
    p = (EIStaticSubModel*)tmp;
    return s;
}
