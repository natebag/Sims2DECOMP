struct EStream {
    void ReadU32(unsigned int *);
};

struct EIFloor;

EStream& operator>>(EStream& s, EIFloor*& p) {
    unsigned int tmp;
    s.ReadU32(&tmp);
    p = (EIFloor*)tmp;
    return s;
}
