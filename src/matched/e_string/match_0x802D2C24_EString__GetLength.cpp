/* EString::GetLength(void) const @ 0x802D2C24 (36 bytes) */
/* Canonical class layout from include/types/EString.h */

class EString {
public:
    char* m_buffer;
    static char m_null;
    int GetLength(void) const;
};

extern "C" int strlen(const char* s);

int EString::GetLength(void) const {
    return strlen(m_buffer);
}
