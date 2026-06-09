struct EStream {
    void ReadU32(unsigned int *);
};

struct ISimsCounterTopObject;

EStream& operator>>(EStream& s, ISimsCounterTopObject*& p) {
    unsigned int tmp;
    s.ReadU32(&tmp);
    p = (ISimsCounterTopObject*)tmp;
    return s;
}
