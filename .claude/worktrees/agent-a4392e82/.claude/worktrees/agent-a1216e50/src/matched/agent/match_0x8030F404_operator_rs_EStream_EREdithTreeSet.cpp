struct EStream {
    void ReadU32(unsigned int *);
};

struct EREdithTreeSet;

EStream& operator>>(EStream& s, EREdithTreeSet*& p) {
    unsigned int tmp;
    s.ReadU32(&tmp);
    p = (EREdithTreeSet*)tmp;
    return s;
}
