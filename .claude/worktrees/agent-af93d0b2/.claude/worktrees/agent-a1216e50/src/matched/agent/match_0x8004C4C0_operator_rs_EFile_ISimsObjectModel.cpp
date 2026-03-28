struct EFile {
    void ReadU32(unsigned int *);
};

struct ISimsObjectModel;

EFile& operator>>(EFile& s, ISimsObjectModel*& p) {
    unsigned int tmp;
    s.ReadU32(&tmp);
    p = (ISimsObjectModel*)tmp;
    return s;
}
