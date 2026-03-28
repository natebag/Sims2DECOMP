struct EAStringC {
    EAStringC& operator=(EAStringC& other);
};

struct AptString {
    char _pad[0x0C];
    EAStringC m_str;

    void cpy(EAStringC* s);
};

void AptString::cpy(EAStringC* s)
{
    m_str = *s;
}
