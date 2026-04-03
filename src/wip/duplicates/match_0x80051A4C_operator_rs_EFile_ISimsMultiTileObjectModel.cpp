struct EFile {
    void ReadU32(unsigned int *);
};

struct ISimsMultiTileObjectModel;

EFile& operator>>(EFile& s, ISimsMultiTileObjectModel*& p) {
    unsigned int tmp;
    s.ReadU32(&tmp);
    p = (ISimsMultiTileObjectModel*)tmp;
    return s;
}
