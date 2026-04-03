struct EFile {
    void ReadU32(unsigned int *);
};

struct EIGameInstance;

EFile& operator>>(EFile& f, EIGameInstance*& p) {
    unsigned int tmp;
    f.ReadU32(&tmp);
    p = (EIGameInstance*)tmp;
    return f;
}
