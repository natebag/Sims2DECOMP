/* EString::Deallocate(char*) @ 0x802D2948 (44 bytes) */
/* Canonical class layout from include/types/EString.h */

class EString {
public:
    char* m_buffer;
    static char m_null;
    void Deallocate(char* buf);
    void FreeBuffer(char* buf);
};

char EString::m_null;

void EString::Deallocate(char* buf) {
    if (buf != &m_null) {
        FreeBuffer(buf);
    }
}
