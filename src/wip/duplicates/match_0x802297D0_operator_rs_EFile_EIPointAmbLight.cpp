struct EFile {
    void ReadU32(unsigned int *);
};

struct EIPointAmbLight;

EFile& operator>>(EFile& s, EIPointAmbLight*& p) {
    unsigned int tmp;
    s.ReadU32(&tmp);
    p = (EIPointAmbLight*)tmp;
    return s;
}
