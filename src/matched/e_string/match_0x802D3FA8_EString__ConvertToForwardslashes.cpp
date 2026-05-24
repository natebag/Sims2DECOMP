/* EString::ConvertToForwardslashes(void) @ 0x802D3FA8 (48 bytes) */
/* Canonical class layout from include/types/EString.h */

class EString {
public:
    char* m_buffer;
    void ConvertToForwardslashes(void);
};

void EString::ConvertToForwardslashes(void) {
    unsigned char* str = (unsigned char*)m_buffer;
    unsigned char c = *str;
    if (c == 0) return;
    do {
        if (c == '\\') {
            *str = '/';
        }
        c = *++str;
    } while (c != 0);
}
