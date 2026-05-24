/* EString::RemoveDriveLetter(void) @ 0x802D3774 (40 bytes) */
/* Canonical class layout from include/types/EString.h */

class EString {
public:
    char* m_buffer;
    static char m_null;
    void RemoveDriveLetter(void);
};

char EString::m_null;

extern void EPathUtil_RemoveDriveLetter(char* dst, char* src);

void EString::RemoveDriveLetter(void) {
    EPathUtil_RemoveDriveLetter(m_buffer, m_buffer);
}
