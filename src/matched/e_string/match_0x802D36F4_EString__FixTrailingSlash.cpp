/* EString::FixTrailingSlash(void) @ 0x802D36F4 (64 bytes) */
/* Canonical class layout from include/types/EString.h */

class EString {
public:
    char* m_buffer;
    static char m_null;
    EString& operator=(char* str);
    void FixTrailingSlash(void);
};

char EString::m_null;

extern char* EPathUtil_FixTrailingSlash(char* dst, char* src);

void EString::FixTrailingSlash(void) {
    char buf[264];
    char* result = EPathUtil_FixTrailingSlash(buf, m_buffer);
    operator=(result);
}
