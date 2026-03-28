struct EStream {
    void ReadU32(unsigned int *);
};

struct ISimInstance;

EStream& operator>>(EStream& s, ISimInstance*& p) {
    unsigned int tmp;
    s.ReadU32(&tmp);
    p = (ISimInstance*)tmp;
    return s;
}
