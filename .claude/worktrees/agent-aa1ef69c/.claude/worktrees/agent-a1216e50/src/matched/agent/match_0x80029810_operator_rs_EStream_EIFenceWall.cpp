/* operator>>(EStream &, EIFenceWall *&) at 0x80029810 (64B) */

struct EStream {
    void ReadU32(unsigned int *);
};

struct EIFenceWall;

EStream& operator>>(EStream& s, EIFenceWall*& p) {
    unsigned int tmp;
    s.ReadU32(&tmp);
    p = (EIFenceWall*)tmp;
    return s;
}
