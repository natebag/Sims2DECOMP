struct EStream {
    void ReadU32(unsigned int *);
};

struct EIPortalPointLight;

EStream& operator>>(EStream& s, EIPortalPointLight*& p) {
    unsigned int tmp;
    s.ReadU32(&tmp);
    p = (EIPortalPointLight*)tmp;
    return s;
}
