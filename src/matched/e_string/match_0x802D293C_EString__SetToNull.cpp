/* EString::SetToNull(void) @ 0x802D293C (12 bytes) */
/* Canonical class layout from include/types/EString.h */

class EString {
public:
    char* m_buffer;
    static char m_null;
    void SetToNull(void);
};

char EString::m_null;

void EString::SetToNull(void) {
    m_buffer = &m_null;
}
