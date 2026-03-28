struct EAStringC {
    EAStringC& operator+=(EAStringC& other);
};

struct AptString {
    char _pad[0x0C];
    EAStringC m_str;

    void cat(EAStringC* s);
};

void AptString::cat(EAStringC* s)
{
    m_str += *s;
}
