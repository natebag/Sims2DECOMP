struct EFile {
    void ReadU32(unsigned int *);
};

struct EInstance;

EFile& operator>>(EFile& f, EInstance*& p) {
    unsigned int tmp;
    f.ReadU32(&tmp);
    p = (EInstance*)tmp;
    return f;
}
