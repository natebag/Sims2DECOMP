struct EStream {
    void ReadU32(unsigned int *);
};

struct EIPointAmbLight;

EStream& operator>>(EStream& s, EIPointAmbLight*& p) {
    unsigned int tmp;
    s.ReadU32(&tmp);
    p = (EIPointAmbLight*)tmp;
    return s;
}
