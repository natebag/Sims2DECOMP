struct EFile {
    void ReadU32(unsigned int *);
};

struct EBoundTreeNode;

EFile& operator>>(EFile& s, EBoundTreeNode*& p) {
    unsigned int tmp;
    s.ReadU32(&tmp);
    p = (EBoundTreeNode*)tmp;
    return s;
}
