struct EStream {
    void ReadU32(unsigned int *);
};

struct ERLevel;

EStream& operator>>(EStream& s, ERLevel*& p) {
    unsigned int tmp;
    s.ReadU32(&tmp);
    p = (ERLevel*)tmp;
    return s;
}
