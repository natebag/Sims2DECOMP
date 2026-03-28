struct EFile {
    void ReadU32(unsigned int *);
};

struct EIAmbLight;

EFile& operator>>(EFile& f, EIAmbLight*& p) {
    unsigned int tmp;
    f.ReadU32(&tmp);
    p = (EIAmbLight*)tmp;
    return f;
}
