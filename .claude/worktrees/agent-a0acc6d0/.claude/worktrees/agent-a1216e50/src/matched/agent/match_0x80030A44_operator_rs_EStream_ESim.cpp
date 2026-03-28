struct EStream {
    void ReadU32(unsigned int *);
};

struct ESim;

EStream& operator>>(EStream& s, ESim*& p) {
    unsigned int tmp;
    s.ReadU32(&tmp);
    p = (ESim*)tmp;
    return s;
}
