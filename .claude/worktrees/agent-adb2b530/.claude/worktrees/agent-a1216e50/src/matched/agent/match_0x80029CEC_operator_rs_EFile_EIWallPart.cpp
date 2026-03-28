struct EFile {
    void ReadU32(unsigned int *);
};

struct EIWallPart;

EFile& operator>>(EFile& s, EIWallPart*& p) {
    unsigned int tmp;
    s.ReadU32(&tmp);
    p = (EIWallPart*)tmp;
    return s;
}
