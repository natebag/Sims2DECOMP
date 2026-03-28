struct EStream {
    void ReadU32(unsigned int *);
};

struct EBoundTreeNode;

EStream& operator>>(EStream& s, EBoundTreeNode*& p) {
    unsigned int tmp;
    s.ReadU32(&tmp);
    p = (EBoundTreeNode*)tmp;
    return s;
}
