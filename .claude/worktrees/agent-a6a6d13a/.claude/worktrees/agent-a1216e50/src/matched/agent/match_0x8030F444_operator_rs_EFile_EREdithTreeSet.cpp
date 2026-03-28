struct EFile {
    void ReadU32(unsigned int *);
};

struct EREdithTreeSet;

EFile& operator>>(EFile& s, EREdithTreeSet*& p) {
    unsigned int tmp;
    s.ReadU32(&tmp);
    p = (EREdithTreeSet*)tmp;
    return s;
}
