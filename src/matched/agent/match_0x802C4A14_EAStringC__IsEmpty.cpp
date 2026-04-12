// 0x802C4A14 EAStringC::IsEmpty (28b)

extern char EAStringC_sEmptyString[];

struct EAStringC {
    char *m_str;
};

int EAStringC__IsEmpty_12(EAStringC *self) {
    return self->m_str == EAStringC_sEmptyString;
}
