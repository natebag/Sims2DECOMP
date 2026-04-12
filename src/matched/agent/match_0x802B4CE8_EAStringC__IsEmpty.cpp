// 0x802B4CE8 EAStringC::IsEmpty (28b)

extern char EAStringC_sEmptyString[];

struct EAStringC {
    char *m_str;
};

int EAStringC__IsEmpty_9(EAStringC *self) {
    return self->m_str == EAStringC_sEmptyString;
}
