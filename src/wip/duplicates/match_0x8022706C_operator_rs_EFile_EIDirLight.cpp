struct EFile {
    void ReadU32(unsigned int *);
};

struct EIDirLight;

EFile& operator>>(EFile& f, EIDirLight*& p) {
    unsigned int tmp;
    f.ReadU32(&tmp);
    p = (EIDirLight*)tmp;
    return f;
}
