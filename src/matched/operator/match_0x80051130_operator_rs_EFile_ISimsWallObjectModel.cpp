struct EFile {
    void ReadU32(unsigned int *);
};

struct ISimsWallObjectModel;

EFile& operator>>(EFile& s, ISimsWallObjectModel*& p) {
    unsigned int tmp;
    s.ReadU32(&tmp);
    p = (ISimsWallObjectModel*)tmp;
    return s;
}
