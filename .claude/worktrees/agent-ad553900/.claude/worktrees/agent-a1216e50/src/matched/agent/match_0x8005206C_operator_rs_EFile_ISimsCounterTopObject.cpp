struct EFile {
    void ReadU32(unsigned int *);
};

struct ISimsCounterTopObject;

EFile& operator>>(EFile& s, ISimsCounterTopObject*& p) {
    unsigned int tmp;
    s.ReadU32(&tmp);
    p = (ISimsCounterTopObject*)tmp;
    return s;
}
