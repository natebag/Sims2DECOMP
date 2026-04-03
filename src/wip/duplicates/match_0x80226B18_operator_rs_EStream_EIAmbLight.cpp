struct EStream {
    void ReadU32(unsigned int *);
};

struct EIAmbLight;

EStream& operator>>(EStream& s, EIAmbLight*& p) {
    unsigned int tmp;
    s.ReadU32(&tmp);
    p = (EIAmbLight*)tmp;
    return s;
}
