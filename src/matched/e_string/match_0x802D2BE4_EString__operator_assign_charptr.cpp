/* EString::operator=(char*) @ 0x802D2BE4 (64 bytes) */
/* Canonical class layout from include/types/EString.h */

class EString {
public:
    char* m_buffer;
    static char m_null;
    void MakeCopy(char* src);
    void Deallocate(char* buf);
    EString& operator=(char* str);
};

char EString::m_null;

EString& EString::operator=(char* str) {
    char* old = m_buffer;
    MakeCopy(str);
    Deallocate(old);
    return *this;
}
