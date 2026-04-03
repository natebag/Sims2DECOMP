struct EStream {
    void ReadU32(unsigned int *);
};

struct EIGameInstance;

EStream& operator>>(EStream& s, EIGameInstance*& p) {
    unsigned int tmp;
    s.ReadU32(&tmp);
    p = (EIGameInstance*)tmp;
    return s;
}
