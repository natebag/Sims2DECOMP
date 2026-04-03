struct EStream {
    void ReadU32(unsigned int *);
};

struct EIPointLight;

EStream& operator>>(EStream& s, EIPointLight*& p) {
    unsigned int tmp;
    s.ReadU32(&tmp);
    p = (EIPointLight*)tmp;
    return s;
}
