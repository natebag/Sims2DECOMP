struct EFile {
    void ReadU32(unsigned int *);
};

struct ERLevel;

EFile& operator>>(EFile& s, ERLevel*& p) {
    unsigned int tmp;
    s.ReadU32(&tmp);
    p = (ERLevel*)tmp;
    return s;
}
