struct EStream {
    void ReadU32(unsigned int *);
};

struct EIWallPart;

EStream& operator>>(EStream& s, EIWallPart*& p) {
    unsigned int tmp;
    s.ReadU32(&tmp);
    p = (EIWallPart*)tmp;
    return s;
}
