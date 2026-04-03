struct EAStringC {
    void* m_ptr;
};

void EAStringC_Append(EAStringC* dst, EAStringC* src);

struct AptString {
    char pad[0x0C];
    EAStringC m_str;

    void cat(EAStringC* src);
};

void AptString::cat(EAStringC* src) {
    EAStringC_Append(&m_str, src);
}
