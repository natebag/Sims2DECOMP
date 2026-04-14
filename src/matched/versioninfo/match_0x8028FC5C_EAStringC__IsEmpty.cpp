// 0x8028FC5C EAStringC::IsEmpty (28b)

extern char EAStringC_sEmptyString[];

struct EAStringC {
    char *m_str;
};

int EAStringC__IsEmpty_4(EAStringC *self) {
    return self->m_str == EAStringC_sEmptyString;
}
