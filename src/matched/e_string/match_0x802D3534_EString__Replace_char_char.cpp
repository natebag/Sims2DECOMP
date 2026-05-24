/* EString::Replace(char, char) @ 0x802D3534 (48 bytes) */
/* Canonical class layout from include/types/EString.h */

class EString {
public:
    char* m_buffer;
    void Replace(char oldChar, char newChar);
};

void EString::Replace(char oldChar, char newChar) {
    unsigned char* p = (unsigned char*)m_buffer;
    unsigned char c = *p;
    if (c == 0) return;
    do {
        if ((char)c == oldChar) {
            *p = newChar;
        }
        c = *++p;
    } while (c != 0);
}
