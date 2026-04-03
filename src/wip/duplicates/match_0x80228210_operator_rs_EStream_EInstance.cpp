struct EStream {
    void ReadU32(unsigned int *);
};

struct EInstance;

EStream& operator>>(EStream& s, EInstance*& p) {
    unsigned int tmp;
    s.ReadU32(&tmp);
    p = (EInstance*)tmp;
    return s;
}
