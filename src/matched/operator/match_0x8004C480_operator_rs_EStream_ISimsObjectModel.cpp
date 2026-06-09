struct EStream {
    void ReadU32(unsigned int *);
};

struct ISimsObjectModel;

EStream& operator>>(EStream& s, ISimsObjectModel*& p) {
    unsigned int tmp;
    s.ReadU32(&tmp);
    p = (ISimsObjectModel*)tmp;
    return s;
}
