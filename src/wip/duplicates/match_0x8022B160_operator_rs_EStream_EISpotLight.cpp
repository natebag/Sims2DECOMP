struct EStream {
    void ReadU32(unsigned int *);
};

struct EISpotLight;

EStream& operator>>(EStream& s, EISpotLight*& p) {
    unsigned int tmp;
    s.ReadU32(&tmp);
    p = (EISpotLight*)tmp;
    return s;
}
