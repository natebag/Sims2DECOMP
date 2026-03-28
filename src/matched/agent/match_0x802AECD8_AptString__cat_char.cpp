struct EAStringC {
    EAStringC& operator+=(char* s);
};

struct AptString {
    char _pad[0x0C];
    EAStringC m_str;

    void cat(char* s);
};

void AptString::cat(char* s)
{
    m_str += s;
}
