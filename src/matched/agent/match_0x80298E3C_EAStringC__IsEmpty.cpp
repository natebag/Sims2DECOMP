// 0x80298E3C EAStringC::IsEmpty (28b)

extern char EAStringC_sEmptyString[];

struct EAStringC {
    char *m_str;
};

int EAStringC__IsEmpty_5(EAStringC *self) {
    return self->m_str == EAStringC_sEmptyString;
}
