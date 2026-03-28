struct EAStringC {
    void* m_ptr;
};

void EAStringC_Copy(EAStringC* dst, EAStringC* src);

struct AptString {
    char pad[0x0C];
    EAStringC m_str;

    void cpy(EAStringC* src);
};

void AptString::cpy(EAStringC* src) {
    EAStringC_Copy(&m_str, src);
}
