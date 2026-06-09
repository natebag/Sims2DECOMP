struct EFile {
    void ReadU32(unsigned int *);
};

struct ISimInstance;

EFile& operator>>(EFile& s, ISimInstance*& p) {
    unsigned int tmp;
    s.ReadU32(&tmp);
    p = (ISimInstance*)tmp;
    return s;
}
