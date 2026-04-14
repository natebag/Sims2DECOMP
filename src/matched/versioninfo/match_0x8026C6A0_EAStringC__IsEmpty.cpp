// 0x8026C6A0 EAStringC::IsEmpty (28b)

extern char EAStringC_sEmptyString[];

struct EAStringC {
    char *m_str;
};

int EAStringC__IsEmpty(EAStringC *self) {
    return self->m_str == EAStringC_sEmptyString;
}
