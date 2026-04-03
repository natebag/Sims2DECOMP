struct EAStringC {
    void* m_ptr;
};

void EAStringC_AppendCStr(EAStringC* dst, char* src);

struct AptString {
    char pad[0x0C];
    EAStringC m_str;

    void cat(char* src);
};

void AptString::cat(char* src) {
    EAStringC_AppendCStr(&m_str, src);
}
