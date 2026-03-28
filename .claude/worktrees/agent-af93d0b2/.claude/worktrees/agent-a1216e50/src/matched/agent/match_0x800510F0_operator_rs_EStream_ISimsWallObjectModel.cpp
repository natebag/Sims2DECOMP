struct EStream {
    void ReadU32(unsigned int *);
};

struct ISimsWallObjectModel;

EStream& operator>>(EStream& s, ISimsWallObjectModel*& p) {
    unsigned int tmp;
    s.ReadU32(&tmp);
    p = (ISimsWallObjectModel*)tmp;
    return s;
}
