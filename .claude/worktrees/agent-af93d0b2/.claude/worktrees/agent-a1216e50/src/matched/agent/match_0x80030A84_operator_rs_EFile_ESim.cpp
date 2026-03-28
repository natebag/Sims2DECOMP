struct EFile {
    void ReadU32(unsigned int *);
};

struct ESim;

EFile& operator>>(EFile& s, ESim*& p) {
    unsigned int tmp;
    s.ReadU32(&tmp);
    p = (ESim*)tmp;
    return s;
}
