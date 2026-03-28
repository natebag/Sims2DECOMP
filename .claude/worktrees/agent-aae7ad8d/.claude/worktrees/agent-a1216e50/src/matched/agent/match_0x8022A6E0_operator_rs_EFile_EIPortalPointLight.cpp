struct EFile {
    void ReadU32(unsigned int *);
};

struct EIPortalPointLight;

EFile& operator>>(EFile& s, EIPortalPointLight*& p) {
    unsigned int tmp;
    s.ReadU32(&tmp);
    p = (EIPortalPointLight*)tmp;
    return s;
}
