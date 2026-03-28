struct EFile {
    void ReadU32(unsigned int *);
};

struct EISpotLight;

EFile& operator>>(EFile& s, EISpotLight*& p) {
    unsigned int tmp;
    s.ReadU32(&tmp);
    p = (EISpotLight*)tmp;
    return s;
}
