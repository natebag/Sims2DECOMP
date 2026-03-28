struct EFile {
    void ReadU32(unsigned int *);
};

struct EIPointLight;

EFile& operator>>(EFile& s, EIPointLight*& p) {
    unsigned int tmp;
    s.ReadU32(&tmp);
    p = (EIPointLight*)tmp;
    return s;
}
