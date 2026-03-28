struct EFile {
    void ReadU32(unsigned int *);
};

struct EIFloor;

EFile& operator>>(EFile& s, EIFloor*& p) {
    unsigned int tmp;
    s.ReadU32(&tmp);
    p = (EIFloor*)tmp;
    return s;
}
