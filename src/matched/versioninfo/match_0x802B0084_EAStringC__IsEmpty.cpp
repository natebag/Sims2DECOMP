// 0x802B0084 EAStringC::IsEmpty (28b)

extern char EAStringC_sEmptyString[];

struct EAStringC {
    char *m_str;
};

int EAStringC__IsEmpty_8(EAStringC *self) {
    return self->m_str == EAStringC_sEmptyString;
}
