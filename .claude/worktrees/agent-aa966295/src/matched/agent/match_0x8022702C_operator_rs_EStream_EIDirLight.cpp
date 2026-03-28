struct EStream {
    void ReadU32(unsigned int *);
};

struct EIDirLight;

EStream& operator>>(EStream& s, EIDirLight*& p) {
    unsigned int tmp;
    s.ReadU32(&tmp);
    p = (EIDirLight*)tmp;
    return s;
}
