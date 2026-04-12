// 0x80287EF4 EAStringC::IsEmpty (28b)

extern char EAStringC_sEmptyString[];

struct EAStringC {
    char *m_str;
};

int EAStringC__IsEmpty_3(EAStringC *self) {
    return self->m_str == EAStringC_sEmptyString;
}
