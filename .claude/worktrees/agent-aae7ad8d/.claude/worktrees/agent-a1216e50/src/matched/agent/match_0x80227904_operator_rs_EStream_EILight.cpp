struct EStream {
    void ReadU32(unsigned int *);
};

struct EILight;

EStream& operator>>(EStream& s, EILight*& p) {
    unsigned int tmp;
    s.ReadU32(&tmp);
    p = (EILight*)tmp;
    return s;
}
