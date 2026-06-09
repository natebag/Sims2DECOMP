struct EStream {
    void ReadU32(unsigned int *);
};

struct ISimsMultiTileObjectModel;

EStream& operator>>(EStream& s, ISimsMultiTileObjectModel*& p) {
    unsigned int tmp;
    s.ReadU32(&tmp);
    p = (ISimsMultiTileObjectModel*)tmp;
    return s;
}
