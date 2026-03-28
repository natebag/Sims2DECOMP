struct EFile {
    void ReadU32(unsigned int *);
};

struct EILight;

EFile& operator>>(EFile& f, EILight*& p) {
    unsigned int tmp;
    f.ReadU32(&tmp);
    p = (EILight*)tmp;
    return f;
}
