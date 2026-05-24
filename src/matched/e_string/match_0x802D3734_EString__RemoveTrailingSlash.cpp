/* EString::RemoveTrailingSlash(void) @ 0x802D3734 (64 bytes) */
/* Canonical class layout from include/types/EString.h */

class EString {
public:
    char* m_buffer;
    static char m_null;
    EString& operator=(char* str);
    void RemoveTrailingSlash(void);
};

char EString::m_null;

extern char* EPathUtil_RemoveTrailingSlash(char* dst, char* src);

void EString::RemoveTrailingSlash(void) {
    char buf[264];
    char* result = EPathUtil_RemoveTrailingSlash(buf, m_buffer);
    operator=(result);
}
