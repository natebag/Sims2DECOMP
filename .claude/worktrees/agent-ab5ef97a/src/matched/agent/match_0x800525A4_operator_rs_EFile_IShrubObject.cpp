struct EFile {
    void ReadU32(unsigned int *);
};

struct IShrubObject;

EFile& operator>>(EFile& s, IShrubObject*& p) {
    unsigned int tmp;
    s.ReadU32(&tmp);
    p = (IShrubObject*)tmp;
    return s;
}
