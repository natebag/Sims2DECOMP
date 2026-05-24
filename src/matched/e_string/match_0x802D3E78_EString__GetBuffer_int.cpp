/* EString::GetBuffer(int) @ 0x802D3E78 (60 bytes) */
/* Canonical class layout from include/types/EString.h */

class EString {
public:
    char* m_buffer;
    static char m_null;
    int Allocate(int size);
    char* GetBuffer(int minLen);
};

char EString::m_null;

char* EString::GetBuffer(int minLen) {
    if (Allocate(minLen) == 0) {
        return 0;
    }
    return m_buffer;
}
