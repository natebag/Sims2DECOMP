// 0x802AEF18 EAStringC::IsEmpty (28b)

extern char EAStringC_sEmptyString[];

struct EAStringC {
    char *m_str;
};

int EAStringC__IsEmpty_7(EAStringC *self) {
    return self->m_str == EAStringC_sEmptyString;
}
