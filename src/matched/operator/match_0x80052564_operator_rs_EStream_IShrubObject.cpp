struct EStream {
    void ReadU32(unsigned int *);
};

struct IShrubObject;

EStream& operator>>(EStream& s, IShrubObject*& p) {
    unsigned int tmp;
    s.ReadU32(&tmp);
    p = (IShrubObject*)tmp;
    return s;
}
