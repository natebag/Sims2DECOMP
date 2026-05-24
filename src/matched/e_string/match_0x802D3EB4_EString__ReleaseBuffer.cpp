/* EString::ReleaseBuffer(void) @ 0x802D3EB4 (36 bytes) */
/* Canonical class layout from include/types/EString.h */

class EString {
public:
    char* m_buffer;
    static char m_null;
    EString& operator=(char* str);
    void ReleaseBuffer(void);
};

char EString::m_null;

void EString::ReleaseBuffer(void) {
    operator=(m_buffer);
}
