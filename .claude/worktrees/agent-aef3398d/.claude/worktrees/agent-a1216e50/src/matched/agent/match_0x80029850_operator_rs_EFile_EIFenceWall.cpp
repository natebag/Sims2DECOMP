struct EFile {
    void ReadU32(unsigned int *);
};

struct EIFenceWall;

EFile& operator>>(EFile& s, EIFenceWall*& p) {
    unsigned int tmp;
    s.ReadU32(&tmp);
    p = (EIFenceWall*)tmp;
    return s;
}
